
	; Microchip MPLAB XC8 C Compiler V1.30
	; Copyright (C) 1984-2014 HI-TECH Software

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -oLamtec Board Tester.cof -mLamtec Board Tester.map --summary=default \
	; --output=default DELAY16.p1 main.p1 Lcd.p1 --chip=18F43K22 \
	; -IC:\Users\Jim\Documents\Lamtec Board Tester \
	; -IC:\Work\Lamtec Board Tester \
	; -IC:\Users\Toto\Documents\Work\Lamtec Board Tester -P \
	; --runtime=default --opt=default,+asm,-debug,-speed,+space,9 --warn=0 \
	; -N255 --addrqual=ignore -g --asmlist \
	; --errformat=Error   [%n] %f; %l.%c %s --msgformat=Advisory[%n] %s \
	; --warnformat=Warning [%n] %f; %l.%c %s
	;


	processor	18F43K22

	GLOBAL	_main,start
	FNROOT	_main

	pic18cxx	equ	1

	psect	config,class=CONFIG,delta=1,noexec
	psect	idloc,class=IDLOC,delta=1,noexec
	psect	const,class=CODE,delta=1,reloc=2,noexec
	psect	smallconst,class=SMALLCONST,delta=1,reloc=2,noexec
	psect	mediumconst,class=MEDIUMCONST,delta=1,reloc=2,noexec
	psect	rbss,class=COMRAM,space=1,noexec
	psect	bss,class=RAM,space=1,noexec
	psect	rdata,class=COMRAM,space=1,noexec
	psect	irdata,class=CODE,space=0,reloc=2,noexec
	psect	bss,class=RAM,space=1,noexec
	psect	data,class=RAM,space=1,noexec
	psect	idata,class=CODE,space=0,reloc=2,noexec
	psect	nvrram,class=COMRAM,space=1,noexec
	psect	nvbit,class=COMRAM,bit,space=1,noexec
	psect	temp,ovrld,class=COMRAM,space=1,noexec
	psect	struct,ovrld,class=COMRAM,space=1,noexec
	psect	rbit,class=COMRAM,bit,space=1,noexec
	psect	bigbss,class=BIGRAM,space=1,noexec
	psect	bigdata,class=BIGRAM,space=1,noexec
	psect	ibigdata,class=CODE,space=0,reloc=2,noexec
	psect	farbss,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	nvFARRAM,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	fardata,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	ifardata,class=CODE,space=0,reloc=2,delta=1,noexec

	psect	reset_vec,class=CODE,delta=1,reloc=2
	psect	powerup,class=CODE,delta=1,reloc=2
	psect	intcode,class=CODE,delta=1,reloc=2
	psect	intcode_body,class=CODE,delta=1,reloc=2
	psect	intcodelo,class=CODE,delta=1,reloc=2
	psect	intret,class=CODE,delta=1,reloc=2
	psect	intentry,class=CODE,delta=1,reloc=2

	psect	intsave_regs,class=BIGRAM,space=1
	psect	init,class=CODE,delta=1,reloc=2
	psect	text,class=CODE,delta=1,reloc=2
GLOBAL	intlevel0,intlevel1,intlevel2
intlevel0:
intlevel1:
intlevel2:
GLOBAL	intlevel3
intlevel3:
	psect	end_init,class=CODE,delta=1,reloc=2
	psect	clrtext,class=CODE,delta=1,reloc=2

	psect	eeprom_data,class=EEDATA,delta=1,noexec
	psect	smallconst
	GLOBAL	__smallconst
__smallconst:
	psect	mediumconst
	GLOBAL	__mediumconst
__mediumconst:
wreg	EQU	0FE8h
fsr0l	EQU	0FE9h
fsr0h	EQU	0FEAh
fsr1l	EQU	0FE1h
fsr1h	EQU	0FE2h
fsr2l	EQU	0FD9h
fsr2h	EQU	0FDAh
postinc0	EQU	0FEEh
postdec0	EQU	0FEDh
postinc1	EQU	0FE6h
postdec1	EQU	0FE5h
postinc2	EQU	0FDEh
postdec2	EQU	0FDDh
tblptrl	EQU	0FF6h
tblptrh	EQU	0FF7h
tblptru	EQU	0FF8h
tablat		EQU	0FF5h

	PSECT	ramtop,class=RAM,noexec
	GLOBAL	__S1			; top of RAM usage
	GLOBAL	__ramtop
	GLOBAL	__LRAM,__HRAM
__ramtop:

	psect	reset_vec
reset_vec:
	; No powerup routine
	global start

; jump to start
	goto start
	GLOBAL __accesstop
__accesstop EQU 96


	psect	init
start:

;Initialize the stack pointer (FSR1)
	global stacklo, stackhi
	stacklo	equ	013Fh
	stackhi	equ	01FFh


	psect	stack,class=STACK,space=2,noexec
	global ___sp,___inthi_sp,___intlo_sp
___sp:
___inthi_sp:
___intlo_sp:

	psect	end_init
	global start_initialization
	goto start_initialization	;jump to C runtime clear & initialization

; Padding undefined space
	psect	config,class=CONFIG,delta=1,noexec
		org 0x0
		db 0xFF

; Config register CONFIG1H @ 0x300001
;	Internal/External Oscillator Switchover bit
;	IESO = OFF, Oscillator Switchover mode disabled
;	Oscillator Selection bits
;	FOSC = HSHP, HS oscillator (high power > 16 MHz)
;	Primary clock enable bit
;	PRICLKEN = ON, Primary clock is always enabled
;	Fail-Safe Clock Monitor Enable bit
;	FCMEN = ON, Fail-Safe Clock Monitor enabled
;	4X PLL Enable
;	PLLCFG = OFF, Oscillator used directly

	psect	config,class=CONFIG,delta=1,noexec
		org 0x1
		db 0x62

; Config register CONFIG2L @ 0x300002
;	Brown-out Reset Enable bits
;	BOREN = OFF, Brown-out Reset disabled in hardware and software
;	Brown Out Reset Voltage bits
;	BORV = 0x3, unprogrammed default
;	Power-up Timer Enable bit
;	PWRTEN = ON, Power up timer enabled

	psect	config,class=CONFIG,delta=1,noexec
		org 0x2
		db 0x18

; Config register CONFIG2H @ 0x300003
;	Watchdog Timer Postscale Select bits
;	WDTPS = 0xF, unprogrammed default
;	Watchdog Timer Enable bits
;	WDTEN = OFF, Watch dog timer is always disabled. SWDTEN has no effect.

	psect	config,class=CONFIG,delta=1,noexec
		org 0x3
		db 0x3C

; Padding undefined space
	psect	config,class=CONFIG,delta=1,noexec
		org 0x4
		db 0xFF

; Config register CONFIG3H @ 0x300005
;	ECCP2 B output mux bit
;	P2BMX = 0x1, unprogrammed default
;	CCP2 MUX bit
;	CCP2MX = 0x1, unprogrammed default
;	PORTB A/D Enable bit
;	PBADEN = OFF, PORTB<5:0> pins are configured as digital I/O on Reset
;	P3A/CCP3 Mux bit
;	CCP3MX = 0x1, unprogrammed default
;	MCLR Pin Enable bit
;	MCLRE = EXTMCLR, MCLR pin enabled, RE3 input pin disabled
;	HFINTOSC Fast Start-up
;	HFOFST = ON, HFINTOSC output and ready status are not delayed by the oscillator stable status
;	Timer3 Clock input mux bit
;	T3CMX = 0x1, unprogrammed default

	psect	config,class=CONFIG,delta=1,noexec
		org 0x5
		db 0xBD

; Config register CONFIG4L @ 0x300006
;	Background Debug
;	DEBUG = OFF, Disabled
;	Stack Full/Underflow Reset Enable bit
;	STVREN = OFF, Stack full/underflow will not cause Reset
;	Extended Instruction Set Enable bit
;	XINST = OFF, Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
;	Single-Supply ICSP Enable bit
;	LVP = OFF, Single-Supply ICSP disabled

	psect	config,class=CONFIG,delta=1,noexec
		org 0x6
		db 0x80

; Padding undefined space
	psect	config,class=CONFIG,delta=1,noexec
		org 0x7
		db 0xFF

; Config register CONFIG5L @ 0x300008
;	Code Protection Block 0
;	CP0 = OFF, Block 0 (000200-000FFFh) not code-protected
;	Code Protection Block 1
;	CP1 = OFF, Block 1 (001000-001FFFh) not code-protected

	psect	config,class=CONFIG,delta=1,noexec
		org 0x8
		db 0x3

; Config register CONFIG5H @ 0x300009
;	unspecified using default value

	psect	config,class=CONFIG,delta=1,noexec
		org 0x9
		db 0xC0


psect comram,class=COMRAM,space=1
psect abs1,class=ABS1,space=1
psect bigram,class=BIGRAM,space=1
psect ram,class=RAM,space=1
psect bank0,class=BANK0,space=1
psect bank1,class=BANK1,space=1
psect sfr,class=SFR,space=1


	end	start
