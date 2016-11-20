
#if _HTC_VER_MAJOR_ >= 9
 #ifndef _HTC_H_
  #warning Device header file included directly. Use #include <htc.h> instead.
 #endif
#elif !defined(_PIC18_H)
 #warning Device header file included directly. Use #include <pic18.h> instead.
#endif

 /* header file for the MICROCHIP PIC18 microcontrollers
	PIC18F2420
	PIC18F2520
	PIC18F4420
	PIC18F4520
 */

#ifndef	__PIC18F4520_H

#define	__PIC18F4520_H

static volatile near unsigned char	TOSU		@ 0xFFF;
static volatile near unsigned char	TOSH		@ 0xFFE;
static volatile near unsigned char	TOSL		@ 0xFFD;
static volatile near unsigned char	STKPTR		@ 0xFFC;
static volatile near unsigned char	PCLATU		@ 0xFFB;
static volatile near unsigned char	PCLATH		@ 0xFFA;
static volatile near unsigned char	PCL		@ 0xFF9;
static volatile far  unsigned char *	TBLPTR		@ 0xFF6;
static volatile near unsigned char	TBLPTRU		@ 0xFF8;
static volatile near unsigned char	TBLPTRH		@ 0xFF7;
static volatile near unsigned char	TBLPTRL		@ 0xFF6;
static volatile near unsigned char	TABLAT		@ 0xFF5;
static volatile near unsigned char	PRODH		@ 0xFF4;
static volatile near unsigned char	PRODL		@ 0xFF3;
static volatile near unsigned char	INTCON		@ 0xFF2;
static          near unsigned char	INTCON2		@ 0xFF1;
static volatile near unsigned char	INTCON3		@ 0xFF0;
static volatile near unsigned char	INDF0		@ 0xFEF;
static volatile near unsigned char	POSTINC0	@ 0xFEE;
static volatile near unsigned char	POSTDEC0	@ 0xFED;
static volatile near unsigned char	PREINC0		@ 0xFEC;
static volatile near unsigned char	PLUSW0		@ 0xFEB;
static volatile near unsigned char	FSR0H		@ 0xFEA;
static volatile near unsigned char	FSR0L		@ 0xFE9;
static volatile near unsigned char	WREG		@ 0xFE8;
static volatile near unsigned char	INDF1		@ 0xFE7;
static volatile near unsigned char	POSTINC1	@ 0xFE6;
static volatile near unsigned char	POSTDEC1	@ 0xFE5;
static volatile near unsigned char	PREINC1		@ 0xFE4;
static volatile near unsigned char	PLUSW1		@ 0xFE3;
static volatile near unsigned char	FSR1H		@ 0xFE2;
static volatile near unsigned char	FSR1L		@ 0xFE1;
static          near unsigned char	BSR		@ 0xFE0;
static volatile near unsigned char	INDF2		@ 0xFDF;
static volatile near unsigned char	POSTINC2	@ 0xFDE;
static volatile near unsigned char	POSTDEC2	@ 0xFDD;
static volatile near unsigned char	PREINC2		@ 0xFDC;
static volatile near unsigned char	PLUSW2		@ 0xFDB;
static volatile near unsigned char	FSR2H		@ 0xFDA;
static volatile near unsigned char	FSR2L		@ 0xFD9;
static volatile near unsigned char	STATUS		@ 0xFD8;
static volatile near unsigned char	TMR0H		@ 0xFD7;
static volatile near unsigned char	TMR0L		@ 0xFD6;
// 16-Bit definition
static volatile near unsigned int	TMR0		@ 0xFD6;
static          near unsigned char	T0CON		@ 0xFD5;
static volatile near unsigned char	OSCCON		@ 0xFD3;
static volatile near unsigned char	HLVDCON		@ 0xFD2;
// alternate definition for bakward compatibility
static volatile near unsigned char	LVDCON		@ 0xFD2;
static volatile near unsigned char	WDTCON		@ 0xFD1;
static volatile near unsigned char	RCON		@ 0xFD0;
static volatile near unsigned char	TMR1H		@ 0xFCF;
static volatile near unsigned char	TMR1L		@ 0xFCE;
// 16-Bit definition
static volatile near unsigned int	TMR1		@ 0xFCE;
static          near unsigned char	T1CON		@ 0xFCD;
static volatile near unsigned char	TMR2		@ 0xFCC;
static          near unsigned char	PR2		@ 0xFCB;
static          near unsigned char	T2CON		@ 0xFCA;
static volatile near unsigned char	SSPBUF		@ 0xFC9;
static          near unsigned char	SSPADD		@ 0xFC8;
static volatile near unsigned char	SSPSTAT		@ 0xFC7;
static volatile near unsigned char	SSPCON1		@ 0xFC6;
static volatile near unsigned char	SSPCON2		@ 0xFC5;
static volatile near unsigned char	ADRESH		@ 0xFC4;
static volatile near unsigned char	ADRESL		@ 0xFC3;
// 16-Bit definition
static volatile near unsigned int	ADRES		@ 0xFC3;
static volatile near unsigned char	ADCON0		@ 0xFC2;
static          near unsigned char	ADCON1		@ 0xFC1;
static          near unsigned char	ADCON2		@ 0xFC0;
static volatile near unsigned char	CCPR1H		@ 0xFBF;
static volatile near unsigned char	CCPR1L		@ 0xFBE;
// 16-Bit definition
static volatile near unsigned int	CCPR1		@ 0xFBE;
static volatile near unsigned char	CCP1CON		@ 0xFBD;
static volatile near unsigned char	CCPR2H		@ 0xFBC;
static volatile near unsigned char	CCPR2L		@ 0xFBB;
// 16-Bit definition
static volatile near unsigned int	CCPR2		@ 0xFBB;
static volatile near unsigned char	CCP2CON		@ 0xFBA;
static volatile near unsigned char	BAUDCON		@ 0xFB8;
#if defined(_18F4420) || defined(_18F4520)
static volatile near unsigned char	PWM1CON		@ 0xFB7;
static volatile near unsigned char	ECCP1AS		@ 0xFB6;
#endif
static volatile near unsigned char	CVRCON		@ 0xFB5;
static volatile near unsigned char	CMCON		@ 0xFB4;
static volatile near unsigned char	TMR3H		@ 0xFB3;
static volatile near unsigned char	TMR3L		@ 0xFB2;
// 16-Bit definition
static volatile near unsigned int	TMR3		@ 0xFB2;
static          near unsigned char	T3CON		@ 0xFB1;
static          near unsigned char	SPBRGH		@ 0xFB0;
static          near unsigned char	SPBRG		@ 0xFAF;
static volatile near unsigned char	RCREG		@ 0xFAE;
static volatile near unsigned char	TXREG		@ 0xFAD;
static volatile near unsigned char	TXSTA		@ 0xFAC;
static volatile near unsigned char	RCSTA		@ 0xFAB;
static          near unsigned char	EEADR		@ 0xFA9;
static volatile near unsigned char	EEDATA		@ 0xFA8;
static volatile near unsigned char	EECON2		@ 0xFA7;
static volatile near unsigned char	EECON1		@ 0xFA6;
static          near unsigned char	IPR2		@ 0xFA2;
static volatile near unsigned char	PIR2		@ 0xFA1;
static          near unsigned char	PIE2		@ 0xFA0;
static          near unsigned char	IPR1		@ 0xF9F;
static volatile near unsigned char	PIR1		@ 0xF9E;
static          near unsigned char	PIE1		@ 0xF9D;
static          near unsigned char	OSCTUNE		@ 0xF9B;
#if defined(_18F4420) || defined(_18F4520)
static volatile near unsigned char	TRISE		@ 0xF96;
static volatile near unsigned char	TRISD		@ 0xF95;
#endif
static volatile near unsigned char	TRISC		@ 0xF94;
static volatile near unsigned char	TRISB		@ 0xF93;
static volatile near unsigned char	TRISA		@ 0xF92;
#if defined(_18F4420) || defined(_18F4520)
static volatile near unsigned char	LATE		@ 0xF8D;
static volatile near unsigned char	LATD		@ 0xF8C;
#endif
static volatile near unsigned char	LATC		@ 0xF8B;
static volatile near unsigned char	LATB		@ 0xF8A;
static volatile near unsigned char	LATA		@ 0xF89;
static volatile near unsigned char	PORTE		@ 0xF84;
#if defined(_18F4420) || defined(_18F4520)
static volatile near unsigned char	PORTD		@ 0xF83;
#endif
static volatile near unsigned char	PORTC		@ 0xF82;
static volatile near unsigned char	PORTB		@ 0xF81;
static volatile near unsigned char	PORTA		@ 0xF80;


/* Definitions for STKPTR register */
static volatile near bit	STKUNF		@ ((unsigned)&STKPTR*8)+6;
static volatile near bit	STKFUL		@ ((unsigned)&STKPTR*8)+7;

/* Definitions for INTCON register */
static volatile near bit	RBIF		@ ((unsigned)&INTCON*8)+0;
static volatile near bit	INT0IF		@ ((unsigned)&INTCON*8)+1;
static volatile near bit	TMR0IF		@ ((unsigned)&INTCON*8)+2;
static          near bit	RBIE		@ ((unsigned)&INTCON*8)+3;
static          near bit	INT0IE		@ ((unsigned)&INTCON*8)+4;
static          near bit	TMR0IE		@ ((unsigned)&INTCON*8)+5;
static          near bit	PEIE		@ ((unsigned)&INTCON*8)+6;
static          near bit	GIE		@ ((unsigned)&INTCON*8)+7;
/* Alternate definitions for INTCON register */
static          near bit	GIEL		@ ((unsigned)&INTCON*8)+6;
static          near bit	GIEH		@ ((unsigned)&INTCON*8)+7;

/* Definitions for INTCON2 register */
static          near bit	RBIP		@ ((unsigned)&INTCON2*8)+0;
static          near bit	TMR0IP		@ ((unsigned)&INTCON2*8)+2;
static          near bit	INTEDG2		@ ((unsigned)&INTCON2*8)+4;
static          near bit	INTEDG1		@ ((unsigned)&INTCON2*8)+5;
static          near bit	INTEDG0		@ ((unsigned)&INTCON2*8)+6;
static          near bit	RBPU		@ ((unsigned)&INTCON2*8)+7;

/* Definitions for INTCON3 register */
static volatile near bit	INT1IF		@ ((unsigned)&INTCON3*8)+0;
static volatile near bit	INT2IF		@ ((unsigned)&INTCON3*8)+1;
static          near bit	INT1IE		@ ((unsigned)&INTCON3*8)+3;
static          near bit	INT2IE		@ ((unsigned)&INTCON3*8)+4;
static          near bit	INT1IP		@ ((unsigned)&INTCON3*8)+6;
static          near bit	INT2IP		@ ((unsigned)&INTCON3*8)+7;

/* Definitions for STATUS register */
static volatile near bit	CARRY		@ ((unsigned)&STATUS*8)+0;
static volatile near bit	DC		@ ((unsigned)&STATUS*8)+1;
static volatile near bit	ZERO		@ ((unsigned)&STATUS*8)+2;
static volatile near bit	OV		@ ((unsigned)&STATUS*8)+3;
static volatile near bit	NEGATIVE	@ ((unsigned)&STATUS*8)+4;

/* Definitions for T0CON register */
static          near bit	T0PS0		@ ((unsigned)&T0CON*8)+0;
static          near bit	T0PS1		@ ((unsigned)&T0CON*8)+1;
static          near bit	T0PS2		@ ((unsigned)&T0CON*8)+2;
static          near bit	PSA		@ ((unsigned)&T0CON*8)+3;
static          near bit	T0SE		@ ((unsigned)&T0CON*8)+4;
static          near bit	T0CS		@ ((unsigned)&T0CON*8)+5;
static          near bit	T08BIT		@ ((unsigned)&T0CON*8)+6;
static          near bit	TMR0ON		@ ((unsigned)&T0CON*8)+7;

/* Definitions for OSCCON register */
static          near bit	SCS0		@ ((unsigned)&OSCCON*8)+0;
static          near bit	SCS1		@ ((unsigned)&OSCCON*8)+1;
static volatile near bit	IOFS		@ ((unsigned)&OSCCON*8)+2;
static volatile near bit	OSTS		@ ((unsigned)&OSCCON*8)+3;
static          near bit	IRCF0		@ ((unsigned)&OSCCON*8)+4;
static          near bit	IRCF1		@ ((unsigned)&OSCCON*8)+5;
static          near bit	IRCF2		@ ((unsigned)&OSCCON*8)+6;
static          near bit	IDLEN		@ ((unsigned)&OSCCON*8)+7;

/* Definitions for HLVDCON register */
static          near bit	HLVDL0		@ ((unsigned)&HLVDCON*8)+0;
static          near bit	HLVDL1		@ ((unsigned)&HLVDCON*8)+1;
static          near bit	HLVDL2		@ ((unsigned)&HLVDCON*8)+2;
static          near bit	HLVDL3		@ ((unsigned)&HLVDCON*8)+3;
static          near bit	HLVDEN		@ ((unsigned)&HLVDCON*8)+4;
static volatile near bit	IRVST		@ ((unsigned)&HLVDCON*8)+5;
static          near bit	VDIRMAG		@ ((unsigned)&HLVDCON*8)+7;

static          near bit	LVDL0		@ ((unsigned)&HLVDCON*8)+0; //compatibility
static          near bit	LVDL1		@ ((unsigned)&HLVDCON*8)+1; //compatibility
static          near bit	LVDL2		@ ((unsigned)&HLVDCON*8)+2; //compatibility
static          near bit	LVDL3		@ ((unsigned)&HLVDCON*8)+3; //compatibility
static          near bit	LVDEN		@ ((unsigned)&HLVDCON*8)+4; //compatibility

/* Definitions for WDTCON register */
static          near bit	SWDTEN		@ ((unsigned)&WDTCON*8)+0;

/* Definitions for RCON register */
static volatile near bit	BOR		@ ((unsigned)&RCON*8)+0;
static volatile near bit	POR		@ ((unsigned)&RCON*8)+1;
static volatile near bit	PD		@ ((unsigned)&RCON*8)+2;
static volatile near bit	TO		@ ((unsigned)&RCON*8)+3;
static volatile near bit	RI		@ ((unsigned)&RCON*8)+4;
static          near bit	SBOREN		@ ((unsigned)&RCON*8)+6;
static          near bit	IPEN		@ ((unsigned)&RCON*8)+7;

/* Definitions for T1CON register */
static          near bit	TMR1ON		@ ((unsigned)&T1CON*8)+0;
static          near bit	TMR1CS		@ ((unsigned)&T1CON*8)+1;
static          near bit	T1SYNC		@ ((unsigned)&T1CON*8)+2;
static          near bit	T1OSCEN		@ ((unsigned)&T1CON*8)+3;
static          near bit	T1CKPS0		@ ((unsigned)&T1CON*8)+4;
static          near bit	T1CKPS1		@ ((unsigned)&T1CON*8)+5;
static          near bit	T1RUN		@ ((unsigned)&T1CON*8)+6;
static          near bit	T1RD16		@ ((unsigned)&T1CON*8)+7;

/* Definitions for T2CON register */
static          near bit	T2CKPS0		@ ((unsigned)&T2CON*8)+0;
static          near bit	T2CKPS1		@ ((unsigned)&T2CON*8)+1;
static          near bit	TMR2ON		@ ((unsigned)&T2CON*8)+2;
static          near bit	T2OUTPS0	@ ((unsigned)&T2CON*8)+3;
static          near bit	T2OUTPS1	@ ((unsigned)&T2CON*8)+4;
static          near bit	T2OUTPS2	@ ((unsigned)&T2CON*8)+5;
static          near bit	T2OUTPS3	@ ((unsigned)&T2CON*8)+6;

/* Definitions for SSPSTAT register */
static volatile near bit	BF		@ ((unsigned)&SSPSTAT*8)+0;
static volatile near bit	UA		@ ((unsigned)&SSPSTAT*8)+1;
static volatile near bit	RW		@ ((unsigned)&SSPSTAT*8)+2;
static volatile near bit	START		@ ((unsigned)&SSPSTAT*8)+3;
static volatile near bit	STOP		@ ((unsigned)&SSPSTAT*8)+4;
static volatile near bit	DA		@ ((unsigned)&SSPSTAT*8)+5;
static          near bit	CKE		@ ((unsigned)&SSPSTAT*8)+6;
static          near bit	SMP		@ ((unsigned)&SSPSTAT*8)+7;

/* Definitions for SSPCON1 register */
static          near bit	SSPM0		@ ((unsigned)&SSPCON1*8)+0;
static          near bit	SSPM1		@ ((unsigned)&SSPCON1*8)+1;
static          near bit	SSPM2		@ ((unsigned)&SSPCON1*8)+2;
static          near bit	SSPM3		@ ((unsigned)&SSPCON1*8)+3;
static          near bit	CKP		@ ((unsigned)&SSPCON1*8)+4;
static          near bit	SSPEN		@ ((unsigned)&SSPCON1*8)+5;
static volatile near bit	SSPOV		@ ((unsigned)&SSPCON1*8)+6;
static volatile near bit	WCOL		@ ((unsigned)&SSPCON1*8)+7;

/* Definitions for SSPCON2 register */
static          near bit	SEN		@ ((unsigned)&SSPCON2*8)+0;
static volatile near bit	RSEN		@ ((unsigned)&SSPCON2*8)+1;
static volatile near bit	PEN		@ ((unsigned)&SSPCON2*8)+2;
static volatile near bit	RCEN		@ ((unsigned)&SSPCON2*8)+3;
static volatile near bit	ACKEN		@ ((unsigned)&SSPCON2*8)+4;
static volatile near bit	ACKDT		@ ((unsigned)&SSPCON2*8)+5;
static volatile near bit	ACKSTAT		@ ((unsigned)&SSPCON2*8)+6;
static          near bit	GCEN		@ ((unsigned)&SSPCON2*8)+7;

/* Definitions for ADCON0 register */
static          near bit	ADON		@ ((unsigned)&ADCON0*8)+0;
static volatile near bit	GODONE		@ ((unsigned)&ADCON0*8)+1;
static          near bit	CHS0		@ ((unsigned)&ADCON0*8)+2;
static          near bit	CHS1		@ ((unsigned)&ADCON0*8)+3;
static          near bit	CHS2		@ ((unsigned)&ADCON0*8)+4;
static          near bit	CHS3		@ ((unsigned)&ADCON0*8)+5;

/* Definitions for ADCON1 register */
static          near bit	PCFG0		@ ((unsigned)&ADCON1*8)+0;
static          near bit	PCFG1		@ ((unsigned)&ADCON1*8)+1;
static          near bit	PCFG2		@ ((unsigned)&ADCON1*8)+2;
static          near bit	PCFG3		@ ((unsigned)&ADCON1*8)+3;
static          near bit	VCFG0		@ ((unsigned)&ADCON1*8)+4;
static          near bit	VCFG1		@ ((unsigned)&ADCON1*8)+5;

/* Definitions for ADCON2 register */
static          near bit	ADCS0		@ ((unsigned)&ADCON2*8)+0;
static          near bit	ADCS1		@ ((unsigned)&ADCON2*8)+1;
static          near bit	ADCS2		@ ((unsigned)&ADCON2*8)+2;
static          near bit	ACQT0		@ ((unsigned)&ADCON2*8)+3;
static          near bit	ACQT1		@ ((unsigned)&ADCON2*8)+4;
static          near bit	ACQT2		@ ((unsigned)&ADCON2*8)+5;
static          near bit	ADFM		@ ((unsigned)&ADCON2*8)+7;

/* Definitions for CCP1CON register */
static          near bit	CCP1M0		@ ((unsigned)&CCP1CON*8)+0;
static          near bit	CCP1M1		@ ((unsigned)&CCP1CON*8)+1;
static          near bit	CCP1M2		@ ((unsigned)&CCP1CON*8)+2;
static          near bit	CCP1M3		@ ((unsigned)&CCP1CON*8)+3;
static          near bit	DC1B0		@ ((unsigned)&CCP1CON*8)+4;
static          near bit	DC1B1		@ ((unsigned)&CCP1CON*8)+5;
#if defined(_18F4420) || defined(_18F4520)
static          near bit	P1M0		@ ((unsigned)&CCP1CON*8)+6;
static          near bit	P1M1		@ ((unsigned)&CCP1CON*8)+7;
#endif

/* Definitions for CCP2CON register */
static          near bit	CCP2M0		@ ((unsigned)&CCP2CON*8)+0;
static          near bit	CCP2M1		@ ((unsigned)&CCP2CON*8)+1;
static          near bit	CCP2M2		@ ((unsigned)&CCP2CON*8)+2;
static          near bit	CCP2M3		@ ((unsigned)&CCP2CON*8)+3;
static          near bit	DC2B0		@ ((unsigned)&CCP2CON*8)+4;
static          near bit	DC2B1		@ ((unsigned)&CCP2CON*8)+5;

/* Definitions for BAUDCON register */
static volatile near bit	ABDEN		@ ((unsigned)&BAUDCON*8)+0;
static volatile near bit	WUE		@ ((unsigned)&BAUDCON*8)+1;
static          near bit	BRG16		@ ((unsigned)&BAUDCON*8)+3;
static volatile near bit	SCKP		@ ((unsigned)&BAUDCON*8)+4;
static volatile near bit	RCIDL		@ ((unsigned)&BAUDCON*8)+6;
static volatile near bit	ABDOVF		@ ((unsigned)&BAUDCON*8)+7;

#if defined(_18F4420) || defined(_18F4520)
/* Definitions for PWM1CON register */
static volatile near bit	PDC0		@ ((unsigned)&PWM1CON*8)+0;
static volatile near bit	PDC1		@ ((unsigned)&PWM1CON*8)+1;
static volatile near bit	PDC2		@ ((unsigned)&PWM1CON*8)+2;
static volatile near bit	PDC3		@ ((unsigned)&PWM1CON*8)+3;
static volatile near bit	PDC4		@ ((unsigned)&PWM1CON*8)+4;
static volatile near bit	PDC5		@ ((unsigned)&PWM1CON*8)+5;
static volatile near bit	PDC6		@ ((unsigned)&PWM1CON*8)+6;
static volatile near bit	PRSEN		@ ((unsigned)&PWM1CON*8)+7;

/* Definitions for ECCP1AS register */
static          near bit	PSSBD0		@ ((unsigned)&ECCP1AS*8)+0;
static          near bit	PSSBD1		@ ((unsigned)&ECCP1AS*8)+1;
static          near bit	PSSAC0		@ ((unsigned)&ECCP1AS*8)+2;
static          near bit	PSSAC1		@ ((unsigned)&ECCP1AS*8)+3;
static          near bit	ECCPAS0		@ ((unsigned)&ECCP1AS*8)+4;
static          near bit	ECCPAS1		@ ((unsigned)&ECCP1AS*8)+5;
static          near bit	ECCPAS2		@ ((unsigned)&ECCP1AS*8)+6;
static volatile near bit	ECCPASE		@ ((unsigned)&ECCP1AS*8)+7;
#endif

/* Definitions for CVRCON register */
static          near bit	CVR0		@ ((unsigned)&CVRCON*8)+0;
static          near bit	CVR1		@ ((unsigned)&CVRCON*8)+1;
static          near bit	CVR2		@ ((unsigned)&CVRCON*8)+2;
static          near bit	CVR3		@ ((unsigned)&CVRCON*8)+3;
static          near bit	CVRSS		@ ((unsigned)&CVRCON*8)+4;
static          near bit	CVRR		@ ((unsigned)&CVRCON*8)+5;
static          near bit	CVROE		@ ((unsigned)&CVRCON*8)+6;
static          near bit	CVREN		@ ((unsigned)&CVRCON*8)+7;

/* Definitions for CMCON register */
static          near bit	CM0		@ ((unsigned)&CMCON*8)+0;
static          near bit	CM1		@ ((unsigned)&CMCON*8)+1;
static          near bit	CM2		@ ((unsigned)&CMCON*8)+2;
static          near bit	CIS		@ ((unsigned)&CMCON*8)+3;
static          near bit	C1INV		@ ((unsigned)&CMCON*8)+4;
static          near bit	C2INV		@ ((unsigned)&CMCON*8)+5;
static volatile near bit	C1OUT		@ ((unsigned)&CMCON*8)+6;
static volatile near bit	C2OUT		@ ((unsigned)&CMCON*8)+7;

/* Definitions for T3CON register */
static          near bit	TMR3ON		@ ((unsigned)&T3CON*8)+0;
static          near bit	TMR3CS		@ ((unsigned)&T3CON*8)+1;
static          near bit	T3SYNC		@ ((unsigned)&T3CON*8)+2;
static          near bit	T3CCP1		@ ((unsigned)&T3CON*8)+3;
static          near bit	T3CKPS0		@ ((unsigned)&T3CON*8)+4;
static          near bit	T3CKPS1		@ ((unsigned)&T3CON*8)+5;
static          near bit	T3CCP2		@ ((unsigned)&T3CON*8)+6;
static          near bit	T3RD16		@ ((unsigned)&T3CON*8)+7;

/* Definitions for TXSTA register */
static volatile near bit	TX9D		@ ((unsigned)&TXSTA*8)+0;
static volatile near bit	TRMT		@ ((unsigned)&TXSTA*8)+1;
static          near bit	BRGH		@ ((unsigned)&TXSTA*8)+2;
static          near bit	SENDB		@ ((unsigned)&TXSTA*8)+3;
static          near bit	SYNC		@ ((unsigned)&TXSTA*8)+4;
static          near bit	TXEN		@ ((unsigned)&TXSTA*8)+5;
static          near bit	TX9		@ ((unsigned)&TXSTA*8)+6;
static          near bit	CSRC		@ ((unsigned)&TXSTA*8)+7;

/* Definitions for RCSTA register */
static volatile near bit	RX9D		@ ((unsigned)&RCSTA*8)+0;
static volatile near bit	OERR		@ ((unsigned)&RCSTA*8)+1;
static volatile near bit	FERR		@ ((unsigned)&RCSTA*8)+2;
static          near bit	ADDEN		@ ((unsigned)&RCSTA*8)+3;
static          near bit	CREN		@ ((unsigned)&RCSTA*8)+4;
static          near bit	SREN		@ ((unsigned)&RCSTA*8)+5;
static          near bit	RX9		@ ((unsigned)&RCSTA*8)+6;
static          near bit	SPEN		@ ((unsigned)&RCSTA*8)+7;

/* Definitions for EECON1 register */
static volatile near bit	RD		@ ((unsigned)&EECON1*8)+0;
static volatile near bit	WR		@ ((unsigned)&EECON1*8)+1;
static          near bit	WREN		@ ((unsigned)&EECON1*8)+2;
static volatile near bit	WRERR		@ ((unsigned)&EECON1*8)+3;
static volatile near bit	FREE		@ ((unsigned)&EECON1*8)+4;
static          near bit	CFGS		@ ((unsigned)&EECON1*8)+6;
static          near bit	EEPGD		@ ((unsigned)&EECON1*8)+7;

/* Definitions for IPR2 register */
static          near bit	CCP2IP		@ ((unsigned)&IPR2*8)+0;
static          near bit	TMR3IP		@ ((unsigned)&IPR2*8)+1;
static          near bit	HLVDIP		@ ((unsigned)&IPR2*8)+2;
static          near bit	BCLIP		@ ((unsigned)&IPR2*8)+3;
static          near bit	EEIP		@ ((unsigned)&IPR2*8)+4;
static          near bit	CMIP		@ ((unsigned)&IPR2*8)+6;
static          near bit	OSCFIP		@ ((unsigned)&IPR2*8)+7;

static          near bit	LVDIP		@ ((unsigned)&IPR2*8)+2; //compatibility

/* Definitions for PIR2 register */
static volatile near bit	CCP2IF		@ ((unsigned)&PIR2*8)+0;
static volatile near bit	TMR3IF		@ ((unsigned)&PIR2*8)+1;
static volatile near bit	HLVDIF		@ ((unsigned)&PIR2*8)+2;
static volatile near bit	BCLIF		@ ((unsigned)&PIR2*8)+3;
static volatile near bit	EEIF		@ ((unsigned)&PIR2*8)+4;
static volatile near bit	CMIF		@ ((unsigned)&PIR2*8)+6;
static volatile near bit	OSCFIF		@ ((unsigned)&PIR2*8)+7;

static volatile near bit	LVDIF		@ ((unsigned)&PIR2*8)+2; //compatibility

/* Definitions for PIE2 register */
static          near bit	CCP2IE		@ ((unsigned)&PIE2*8)+0;
static          near bit	TMR3IE		@ ((unsigned)&PIE2*8)+1;
static          near bit	HLVDIE		@ ((unsigned)&PIE2*8)+2;
static          near bit	BCLIE		@ ((unsigned)&PIE2*8)+3;
static          near bit	EEIE		@ ((unsigned)&PIE2*8)+4;
static          near bit	CMIE		@ ((unsigned)&PIE2*8)+6;
static          near bit	OSCFIE		@ ((unsigned)&PIE2*8)+7;

static          near bit	LVDIE		@ ((unsigned)&PIE2*8)+2; //compatibility

/* Definitions for IPR1 register */
static          near bit	TMR1IP		@ ((unsigned)&IPR1*8)+0;
static          near bit	TMR2IP		@ ((unsigned)&IPR1*8)+1;
static          near bit	CCP1IP		@ ((unsigned)&IPR1*8)+2;
static          near bit	SSPIP		@ ((unsigned)&IPR1*8)+3;
static          near bit	TXIP		@ ((unsigned)&IPR1*8)+4;
static          near bit	RCIP		@ ((unsigned)&IPR1*8)+5;
static          near bit	ADIP		@ ((unsigned)&IPR1*8)+6;
#if defined(_18F4420) || defined(_18F4520)
static          near bit	PSPIP		@ ((unsigned)&IPR1*8)+7;
#endif

/* Definitions for PIR1 register */
static volatile near bit	TMR1IF		@ ((unsigned)&PIR1*8)+0;
static volatile near bit	TMR2IF		@ ((unsigned)&PIR1*8)+1;
static volatile near bit	CCP1IF		@ ((unsigned)&PIR1*8)+2;
static volatile near bit	SSPIF		@ ((unsigned)&PIR1*8)+3;
static volatile near bit	TXIF		@ ((unsigned)&PIR1*8)+4;
static volatile near bit	RCIF		@ ((unsigned)&PIR1*8)+5;
static volatile near bit	ADIF		@ ((unsigned)&PIR1*8)+6;
#if defined(_18F4420) || defined(_18F4520)
static volatile near bit	PSPIF		@ ((unsigned)&PIR1*8)+7;
#endif

/* Definitions for PIE1 register */
static          near bit	TMR1IE		@ ((unsigned)&PIE1*8)+0;
static          near bit	TMR2IE		@ ((unsigned)&PIE1*8)+1;
static          near bit	CCP1IE		@ ((unsigned)&PIE1*8)+2;
static          near bit	SSPIE		@ ((unsigned)&PIE1*8)+3;
static          near bit	TXIE		@ ((unsigned)&PIE1*8)+4;
static          near bit	RCIE		@ ((unsigned)&PIE1*8)+5;
static          near bit	ADIE		@ ((unsigned)&PIE1*8)+6;
#if defined(_18F4420) || defined(_18F4520)
static          near bit	PSPIE		@ ((unsigned)&PIE1*8)+7;
#endif

/* Definitions for OSCTUNE register */
static          near bit	TUN0		@ ((unsigned)&OSCTUNE*8)+0;
static          near bit	TUN1		@ ((unsigned)&OSCTUNE*8)+1;
static          near bit	TUN2		@ ((unsigned)&OSCTUNE*8)+2;
static          near bit	TUN3		@ ((unsigned)&OSCTUNE*8)+3;
static          near bit	TUN4		@ ((unsigned)&OSCTUNE*8)+4;
#if defined(_18F4420) || defined(_18F4520)
static          near bit	PLLEN		@ ((unsigned)&OSCTUNE*8)+6;
#endif
static          near bit	INTSRC		@ ((unsigned)&OSCTUNE*8)+7;

#if defined(_18F4420) || defined(_18F4520)
/* Definitions for TRISE register */
static volatile near bit	TRISE0		@ ((unsigned)&TRISE*8)+0;
static volatile near bit	TRISE1		@ ((unsigned)&TRISE*8)+1;
static volatile near bit	TRISE2		@ ((unsigned)&TRISE*8)+2;
static          near bit	PSPMODE		@ ((unsigned)&TRISE*8)+4;
static volatile near bit	IBOV		@ ((unsigned)&TRISE*8)+5;
static volatile near bit	OBF		@ ((unsigned)&TRISE*8)+6;
static volatile near bit	IBF		@ ((unsigned)&TRISE*8)+7;

/* Definitions for TRISD register */
static volatile near bit	TRISD0		@ ((unsigned)&TRISD*8)+0;
static volatile near bit	TRISD1		@ ((unsigned)&TRISD*8)+1;
static volatile near bit	TRISD2		@ ((unsigned)&TRISD*8)+2;
static volatile near bit	TRISD3		@ ((unsigned)&TRISD*8)+3;
static volatile near bit	TRISD4		@ ((unsigned)&TRISD*8)+4;
static volatile near bit	TRISD5		@ ((unsigned)&TRISD*8)+5;
static volatile near bit	TRISD6		@ ((unsigned)&TRISD*8)+6;
static volatile near bit	TRISD7		@ ((unsigned)&TRISD*8)+7;
#endif

/* Definitions for TRISC register */
static volatile near bit	TRISC0		@ ((unsigned)&TRISC*8)+0;
static volatile near bit	TRISC1		@ ((unsigned)&TRISC*8)+1;
static volatile near bit	TRISC2		@ ((unsigned)&TRISC*8)+2;
static volatile near bit	TRISC3		@ ((unsigned)&TRISC*8)+3;
static volatile near bit	TRISC4		@ ((unsigned)&TRISC*8)+4;
static volatile near bit	TRISC5		@ ((unsigned)&TRISC*8)+5;
static volatile near bit	TRISC6		@ ((unsigned)&TRISC*8)+6;
static volatile near bit	TRISC7		@ ((unsigned)&TRISC*8)+7;

/* Definitions for TRISB register */
static volatile near bit	TRISB0		@ ((unsigned)&TRISB*8)+0;
static volatile near bit	TRISB1		@ ((unsigned)&TRISB*8)+1;
static volatile near bit	TRISB2		@ ((unsigned)&TRISB*8)+2;
static volatile near bit	TRISB3		@ ((unsigned)&TRISB*8)+3;
static volatile near bit	TRISB4		@ ((unsigned)&TRISB*8)+4;
static volatile near bit	TRISB5		@ ((unsigned)&TRISB*8)+5;
static volatile near bit	TRISB6		@ ((unsigned)&TRISB*8)+6;
static volatile near bit	TRISB7		@ ((unsigned)&TRISB*8)+7;

/* Definitions for TRISA register */
static volatile near bit	TRISA0		@ ((unsigned)&TRISA*8)+0;
static volatile near bit	TRISA1		@ ((unsigned)&TRISA*8)+1;
static volatile near bit	TRISA2		@ ((unsigned)&TRISA*8)+2;
static volatile near bit	TRISA3		@ ((unsigned)&TRISA*8)+3;
static volatile near bit	TRISA4		@ ((unsigned)&TRISA*8)+4;
static volatile near bit	TRISA5		@ ((unsigned)&TRISA*8)+5;
static volatile near bit	TRISA6		@ ((unsigned)&TRISA*8)+6;
static volatile near bit	TRISA7		@ ((unsigned)&TRISA*8)+7;

#if defined(_18F4420) || defined(_18F4520)
/* Definitions for LATE register */
static volatile near bit	LATE0		@ ((unsigned)&LATE*8)+0;
static volatile near bit	LATE1		@ ((unsigned)&LATE*8)+1;
static volatile near bit	LATE2		@ ((unsigned)&LATE*8)+2;

/* Definitions for LATD register */
static volatile near bit	LATD0		@ ((unsigned)&LATD*8)+0;
static volatile near bit	LATD1		@ ((unsigned)&LATD*8)+1;
static volatile near bit	LATD2		@ ((unsigned)&LATD*8)+2;
static volatile near bit	LATD3		@ ((unsigned)&LATD*8)+3;
static volatile near bit	LATD4		@ ((unsigned)&LATD*8)+4;
static volatile near bit	LATD5		@ ((unsigned)&LATD*8)+5;
static volatile near bit	LATD6		@ ((unsigned)&LATD*8)+6;
static volatile near bit	LATD7		@ ((unsigned)&LATD*8)+7;
#endif

/* Definitions for LATC register */
static volatile near bit	LATC0		@ ((unsigned)&LATC*8)+0;
static volatile near bit	LATC1		@ ((unsigned)&LATC*8)+1;
static volatile near bit	LATC2		@ ((unsigned)&LATC*8)+2;
static volatile near bit	LATC3		@ ((unsigned)&LATC*8)+3;
static volatile near bit	LATC4		@ ((unsigned)&LATC*8)+4;
static volatile near bit	LATC5		@ ((unsigned)&LATC*8)+5;
static volatile near bit	LATC6		@ ((unsigned)&LATC*8)+6;
static volatile near bit	LATC7		@ ((unsigned)&LATC*8)+7;

/* Definitions for LATB register */
static volatile near bit	LATB0		@ ((unsigned)&LATB*8)+0;
static volatile near bit	LATB1		@ ((unsigned)&LATB*8)+1;
static volatile near bit	LATB2		@ ((unsigned)&LATB*8)+2;
static volatile near bit	LATB3		@ ((unsigned)&LATB*8)+3;
static volatile near bit	LATB4		@ ((unsigned)&LATB*8)+4;
static volatile near bit	LATB5		@ ((unsigned)&LATB*8)+5;
static volatile near bit	LATB6		@ ((unsigned)&LATB*8)+6;
static volatile near bit	LATB7		@ ((unsigned)&LATB*8)+7;

/* Definitions for LATA register */
static volatile near bit	LATA0		@ ((unsigned)&LATA*8)+0;
static volatile near bit	LATA1		@ ((unsigned)&LATA*8)+1;
static volatile near bit	LATA2		@ ((unsigned)&LATA*8)+2;
static volatile near bit	LATA3		@ ((unsigned)&LATA*8)+3;
static volatile near bit	LATA4		@ ((unsigned)&LATA*8)+4;
static volatile near bit	LATA5		@ ((unsigned)&LATA*8)+5;
static volatile near bit	LATA6		@ ((unsigned)&LATA*8)+6;
static volatile near bit	LATA7		@ ((unsigned)&LATA*8)+7;

#if defined(_18F4420) || defined(_18F4520)
/* Definitions for PORTE register */
static volatile near bit	RE0		@ ((unsigned)&PORTE*8)+0;
static volatile near bit	RE1		@ ((unsigned)&PORTE*8)+1;
static volatile near bit	RE2		@ ((unsigned)&PORTE*8)+2;
#endif
static volatile near bit	RE3		@ ((unsigned)&PORTE*8)+3;

#if defined(_18F4420) || defined(_18F4520)
/* Definitions for PORTD register */
static volatile near bit	RD0		@ ((unsigned)&PORTD*8)+0;
static volatile near bit	RD1		@ ((unsigned)&PORTD*8)+1;
static volatile near bit	RD2		@ ((unsigned)&PORTD*8)+2;
static volatile near bit	RD3		@ ((unsigned)&PORTD*8)+3;
static volatile near bit	RD4		@ ((unsigned)&PORTD*8)+4;
static volatile near bit	RD5		@ ((unsigned)&PORTD*8)+5;
static volatile near bit	RD6		@ ((unsigned)&PORTD*8)+6;
static volatile near bit	RD7		@ ((unsigned)&PORTD*8)+7;
#endif

/* Definitions for PORTC register */
static volatile near bit	RC0		@ ((unsigned)&PORTC*8)+0;
static volatile near bit	RC1		@ ((unsigned)&PORTC*8)+1;
static volatile near bit	RC2		@ ((unsigned)&PORTC*8)+2;
static volatile near bit	RC3		@ ((unsigned)&PORTC*8)+3;
static volatile near bit	RC4		@ ((unsigned)&PORTC*8)+4;
static volatile near bit	RC5		@ ((unsigned)&PORTC*8)+5;
static volatile near bit	RC6		@ ((unsigned)&PORTC*8)+6;
static volatile near bit	RC7		@ ((unsigned)&PORTC*8)+7;

/* Definitions for PORTB register */
static volatile near bit	RB0		@ ((unsigned)&PORTB*8)+0;
static volatile near bit	RB1		@ ((unsigned)&PORTB*8)+1;
static volatile near bit	RB2		@ ((unsigned)&PORTB*8)+2;
static volatile near bit	RB3		@ ((unsigned)&PORTB*8)+3;
static volatile near bit	RB4		@ ((unsigned)&PORTB*8)+4;
static volatile near bit	RB5		@ ((unsigned)&PORTB*8)+5;
static volatile near bit	RB6		@ ((unsigned)&PORTB*8)+6;
static volatile near bit	RB7		@ ((unsigned)&PORTB*8)+7;

/* Definitions for PORTA register */
static volatile near bit	RA0		@ ((unsigned)&PORTA*8)+0;
static volatile near bit	RA1		@ ((unsigned)&PORTA*8)+1;
static volatile near bit	RA2		@ ((unsigned)&PORTA*8)+2;
static volatile near bit	RA3		@ ((unsigned)&PORTA*8)+3;
static volatile near bit	RA4		@ ((unsigned)&PORTA*8)+4;
static volatile near bit	RA5		@ ((unsigned)&PORTA*8)+5;
static volatile near bit	RA6		@ ((unsigned)&PORTA*8)+6;
static volatile near bit	RA7		@ ((unsigned)&PORTA*8)+7;


#if defined(_18F2420) || defined(_18F4420)
#define ROMSIZE 16384
#else
#define ROMSIZE 32768
#endif

#define EEPROM_SIZE 256

// Configuration Bit Values
// config word 1
// Oscillator
 #define EXTCLKO	0xFFFF 	// 11XX EXT RC-CLKOUT on RA6 
 #define INTCLKO	0xF9FF 	// INT RC-CLKOUT on RA6,Port on RA7 
 #define INTIO		0xF8FF 	// INT RC-Port on RA6,Port on RA7 
 #define EXTIO		0xF7FF 	// EXT RC-Port on RA6 
 #define HSPLL		0xF6FF 	// HS-PLL enabled freq=4xFosc1 
 #define ECIO		0xF5FF 	// EC-Port on RA6 
 #define ECCLKO		0xF4FF 	// EC-CLKOUT on RA6 
 #define HS		0xF2FF 	// HS Oscillator 
 #define XT		0xF1FF 	// XT Oscillator 
 #define LP		0xF0FF 	// LP Oscillator 
// Fail-Safe Clock Monitor Enable
 #define FCMDIS		0xBFFF 	// Disabled 
 #define FCMEN		0xFFFF 	// Enabled 
// Internal External Switch Over Mode
 #define IESODIS	0x7FFF 	// Disabled 
 #define IESOEN		0xFFFF 	// Enabled 

// config word 2
// Power Up Timer
 #define PWRTDIS	0xFFFF 	// Disabled 
 #define PWRTEN		0xFFFE 	// Enabled 
// Brown Out Detect
 #define BOREN		0xFFFF 	// Enabled in hardware, SBOREN disabled 
 #define BOREN_XSLP	0xFFFD 	// Enabled while active,disabled in SLEEP,SBOREN disabled 
 #define SWBOREN	0xFFFB 	// Controlled with SBOREN bit 
 #define BORDIS		0xFFF9 	// Disabled in hardware, SBOREN disabled 
// Brown Out Voltage
 #define BORV20		0xFFFF 	// 2.0V 
 #define BORV27		0xFFF7 	// 2.7V 
 #define BORV42		0xFFEF 	// 4.2V 
 #define BORV45		0xFFE7 	// 4.5V 

// Watchdog Timer
 #define WDTEN		0xFFFF 	// Enabled 
 #define WDTDIS		0xFEFF 	// Disabled-Controlled by SWDTEN bit 
// Watchdog Postscaler
 #define WDTPS32K	0xFFFF 	// 1:32768 
 #define WDTPS16K	0xFDFF 	// 1:16384 
 #define WDTPS8K	0xFBFF 	// 1:8192 
 #define WDTPS4K	0xF9FF 	// 1:4096 
 #define WDTPS2K	0xF7FF 	// 1:2048 
 #define WDTPS1K	0xF5FF 	// 1:1024 
 #define WDTPS512	0xF3FF 	// 1:512 
 #define WDTPS256	0xF1FF 	// 1:256 
 #define WDTPS128	0xEFFF 	// 1:128 
 #define WDTPS64	0xEDFF 	// 1:64 
 #define WDTPS32	0xEBFF 	// 1:32 
 #define WDTPS16	0xE9FF 	// 1:16 
 #define WDTPS8		0xE7FF 	// 1:8 
 #define WDTPS4		0xE5FF 	// 1:4 
 #define WDTPS2		0xE3FF 	// 1:2 
 #define WDTPS1		0xE1FF 	// 1:1 

// config word 3
// CCP2 Mux
 #define CCP2RC1	0xFFFF 	// RC1 
 #define CCP2RB3	0xFEFF 	// RB3 
// PortB A/D Enable
 #define PBDIGITAL	0xFDFF 	// PORTB<4:0> configured as digital I/O on RESET 
 #define PBADDIS	PBDIGITAL 	// Deprecated
 #define PBANALOG	0xFFFF 	// PORTB<4:0> configured as analog inputs on RESET 
 #define PBADEN		PBANALOG 	// Deprecated
// Low Power Timer1 Osc enable
 #define LPT1EN		0xFFFF 	// Enabled 
 #define LPT1DIS	0xFBFF 	// Disabled 
// Master Clear Enable
 #define MCLREN		0xFFFF 	// MCLR Enabled,RE3 Disabled 
 #define MCLRDIS	0x7FFF 	// MCLR Disabled,RE3 Enabled 

// config word 4
// Extended CPU Enable
 #define XINSTEN	0xFFFF 	// Enabled 
 #define XINSTDIS	0xFFBF 	// Disabled 
// Stack Overflow Reset
 #define STVREN		0xFFFF & XINSTDIS 	// Enabled 
 #define STVRDIS	0xFFFE & XINSTDIS 	// Disabled 
// Low Voltage Program
 #define LVPEN		0xFFFF & XINSTDIS 	// Enabled 
 #define LVPDIS		0xFFFB & XINSTDIS 	// Disabled 
// Background Debug
 #define DEBUGDIS	0xFFFF & XINSTDIS 	// Disabled 
 #define DEBUGEN	0xFF7F & XINSTDIS 	// Enabled 

// config word 5
// Code Protection
 #define UNPROTECT	0xFFFF 	// Do not protect code 
 #define CP0		0xFFFE 	// Code Protect 00800-01FFF 
 #define CP1		0xFFFD 	// Code Protect 02000-03FFF 
#if defined(_18F2520) || defined(_18F4520)
 #define CP2		0xFFFB 	// Code Protect 04000-05FFF 
 #define CP3		0xFFF7 	// Code Protect 06000-07FFF 
 #define CPA		CP0 & CP1 & CP2 & CP3
#else
 #define CPA		CP0 & CP1
#endif
 #define CPD		0x7FFF 	// Data EEPROM Code Protect 
 #define CPB		0xBFFF 	// Code Protect Boot 
 #define CPALL		CPA & CPB & CPD		// Protect all of the above 

// config word 6
// Table Write Protection
// to disable protection use UNPROTECT
 #define WP0		0xFFFE 	// Table Write Protect 00800-01FFF 
 #define WP1		0xFFFD 	// Table Write Protect 02000-03FFF 
#if defined(_18F2520) || defined(_18F4520)
 #define WP2		0xFFFB 	// Table Write Protect 04000-05FFF 
 #define WP3		0xFFF7 	// Table Write Protect 06000-07FFF 
 #define WPA		WP0 & WP1 & WP2 & WP3
#else
 #define WPA		WP0 & WP1
#endif
 #define WPD		0x7FFF 	// Data EEPROM Write Protect 
 #define WPB		0xBFFF 	// Table Write Protect Boot 
 #define WPC		0xDFFF 	// Config. Write Protect 
 #define WPALL		WPA & WPB & WPD	& WPC	// Protect all of the above 

// config word 7
// Table Read Protection
// to disable protection use UNPROTECT
 #define TRP0		0xFFFE 	// Table Read Protect 00800-01FFF 
 #define TRP1		0xFFFD 	// Table Read Protect 02000-03FFF 
#if defined(_18F2520) || defined(_18F4520)
 #define TRP2		0xFFFB 	// Table Read Protect 04000-05FFF 
 #define TRP3		0xFFF7 	// Table Read Protect 06000-07FFF 
 #define TRA		TR0 & TR1 & TR2 & TR3
#else
 #define TRA		TR0 & TR1
#endif
 #define TRPB		0xBFFF 	// Table Read Protect Boot 
 #define TRPALL		TRPA & TRPB	// Protect all of the above 

#endif
