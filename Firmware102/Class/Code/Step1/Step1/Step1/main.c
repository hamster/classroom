/*
 * First Steps.c
 *
 * Author : hamster
 */ 

#define F_CPU 16000000L			// crystal is 16MHz

#include <avr/io.h>
#include <util/delay.h>

int main(void){
	
	DDRB = 0x3F;				// Data direction register for Port B - pins 0-5 set to output
	PORTB = 0x3F;				// Set pins 0-5 to high
	
    while(1){					// Forever and ever and ever and ...
	
		PORTB &= ~(1 << 5);		// Set pin 5 low
		_delay_ms(100);			// wait for it...
		PORTB |= (1 << 5);		// Set pin 5 high
		_delay_ms(100);			// wait for it...
		
    }
}

