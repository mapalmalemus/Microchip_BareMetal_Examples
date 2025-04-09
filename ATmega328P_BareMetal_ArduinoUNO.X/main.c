/*
 * File:   main.c
 * Author: miguelpalma
 *
 * Created on March 25, 2025, 5:48 PM
 */

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


