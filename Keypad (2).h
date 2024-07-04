/*
 * Keypad.h
 *
 * Created: 8/3/2016 8:10:56 PM
 *  Author: Ahmad-Mustafa 
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

//typedef unsigned char uint8;

#define NC 4
#define NR 4

#define KEYPAD_PORT PORTA
#define KEYPAD_PIN  PINA
#define KEYPAD_DDR  DDRA 

unsigned char keyPress(void);

#endif /* KEYPAD_H_ */