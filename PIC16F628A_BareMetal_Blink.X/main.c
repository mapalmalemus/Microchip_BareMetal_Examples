/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 18, 2025, 7:39 PM
 */
//TB3261
//PIC1000: Getting Started with Writing C-Code for PIC16 and PIC18

// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>
//#include <pic16f628a.h>

void main(void) {
    
/* setting pin RA0,RA1,RB0,RB1 as output (LED) */
    

/* 
 * 5.0 I/O PORTS
 * REGISTER 10-1: CMCON ? COMPARATOR CONFIGURATION REGISTER (ADDRESS: 01Fh)
 * REGISTER 11-1: VRCON ? VOLTAGE REFERENCE CONTROL REGISTER (ADDRESS: 9Fh)
 * REGISTER 4-2: OPTION_REG ? OPTION REGISTER (ADDRESS: 81h, 181h)
 *
 */    
CMCON = 0x07;
VRCON = 0x00;
//OPTION_REG = 0X0;
TRISAbits.TRISA0 = 0;
TRISAbits.TRISA1 = 0;
TRISBbits.TRISB0 = 0;
TRISBbits.TRISB1 = 0;
PORTAbits.RA0 = 0;
PORTAbits.RA1 = 0;
PORTBbits.RB0 = 0;
PORTBbits.RB1 = 0;

    /* main program loop */
    while(1) {
    
    /* turn on the LED (pin RB0 high) */ 
    //3.1.1 Set, Clear and Read Register Bits using Bit Unions
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    PORTBbits.RB0 = 1;
    PORTBbits.RB1 = 1;
    
    //__delay_us(1000);
    __delay_ms(2);

    /* turn off the LED (pin RB0 high) */ 
    //3.1.1 Set, Clear and Read Register Bits using Bit Unions
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTBbits.RB0 = 0;
    PORTBbits.RB1 = 0;


    //__delay_us(1000);
    __delay_ms(2);
       
    }
    return;
}




