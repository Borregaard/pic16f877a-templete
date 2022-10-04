#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#pragma config FOSC = HS    // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF	// Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF	// Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF	// Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF	// Low-Voltage (Single-Supply) In-Circuit Serial Programming 
#pragma config CPD = OFF	// Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF	// Flash Program Memory Write protection 
#pragma config CP = OFF     // Flash Program Memory Code Protection bit

#define _XTAL_FREQ 10000000	// Her angives frekvensen på krystallen

#endif	/* XC_HEADER_TEMPLATE_H */

