/*
 * First Steps 4.c
 *
 * Author : hamster
 * With code borrowed from https://www.avrfreaks.net/forum/tut-c-bit-manipulation-aka-programming-101
 */ 

#define F_CPU 16000000L					// crystal is 16MHz

#include <avr/io.h>
#include <util/delay.h>
#include "config.h"
#include "bitroutines.h"

#define DELAY	100

int main(void){
	
	int currentLED = 0;
	DDRB = 0x3F;						// Data direction register for Port B - pins 0-5 set to output
	PORTB = 0x3F;						// Set pins 0-5 to high
	
	DDRD = 0xF0;						// Set top four bits as outputs, and the bottom 4 as inputs
	PORTD = 0xFC;						// Set the top four bits high, and configure the two switch inputs as pullups
	
    while(1){							// Forever and ever and ever and ...
			
		if(C_CHECKBIT(RIGHT_SWITCH) == 0){
			// Debounce
			_delay_ms(5);
			if(C_CHECKBIT(RIGHT_SWITCH) == 0){
				// Right switch is still pressed		
				currentLED++;
				if(currentLED > 3){
					currentLED = 0;
				}
			}
		}
	
		if(C_CHECKBIT(LEFT_SWITCH) == 0){
			// Debounce
			_delay_ms(5);
			if(C_CHECKBIT(LEFT_SWITCH) == 0){
				// Left switch is still pressed
				currentLED--;
				if(currentLED < 0){
					currentLED = 3;
				}
			}
		}
		
		switch(currentLED){
			case 0:
				C_CLEARBIT(UPPER_RIGHT_YELLOW);
				_delay_ms(DELAY);
				C_SETBIT(UPPER_RIGHT_YELLOW);
				_delay_ms(DELAY);
				break;
			case 1:
				C_CLEARBIT(UPPER_LEFT_YELLOW);
				_delay_ms(DELAY);
				C_SETBIT(UPPER_LEFT_YELLOW);
				_delay_ms(DELAY);
				break;
			case 2:
				C_CLEARBIT(LOWER_LEFT_YELLOW);
				_delay_ms(DELAY);
				C_SETBIT(LOWER_LEFT_YELLOW);
				_delay_ms(DELAY);
				break;
			case 3:
				C_CLEARBIT(LOWER_RIGHT_YELLOW);
				_delay_ms(DELAY);
				C_SETBIT(LOWER_RIGHT_YELLOW);
				_delay_ms(DELAY);
				break;
		}	
    }
}