/*
 * stepper.h
 *
 * Created: 17.12.2013 22:57:39
 *  Author: Samuel
 */ 


#ifndef MAIN_H_
#define MAIN_H_

//includes
#include <avr/io.h>
#include <avr/power.h> //für set prescaler
#include <avr/interrupt.h>
#define F_CPU 16000000UL  //muss vor delay.h wegen taktfreq
#include <util/delay.h> //_delay_ms
#include <stdlib.h>	//utoa
#include <stdbool.h>//erlaubt bool

#include "usb_serial.h"
#include "adc.h"
#include "millis.h"
#include "stepper.h"
#include "tool.h"
#include "cmd.h"
//defines
#define E6_on PORTE |= (1<<PINE6);//debug led
#define E6_off PORTE &= ~(1<<PINE6);
#define E6_toggle PORTE^=(1<<PINE6);

#define disable_stepper	PORTC &= ~(1<<PINC6);//portpin low
#define enable_stepper PORTC |= (1<<PINC6); //portpin hign


//funktions prototypen
void sleep_us(uint16_t us);
void sleep_ms(uint16_t ms);
void bootloader (void); // jump into usb bootloader
uint8_t get_switch(void); //read adc to get which switch is pressed
#endif /*MAIN_H_ */