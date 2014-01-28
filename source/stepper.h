/*
 * stepper.h
 *
 * Created: 19.12.2013 10:57:32
 *  Author: Samuel
 */ 
#ifndef STEPPER_H_
#define STEPPER_H_
#include <stdbool.h>


//extern  uint8_t stepper_x_pos;
extern  int32_t steps_x, steps_y, steps_z;

///////// Funktionsprototypen /////////////
void stepper_x_forward (void);	// stepper x    1 step vorwärts ohne pause nur io schalten
void stepper_x_backward (void); //  stepper x    1 step rückwerts ohne pause nur io schalten
void stepper_x_move (int32_t steps); // der stepper macht bis zu 32767 steps positiv und 32768 negativ

void stepper_y_forward (void);	// stepper y    1 step vorwärts ohne pause nur io schalten
void stepper_y_backward (void); //  stepper y    1 step rückwerts ohne pause nur io schalten
void stepper_y_move (int32_t steps); // der stepper macht bis zu 32767 steps positiv und 32768 negativ

void stepper_z_forward (void);	// stepper z    1 step vorwärts ohne pause nur io schalten
void stepper_z_backward (void); //  stepper z    1 step rückwerts ohne pause nur io schalten
void stepper_z_move (int32_t steps); // der stepper macht bis zu 32767 steps positiv und 32768 negativ



//////////////////////////////////////////////////////////////////////////////////////////
//                        defines X-Achse												//
//////////////////////////////////////////////////////////////////////////////////////////

#define x_achse_L1_a_high	PORTB |=  (1<<PB0);
#define x_achse_L1_a_low	PORTB &=~ (1<<PB0);

#define x_achse_L1_b_high	PORTB |=  (1<<PB1);
#define x_achse_L1_b_low	PORTB &=~ (1<<PB1);

#define x_achse_L2_a_high	PORTB |=  (1<<PB2);
#define x_achse_L2_a_low	PORTB &=~ (1<<PB2);

#define x_achse_L2_b_high	PORTB |=  (1<<PB3);
#define x_achse_L2_b_low	PORTB &=~ (1<<PB3);


#define  step1_x	 x_achse_L1_a_high		x_achse_L1_b_high	x_achse_L2_a_low	x_achse_L2_b_low
#define  step2_x	 x_achse_L1_a_low		x_achse_L1_b_high	x_achse_L2_a_high	x_achse_L2_b_low
#define  step3_x	 x_achse_L1_a_low		x_achse_L1_b_low	x_achse_L2_a_high	x_achse_L2_b_high
#define  step4_x	 x_achse_L1_a_high		x_achse_L1_b_low	x_achse_L2_a_low	x_achse_L2_b_high



//////////////////////////////////////////////////////////////////////////////////////////
//                        defines Y-Achse												//
//////////////////////////////////////////////////////////////////////////////////////////

#define y_achse_L1_a_high	PORTB |=  (1<<PB4);
#define y_achse_L1_a_low	PORTB &=~ (1<<PB4);

#define y_achse_L1_b_high	PORTB |=  (1<<PB5);
#define y_achse_L1_b_low	PORTB &=~ (1<<PB5);

#define y_achse_L2_a_high	PORTB |=  (1<<PB6);
#define y_achse_L2_a_low	PORTB &=~ (1<<PB6);

#define y_achse_L2_b_high	PORTB |=  (1<<PB7);
#define y_achse_L2_b_low	PORTB &=~ (1<<PB7);


#define  step1_y	 y_achse_L1_a_high		y_achse_L1_b_high	y_achse_L2_a_low	y_achse_L2_b_low
#define  step2_y	 y_achse_L1_a_low		y_achse_L1_b_high	y_achse_L2_a_high	y_achse_L2_b_low
#define  step3_y	 y_achse_L1_a_low		y_achse_L1_b_low	y_achse_L2_a_high	y_achse_L2_b_high
#define  step4_y	 y_achse_L1_a_high		y_achse_L1_b_low	y_achse_L2_a_low	y_achse_L2_b_high


//////////////////////////////////////////////////////////////////////////////////////////
//                        defines Z-Achse												//
//////////////////////////////////////////////////////////////////////////////////////////

#define z_achse_L1_a_high	PORTD |=  (1<<PD4);
#define z_achse_L1_a_low	PORTD &=~ (1<<PD4);

#define z_achse_L1_b_high	PORTD |=  (1<<PD5);
#define z_achse_L1_b_low	PORTD &=~ (1<<PD5);

#define z_achse_L2_a_high	PORTD |=  (1<<PD6);
#define z_achse_L2_a_low	PORTD &=~ (1<<PD6);

#define z_achse_L2_b_high	PORTD |=  (1<<PD7);
#define z_achse_L2_b_low	PORTD &=~ (1<<PD7);


#define  step1_z	z_achse_L1_a_high		z_achse_L1_b_high	z_achse_L2_a_low	z_achse_L2_b_low
#define  step2_z	z_achse_L1_a_low		z_achse_L1_b_high	z_achse_L2_a_high	z_achse_L2_b_low
#define  step3_z	z_achse_L1_a_low		z_achse_L1_b_low	z_achse_L2_a_high	z_achse_L2_b_high
#define  step4_z	z_achse_L1_a_high		z_achse_L1_b_low	z_achse_L2_a_low	z_achse_L2_b_high




#endif /* STEPPER_H_ */
