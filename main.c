/*  LINX Transmit - MPLABX project
 *  For Magic Wand boards
 *  C language written for for 18F2520 on XC8 Compiler
 *
 *  5-24-14 
 *  11-19-16
 *  11-20-16: Works with sleep mode. Sends ">ABCDEF<\r" at 9600 baud on Tx UART pin.
 *  Uses RA0 pin to send start bits.
 *  11-25-16: Got Manchester Coding working on magic wands 
 *              with 18LF2520 running at 16 Mhz with Timer 2 rooling over at 100 uS 
 */

#include <XC.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include "DELAY16.H"
#pragma config IESO = OFF, OSC = HS, FCMEN = OFF, BOREN = OFF, PWRT = ON, WDT = OFF, CCP2MX = PORTC, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON, DEBUG = OFF, STVREN = OFF, XINST = OFF, LVP = OFF, CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF  // For 18F2520

/*
#define START_ONE 200
#define START_TWO 60
#define START_THREE 60
#define BITPERIOD 10
#define TIMEOUT 30
#define NUM_SETTLING_PULSES 3 
#define START_TRANSMIT 1
 */


#define false 0
#define true !false
#define TRUE true
#define FALSE false
#define NUM_DATA_BITS 8

#define DEBOUNCE_TIME 64000		// About 250 ms

#define PDownOut 	PORTAbits.RA1
#define TX_OUT 		LATAbits.LATA0
#define PUSHin 		PORTBbits.RB0
// #define LED         PORTBbits.RB5
#define TRIG_OUT    LATBbits.LATB5

// declare the assembly routine so it can be correctly called
extern unsigned char add(unsigned char a);

void init(void);

#define MAXBUFFER 16

#define XORmask 0xAAAAAAAA

unsigned short getOutData(unsigned short dataOut) {
    unsigned short dataInt, intMask, xorInt;
    unsigned short i, dataMask;

    dataInt = 0x0000;
    dataMask = 0x0001;
    intMask = 0x0003;
    for (i = 0; i < NUM_DATA_BITS; i++) {
        if (dataMask & dataOut) dataInt = dataInt | intMask;
        dataMask = dataMask << 1;
        intMask = intMask << 2;
    }
    xorInt = XORmask ^ dataInt;
    return (xorInt);
}

#define START_ONE 20
#define START_TWO 6  
#define START_THREE 6
#define START_FOUR 9
#define BITPERIOD 1
#define TIMEOUT 3
#define NUM_SETTLING_PULSES 3   
#define START_TRANSMIT 1

void main() {
    unsigned char XMITbuffer[MAXBUFFER] = ">ABCDEF<\r";
    unsigned char testByte = 'A';
    unsigned char ch, i;
    unsigned short Timer2Counter = 0;
    unsigned char pulseCounter = 0;
    unsigned char TXstate = 0;
    unsigned char bitCounter = 0;
    unsigned short dataOut = 0;
    unsigned short command = 0;
    unsigned short dataOutMask = 0, dataOutInt = 0;
    unsigned char  numRepeats = 0;

    volatile unsigned char result;
    result = add(5); // call the assembly routine    

    init();
    PDownOut = 0;
    TX_OUT = 0;
    TRIG_OUT = 0;
    // LED = 0;
    //DelayMs(200);
    //printf("\rTesting new compiler.\r");

    //OSCCONbits.SCS1 = 1; // Use internal RC oscillator in IDLE mode
    Sleep();
    //OSCCONbits.SCS1 = 0; // Use primary oscillator in RUN mode

    while (1) {
        if (!PUSHin && !TXstate) {
            XMITbuffer[1] = testByte++;
            // if (testByte > 'Z') testByte = 'A';
            PDownOut = 1;
            dataOut = command;
            dataOut = dataOut | (command << 8);
            dataOutInt = getOutData(dataOut);
            command++;
            if (command > 0xFF) command = 0;
            TXstate = START_TRANSMIT;
            TRIG_OUT = 1;
        }

        if (TMR2IF) {
            TMR2IF = 0;
            if (Timer2Counter) Timer2Counter--;
            if (!Timer2Counter) {
                if (TXstate) {
                    if (TXstate == 1) {
                        if (TX_OUT) {
                            TX_OUT = 0;
                            pulseCounter++;
                            if (pulseCounter >= NUM_SETTLING_PULSES) {
                                pulseCounter = 0;
                                TXstate++;
                            }
                        } else TX_OUT = 1;
                        //TRIG_OUT = 1;
                        Timer2Counter = BITPERIOD;
                    } else if (TXstate == 2) {
                        TX_OUT = 1;
                        Timer2Counter = START_ONE;
                        bitCounter = 0;
                        dataOutMask = 0x0001;
                        numRepeats = 1;
                        TXstate++;
                    } else if (TXstate == 3) {
                        TX_OUT = 0;
                        Timer2Counter = START_TWO;
                        TXstate++;
                    } else if (TXstate == 4) {
                        TX_OUT = 1;
                        Timer2Counter = START_THREE;
                        TXstate++;
                    } else if (TXstate == 5) {
                        TX_OUT = 0;
                        Timer2Counter = BITPERIOD;
                        TXstate++;
                    } else if (TXstate == 6) {
                        TX_OUT = 1;
                        Timer2Counter = BITPERIOD;
                        TXstate++;
                    } else if (TXstate == 7) {
                        if (bitCounter < (NUM_DATA_BITS * 2)) {
                            if (dataOutInt & dataOutMask) TX_OUT = 1;
                            else TX_OUT = 0;
                            dataOutMask = dataOutMask << 1;
                            Timer2Counter = BITPERIOD;
                        } 
                        else {
                            TX_OUT = 0;
                            TXstate++;
                            Timer2Counter = TIMEOUT * 2;
                        }
                        bitCounter++;
                        if ((bitCounter == (NUM_DATA_BITS * 2)) && numRepeats--){
                            dataOutMask = 0x0001;   
                            bitCounter = 0;                            
                        }
                    } else if (TXstate == 8) {
                        TXstate = 0;
                        TX_OUT = 0;
                        TRIG_OUT = 0;
                        Sleep();
                    } else {
                        TXstate = 0;
                        TX_OUT = 0;
                        TRIG_OUT = 0;
                        Sleep();
                    }
                } // end if TXstate
            } // end if (!Timer2Counter)
        }
    } // end while(1)
} // end main()

void init(void) {
    /*
    OSCCONbits.IDLEN = 1; // Enter IDLE mode with SLEEP instruction
    OSCCONbits.IRCF2 = 0; // Internal Oscillator Frequency = 31 kHz from INTRC directly
    OSCCONbits.IRCF1 = 0;
    OSCCONbits.IRCF0 = 0;
    OSCCONbits.SCS1 = 0; // Use primary oscillator in RUN mode
    OSCCONbits.SCS0 = 0;
    OSCTUNEbits.INTSRC = 0; // 31 kHz device clock derived directly from INTRC internal oscillator
     */
    GIE = 0; // Global interrupt disabled
    TRISA = 0b11111100; // RA0 is Data Out (TX_OUT), RA1 is power down out
    ADCON0 = 0;
    ADCON1 = 0b00001111; // PORT A is all digital

    TRISB = 0b11011111; // RB5 is LED out
    RBPU = 0; // Enable pullups        
    TRISC = 0b11111111;

    TXSTAbits.TXEN = 0; // Disable UART Tx        
    TRISC = 0b11111111; // Set UART Tx pin to input
    TRISA = 0b11111100; // Set RA0 to output

    // Set up the UART         
    TXSTAbits.BRGH = 0; // Low speed baud rate
    SPBRG = 25; // Baudrate = 9600 @ 16 Mhz clock
    TXSTAbits.SYNC = 0; // asynchronous
    RCSTAbits.SPEN = 1; // enable serial port pins
    RCSTAbits.CREN = 1; // enable reception
    RCSTAbits.SREN = 0; // no effect
    TXIE = 0; // disable tx interrupts 
    RCIE = 0; // disable rx interrupts 
    TXSTAbits.TX9 = 0; // 8-bit transmission
    RCSTAbits.RX9 = 0; // 8-bit reception
    TXSTAbits.TXEN = 0; // Disable transmitter until needed
    BAUDCONbits.TXCKP = 0; // Do not invert transmit and receive data
    BAUDCONbits.RXDTP = 0;

    // Set up Timer 2 to roll over every 100 uS:	
    T2CON = 0x00;
    T2CONbits.T2CKPS1 = 0; // 1:4 prescaler  was 1:1 for 10uS rolloever
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.T2OUTPS3 = 0; // 1:1 postscaler
    T2CONbits.T2OUTPS2 = 0;
    T2CONbits.T2OUTPS1 = 0;
    T2CONbits.T2OUTPS0 = 0;
    PR2 = 100; // Was 40 for 10 uS rollover
    TMR2ON = 1; // Timer 2 ON

    // Set up interrupts. 
    INTCON = 0x00; // Clear all interrupts
    INTCONbits.INT0IE = 1; // Enable pushbutton interrupts

    INTCON2 = 0x00;
    INTCON2bits.RBPU = 0; // Enable Port B pullups 
    INTCON2bits.INTEDG0 = 0; // Interrupt on falling edge of RB0,
    // when pushbutton is pushed.
    // This will wake up PIC from sleep mode
    GIE = 1; // Enable global interrupts           
}

static void interrupt isr(void) {
    if (INTCONbits.INT0IF) INTCONbits.INT0IF = 0;
}

void putch(unsigned char TxByte) {
    while (!TXIF); // set when register is empty 
    TXREG = TxByte;
    return;
}

/*
        if (TMR2IF) {
            TMR2IF = 0;
            if (Timer2Counter) Timer2Counter--;
            if (!Timer2Counter) {
                if (TXstate) {
                    if (TXstate == 1) {
                        if (TX_OUT) {
                            TX_OUT = 0;
                            pulseCounter++;
                            if (pulseCounter >= NUM_SETTLING_PULSES) {
                                pulseCounter = 0;
                                TXstate++;
                            }
                        } else TX_OUT = 1;                        
                        Timer2Counter = BITPERIOD;
                    } else if (TXstate == 2) {
                        TX_OUT = 1;                        
                        Timer2Counter = START_ONE;
                        bitCounter = 0;                        
                        TXstate++;
                    } else if (TXstate == 3) {
                        TX_OUT = 0;
                        Timer2Counter = START_TWO;
                        TXstate++;
                    } else if (TXstate == 4) {
                        TX_OUT = 1;
                        Timer2Counter = START_THREE;     
                        TRISA = 0b11111101;     // Tristate RA0
                        TRISC = 0b10111111;     // Set UART Tx pin to output
                        TXSTAbits.TXEN = 1;     // Enable UART Tx                                                     
                        TXstate++;
                    } else if (TXstate == 5) {
                        LED = 1;
                        putch(0);
                        Timer2Counter = 20;
                        TXstate++;                        
                    } else if (TXstate == 6) {
                        i = 0;
                        do {                            
                            ch = XMITbuffer[i++];                            
                            putch(ch);
                            if (ch=='\r') break;
                        } while (i < MAXBUFFER);                        
                        Timer2Counter = 20;
                        TXstate++;                        
                    } else {
                        while (!TXIF);
                        TXSTAbits.TXEN = 0;     // Disable UART Tx        
                        TRISC = 0b11111111;     // Tristate UART Tx pin
                        TRISA = 0b11111100;     // Set RA0 to output                        
                        TXstate = 0;
                        TX_OUT = 0;
                        PDownOut = 0;
                        LED = 0;
                        while(!PUSHin);
                        DelayMs(20);
                        while(!PUSHin);          
                        //OSCCONbits.SCS1 = 1; // Use internal RC oscillator in IDLE mode
                        Sleep();             // Go back to sleep (IDLE MODE) until pushbutton is pushed
                        //OSCCONbits.SCS1 = 0; // Use primary oscillator in RUN mode
                    }
                } // end if (TXstate)
            }  // end if (!Timer2Counter)
        }  // end if (TMR2IF)
 */ 