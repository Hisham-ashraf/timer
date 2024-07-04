#include "Keypad.h"

typedef unsigned char uint8;

uint8 sec = 0, min = 0;

void display_time(void);
void timer_init(void);
void counter(void);
void adjust_minutes(void);
void adjust_seconds(void);
void timer_on(void);
void timer_reset(void);

int main(void) {
	DDRC = 0xff; DDRD = 0xff;
	PORTC = 0; PORTD = 0;

	timer_init();

	uint8 key;

	while (1) {
		key = keyPress();
		
		switch (key) {
			case '+':
			adjust_seconds();
			break;
			
			case '-':
			adjust_minutes();
			break;
			
			case 'C':
			timer_reset();
			break;
			
			case '=':
			timer_on();
			break;
			
			case 'D':
			counter();
			break;
		}

	}

	return 0;
}



void display_time(void) {
	PORTD = (sec /10)*6 + sec;
	PORTC = (min /10)*6 + min ;
}

void timer_init(void) {
	TCNT0 = 0 ;
	TCCR0 |= (1 << CS02) | (1 << CS01) | (1 << CS00); 
}

void adjust_minutes(void) {
	TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
	min++; 
	if (min == 60) {
		min = 0;
	}
	display_time();
}

void adjust_seconds(void) {
	TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
	sec++;
	if (sec == 60) {
		sec = 0;
	}
	display_time();
}

void timer_on(void) {
	TCCR0 |= (1 << CS02) | (1 << CS01) | (1 << CS00);
}

void timer_reset(void) {
	sec = 0; 
	min = 0;
	display_time();
}

void counter(void) {
	if (TCNT0 == 1) {
		TCNT0 = 0;
		sec++;
		if (sec == 60) {
			sec = 0;
			min++;
			if (min == 60) {
				min = 0;
			}
		}
	}
	display_time();
}