/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 18, 2025, 7:39 PM
 */

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
//#include <xc.h>

void main(void) {
    
/* setting pin RB0 as output (LED) */
TRISAbits.TRISA0 = 0;
TRISAbits.TRISA1 = 0;
TRISBbits.TRISB0 = 0;     
/* setting pin RB1 as input (button) */
//TRISBbits.TRISB1 = 1;
/* enable digital input buffer for pin RB1 (button) */
//ANSELBbits.ANSELB1 = 0;
/* enable internal pull-up for pin RB1 (button) */
//WPUBbits.WPUB1 = 1;
    
    /* main program loop */
while(1) {
    
    /* turn on the LED (pin RB0 high) */
    //LATBbits.LATB0 = 1;
    PORTAbits.RA0 = 1;
    _delay(10);
    //_delay(50,463,240);
    PORTAbits.RA0 = 0;
    _delay(10);
    PORTAbits.RA1 = 0;
    PORTBbits.RB0 = 1;
    
    /* if button is pressed (pin RB1 high) */
    //if(PORTBbits.RB1)
    //{
        /* turn on the LED (pin RB0 high) */
    //    LATBbits.LATB0 = 1;
    //}else
    //{
        /* turn off the LED (pin RE0 low) */
    //    LATEbits.LATE0 = 0;
    //}
           
}
            
    return;
}








