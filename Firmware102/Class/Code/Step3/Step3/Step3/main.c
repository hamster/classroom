/*
 * First Steps 3.c
 *
 * Author : hamster
 * With code borrowed from https://www.avrfreaks.net/forum/tut-c-bit-manipulation-aka-programming-101
 */ 

#define F_CPU 16000000L					// crystal is 16MHz

#include <avr/io.h>
#include <util/delay.h>
#include "config.h"
#include "bitroutines.h"

int main(void){
	
	DDRB = 0x3F;						// Data direction register for Port B - pins 0-5 set to output
	PORTB = 0x3F;						// Set pins 0-5 to high
	
    while(1){							// Forever and ever and ever and ...
	
		C_CLEARBIT(UPPER_RIGHT_YELLOW);	// Set pin 5 low
		_delay_ms(100);					// wait for it...
		C_SETBIT(UPPER_RIGHT_YELLOW);	// Set pin 5 high
		_delay_ms(100);					// wait for it...
		
    }
}

