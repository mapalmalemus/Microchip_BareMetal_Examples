/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 25, 2025, 3:03 AM
 */

// PIC12F683 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>
#include <pic12f683.h>
//#include <pic12f683_legacy.h>


void main(void) {
    
/* setting pin RA0,RA1,RB0,RB1 as output (LED) */
    

/* 
 * 4.0 GPIO PORT
 * 4.1 GPIO and the TRISIO Registers
 * 4.2 Additional Pin Functions
 *
 */   
GPIO = 0x00;
CMCON0 = 0x07;
//CMCON1 = 0x07;
ANSEL = 0x00;
//VRCON = 0x00;
//TRISIO = 0x00;
TRISIObits.TRISIO0 = 0;
TRISIObits.TRISIO1 = 0;
TRISIObits.TRISIO2 = 0;
TRISIObits.TRISIO3 = 1;
TRISIObits.TRISIO4 = 0;
TRISIObits.TRISIO5 = 0;
//GPIO = 0x00;
GPIObits.GP0 = 0;
GPIObits.GP1 = 0;
GPIObits.GP2 = 0;
//GPIObits.GP3 = 0;
GPIObits.GP4 = 0;
GPIObits.GP5 = 0;


    /* main program loop */
    while(1) {
    
    /* turn on the LED (pin RB0 high) */ 
    //3.1.1 Set, Clear and Read Register Bits using Bit Unions
    GPIObits.GP0 = 1;
    GPIObits.GP1 = 1;
    GPIObits.GP2 = 1;
    //GPIObits.GP3 = 1;
    
    __delay_us(1000);
    //__delay_ms(500);

    /* turn off the LED (pin RB0 high) */ 
    //3.1.1 Set, Clear and Read Register Bits using Bit Unions
    GPIObits.GP0 = 0;
    GPIObits.GP1 = 0;
    GPIObits.GP2 = 0;
    //GPIObits.GP3 = 0;

    __delay_us(1000);
    //__delay_ms(500);
       
    }
    return;
}



