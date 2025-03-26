/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 25, 2025, 5:48 PM
 */

// ATmega328P Configuration Bit Settings

// 'C' source line config statements

#include <avr/io.h>

FUSES = {
	.low = 0x62, // LOW {SUT_CKSEL=INTRCOSC_8MHZ_6CK_14CK_65MS, CKOUT=CLEAR, CKDIV8=SET}
	.high = 0xD9, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, DWEN=CLEAR, RSTDISBL=CLEAR}
	.extended = 0xFF, // EXTENDED {BODLEVEL=DISABLED}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}

//REFERENCIA
//https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/8-bit-avr/getting-started/flashing-led/

/* _XTAL_FREQ is defined by MCC headers; when not using MCC, place a definition similar to: #define _XTAL_FREQ 4000000
in your code to ensure that the 'us' and 'ms' forms of delay routines work as expected. */
#define _XTAL_FREQ 4000000
//#define F_CPU 16000000UL

#include <xc.h>
#include <avr/delay.h>
//#include <avr/iom328p.h>


void main(void) {
    /* MANUAL ATMEGA328P 14 I/O  */
    /* Direction configuration of the pins */
    /* Read-Modify-Write: Software */

    DDRB |= (1 << PB5); // set PB5 as output pin
     
    while(1){
       
       //PORTB |= (1 << PB5);    // set PB5 high all time (No Blink or Turn ON permanent )      
       PINB |= (1 << PINB5); // set PB5 high_low all time (Blink or Pulse)
        
       //_delay_ms(5); 
       _delay_us(500);
        
    }
            
    return;
}


