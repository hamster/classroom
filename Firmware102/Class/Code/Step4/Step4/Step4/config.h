/*
 * First Steps 3.c
 *
 * Author : hamster
 * Configuration for the DC801 shield
 */ 

#define UPPER_RIGHT_YELLOW	PORTB, 5	// D6
#define UPPER_LEFT_YELLOW	PORTB, 4	// D5
#define LOWER_RIGHT_YELLOW	PORTB, 3	// D4
#define LOWER_LEFT_YELLOW	PORTB, 2	// D3

// D1
#define LEFT_EYE_BLUE	PORTB, 1
#define LEFT_EYE_GREEN	PORTB, 0
#define LEFT_EYE_RED	PORTD, 7

// D2
#define RIGHT_EYE_BLUE	PORTD, 6
#define RIGHT_EYE_GREEN	PORTD, 5
#define RIGHT_EYE_RED	PORTD, 4

#define RIGHT_SWITCH	PIND, 3
#define LEFT_SWITCH		PIND, 2
