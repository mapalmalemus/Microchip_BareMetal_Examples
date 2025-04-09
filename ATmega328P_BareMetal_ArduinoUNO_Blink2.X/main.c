/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 27, 2025, 2:40 AM
 */

// REFERENCE
// 
// Microchip Developer Help
// https://youtube.com/playlist?list=PLtQdQmNK_0DQ8KGcZ1BOPv-3RDPvtqJ1H&si=lkYU_Lm8c3_0KiEW
// https://youtu.be/Cxabz8PcgaU
// Ross Satchel from Microchip
//

/*
 
 * Arduino® UNO R3
 * 
 * https://store.arduino.cc/products/arduino-uno-rev3
 * 
 * 5.1  JANALOG
 * Pin  Functions               Type                Description
 * 1    NC                      NC                  Not connected
 * 2    IOREF                   IOREF               Reference for digital logic V - connected to 5V
 * 3    PC6/Reset               Reset               Reset
 * 4    +3V3                    Power               +3V3 Power Rail
 * 5    +5V                     Power               +5V Power Rail
 * 6    GND                     Power               Ground
 * 7    GND                     Power               Ground
 * 8    VIN                     Power               Voltage Input
 * 9    ADC[0]/PC0/A0/D14       Analog/GPIO         Analog input 0 /GPIO
 * 10   ADC[1]/PC1/A1/D15       Analog/GPIO         Analog input 1 /GPIO
 * 11   ADC[2]/PC2/A2/D16       Analog/GPIO         Analog input 2 /GPIO
 * 12   ADC[3]/PC3/A3/D17       Analog/GPIO         Analog input 3 /GPIO
 * 13   ADC[4]/PC4/A4/SDA/D18   Analog input/I2C    Analog input 4 /I2C Data line
 * 14   ADC[5]/PC5/A5/SCL/D19   Analog input/I2C    Analog input 5 /I2C Clock line
 * 
 * 5.2  JDIGITAL
 * Pin  Function                    Type                Description
 * 1    PD0/RX/D0                   Digital/GPIO        Digital pin 0/GPIO
 * 2    PD1/TX/D1                   Digital/GPIO        Digital pin 1/GPIO
 * 3    PD2/D2                      Digital/GPIO        Digital pin 2/GPIO
 * 4    PD3/D3                      Digital/GPIO        Digital pin 3/GPIO
 * 5    PD4/D4                      Digital/GPIO        Digital pin 4/GPIO
 * 6    PD5/D5                      Digital/GPIO        Digital pin 5/GPIO
 * 7    PD6/D6                      Digital/GPIO        Digital pin 6/GPIO
 * 8    PD7/D7                      Digital/GPIO        Digital pin 7/GPIO
 * 9    PB0/D8                      Digital/GPIO        Digital pin 8/GPIO
 * 10   PB1/D9                      Digital/GPIO        Digital pin 9/GPIO
 * 11   PB2/SS/D10                  Digital             SPI Chip Select
 * 12   PB3/MOSI/D11                Digital             SPI1 Main Out Secondary In
 * 13   PB4/MISO/D12                Digital             SPI Main In Secondary Out
 * 14   PB5/SCK/D13                 Digital             SPI serial clock output
 * 15   GND                         Power               Ground
 * 16   AREF                        Digital             Analog reference voltage
 * 17   PC4/A4/SD4/ADC[4]/SDA/D18   Digital             Analog input 4/I2C Data line (duplicated)
 * 18   PC5/A5/SD5/ADC[5]/SCL/D19   Digital             Analog input 5/I2C Clock line (duplicated)
 * 
 *      LED_BUILTIN/PB5/D13         Digital             LED built in
 *      TX LED/PD5                  Digital             LED tx            
 *      RX LED/PD4                  Digital             LED rx     
 *      POWER
 * 
 */

// ATmega328P Configuration Bit Settings

// 'C' source line config statements

#include <avr/io.h>

FUSES = {
	.low = 0x62, // LOW {SUT_CKSEL=INTRCOSC_8MHZ_6CK_14CK_65MS, CKOUT=CLEAR, CKDIV8=SET}
	.high = 0x99, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, DWEN=SET, RSTDISBL=CLEAR}
	.extended = 0xFF, // EXTENDED {BODLEVEL=DISABLED}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}


/* _XTAL_FREQ is defined by MCC headers; when not using MCC, place a definition similar to: #define _XTAL_FREQ 4000000
in your code to ensure that the 'us' and 'ms' forms of delay routines work as expected. */
#define _XTAL_FREQ 8000000
//#define F_CPU 16000000UL

#include <xc.h>
//#include <avr/iom328p.h>
//#include <avr/delay.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>

ISR(TIMER1_OVF_vect)
{
PORTB |= _BV(0); // results in SBI which does not affect SREG

return;
}

unsigned int read_timer1(void)
{
unsigned int val;
__builtin_avr_cli(); // disable interrupts
val = TCNT1; // read timer value register; TEMP used internally
__builtin_avr_sei(); // re-enable interrupts
return val;
}


void main(void) {
    unsigned char sreg, tifr1;
    //unsigned long i,counter;
    int i;
    int counter=0;
    int test; 
    i = 4000;
    double x,y;
    errno = 0;
    x = -1.0;
    y = cos (x);
    //if (errno)
    //perror("Error");
    //printf("The cosine of %f is %f\n", x, y);
    errno = 0;
    x = 0.0;
    y = cos (x);
    //if (errno)
    //perror("Error");
    //printf("The cosine of %f is %f\n", x, y);

    /* MANUAL ATMEGA328P 14 I/O  */
    /* Direction configuration of the pins */
    /* Read-Modify-Write: Software */
    // Initialization CLKPR Clock Prescale Register with 0000 mode or clock division factor 1
    //CLKPR = (1<<CLKPCE)|(1<<CLKPS3)|(1<<CLKPS2)|(1<<CLKPS1)|(1<<CLKPS0);
    //DDRB |= (1 << PB5); // set PB5 as output pin
    DDRB |= _BV(PB7)|_BV(PB6)|_BV(PB5)|_BV(PB4); // set PB7-4 as output pin
    //DDRB &= !(_BV(PB0)); // clear PB4 as input pin
    DDRB |= _BV(PB3)|_BV(PB2)|_BV(PB1)|_BV(PB0); // set PB3-0 as output pin
    PORTB = 0x55;
    // Initialization TCCR1A Timer/Counter1 Control Register A
    //TCCR1A = (1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0)|(1<<WGM11)|(1<<WGM10);
    // Initialization TCCR1B Timer/Counter1 Control Register B set up Clock Select CLKio/1 (NoPrescaling/001)
    //TCCR1B = (1<<ICNC1)|(1<<ICES1)|(1<<WGM13)|(1<<WGM12)|(1<<CS12)|(1<<CS11)|(1<<CS10);
    TCCR1B = (1<<CS10);
    //Initialization TCCR1C Timer/Counter2 Control Register C bits Force Output Compare 1 for Channel A/B 
    //TCCR1C = (1<<FOC1A)|(1<<FOC1B);
    //Initialization TIMSK1 Timer/Counter1 Interrupt Mask Register  
    //TIMSK1 = (1<<ICIE1)|(1<<OCIE1B)|(1<<OCIE1A)|(1<<TOIE1);
    //TIMSK1 = (1<<TOIE1);
    //TIFR1 NOT Initialization TIFR1 Timer/Counter1 Interrupt Flag Register (Only Read))
    //TIFR1 = !(1<<ICF1)&!(1<<OCF1B)&!(1<<OCF1A)&!(1<<TOV1);
    
     /* Save global interrupt flag */
    //sreg = SREG;
    //tifr1 = TIFR1;
    /* Disable interrupts */
    //_CLI();
    //TCNT1 = 0x0000;
    /* Restore global interrupt flag */
    //SREG = sreg;
        
    //Halt by software to Debug
    //while(1){    
    //}
    
    //__builtin_avr_cli(); // disable interrupts
    //TIFR1 NOT Initialization TIFR1 Timer/Counter1 Interrupt Flag Register (Only Read))
    //TIFR1 = (1<<TOV1);
    TIFR1 = _BV(TOV1);
    //Initialization TIMSK1 Timer/Counter1 Interrupt Mask Register      
    //TIMSK1 = (1<<TOIE1);
    //__builtin_avr_sei(); // re-enable interrupts
 
    while(1){  
    
    //test = bit_is_set(TIFR1,TOV1);    
    if(bit_is_set(TIFR1,TOV1))
    //if(bit_is_clear(TIFR1,TOV1)); 
    //loop_until_bit_is_set(TIFR1,TOV1);
    //loop_until_bit_is_clear(TIFR1,TOV1);
        {
        //test = bit_is_set(TIFR1,TOV1);
        TIFR1 = (1<<TOV1);
        counter++;
        if(counter == 500)
            {
            //__builtin_avr_cli(); // disable interrupts
            //PORTB |= (1 << PB5);    // set PB5 high all time (No Blink or Turn ON permanent ) 
            //PORTB &= !(1 << PB5);    // set PB5 low all time (No Blink or Turn OFF permanent ) 
            PINB |= (1 << PINB5); // set PB5 high_low all time (Blink or Pulse)        
            counter = 0;
            }
        }    
        
    }
    
    return;
}



