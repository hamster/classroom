/*
 * First Steps 2.c
 *
 * Author : hamster
 * With code borrowed from https://www.avrfreaks.net/forum/tut-c-bit-manipulation-aka-programming-101
 */ 

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define VARFROMCOMB(x, y) x
#define BITFROMCOMB(x, y) y

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))

#define UPPER_RIGHT_YELLOW PORTB, 5

#define F_CPU 16000000L					// crystal is 16MHz

#include <avr/io.h>
#include <util/delay.h>

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


