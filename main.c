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
 *  11-27-16: Simplified Manchester transmitting / receiving and greatly improved reliability.
 *  Transmit errors rarely occur. Distance improved significantly.
 *  Created xmitTest.c file.
 *  Added multibyte packets and CRC check. Works great! 
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

#define false 0
#define true !false
#define TRUE true
#define FALSE false
#define NUM_DATA_BITS 8

#define PDownOut 	PORTAbits.RA1
#define TX_OUT 		LATAbits.LATA0
#define PUSHin 		PORTBbits.RB0
#define TRIG_OUT    PORTBbits.RB5

extern void xmitData(unsigned char *ptrData, unsigned char numBytes);
extern void xmitStartSequence(void);
extern void xmitStopSequence(void);
extern unsigned short CRCcalculate(unsigned char *message, unsigned char nBytes);

void init(void);

#define COMMAND_LENGTH 16

void main() {
    unsigned short CRCinteger;
    unsigned char command = 0;
    unsigned char commandBuffer[COMMAND_LENGTH];      
    union {
        unsigned char CRCbyte[2];
        unsigned short CRCinteger;
    } convert;    
    
    init();
    PDownOut = 0;
    TX_OUT = 0;
    TRIG_OUT = 0;
    DelayMs(100);
    Sleep();

    while (1) {  
        commandBuffer[0] = 7;
        commandBuffer[1] = command++;
        commandBuffer[2] = command++;
        commandBuffer[3] = command++;
        commandBuffer[4] = command++;
        commandBuffer[5] = command++;
        commandBuffer[6] = command++;
        commandBuffer[7] = command++;
        
        convert.CRCinteger = CRCcalculate(&commandBuffer[1], 7);
        commandBuffer[8] = convert.CRCbyte[0];
        commandBuffer[9] = convert.CRCbyte[1];
        PDownOut = 1;    
        DelayMs(10);
        TRIG_OUT = 1;
        xmitStartSequence();
        xmitData(commandBuffer, 10);
        xmitStopSequence();
        TRIG_OUT = 0;
        PDownOut = 0;
        do {
            DelayMs(20);
        } while (!PUSHin);
        DelayMs(20);
        while (!PUSHin);
        Sleep();
    }
}

void init(void) {
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
    PR2 = 10; // Was 40 for 10 uS rollover
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
