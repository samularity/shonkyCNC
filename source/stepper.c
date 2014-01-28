/*
 * stepper.c
 *
 * Created: 19.12.2013 10:57:21
 *  Author: Samuel
 */ 
#include "main.h"

uint8_t stepper_x_pos = 1 , stepper_y_pos = 1, stepper_z_pos = 1 ;
int32_t steps_x=0, steps_y=0, steps_z=0;

//////////////////////////////////////////////////////////////////////////////////////
//								X-Achse												//
//////////////////////////////////////////////////////////////////////////////////////
void stepper_x_forward (void)  // char stepper = x, y oder z
{
			//stepper_x_pos ist momentane real position des stepper
			//abhängig von der realposition den nächsten schritt vorwärts ermitteln 
			 switch (stepper_x_pos)  
			 {
				 case 1: //position ist 1 soll-schritt ist 2
				 {step2_x  stepper_x_pos++; break;}
				 case 2://position ist 2 soll-schritt ist 3
				 {step3_x  stepper_x_pos++; break;}
				 case 3://position ist 3 soll-schritt ist 4
				 {step4_x  stepper_x_pos++; break;}
				 case 4://position ist 4 soll-schritt ist 1
				 {step1_x stepper_x_pos=1; break;}
				 default:
				 break;
			 }
}

void stepper_x_backward (void) //  stepper x    1 step rückwerts
{
	//stepper_x_pos ist momentane real position des stepper
	//abhängig von der realposition den nächsten schritt vorwärts ermitteln
	switch (stepper_x_pos)
	{
		case 1: //position ist 1 soll-schritt ist 4
		{step4_x  stepper_x_pos=4; break;}
		case 2://position ist 2 soll-schritt ist 1
		{step1_x  stepper_x_pos--; break;}
		case 3://position ist 3 soll-schritt ist 2
		{step2_x  stepper_x_pos--; break;}
		case 4://position ist 4 soll-schritt ist 3
		{step3_x stepper_x_pos--; break;}
		default:
		break;
	}
}

void stepper_x_move (int32_t steps) // +32767 bis -32768  steps
{
	steps_x +=  steps; //sollschritte zu akutuelle schritte dazu addieren
}





//////////////////////////////////////////////////////////////////////////////////////
//								Y-Achse												//
//////////////////////////////////////////////////////////////////////////////////////



void stepper_y_forward (void)  // char stepper = x, y oder z
{
	//stepper_x_pos ist momentane real position des stepper
	//abhängig von der realposition den nächsten schritt vorwärts ermitteln
	switch (stepper_y_pos)
	{
		case 1: //position ist 1 soll-schritt ist 2
		{step2_y  stepper_y_pos++; break;}
		case 2://position ist 2 soll-schritt ist 3
		{step3_y  stepper_y_pos++; break;}
		case 3://position ist 3 soll-schritt ist 4
		{step4_y  stepper_y_pos++; break;}
		case 4://position ist 4 soll-schritt ist 1
		{step1_y stepper_y_pos=1; break;}
		default:
		break;
	}
}
void stepper_y_backward (void) //  stepper x    1 step rückwerts
{
	//stepper_x_pos ist momentane real position des stepper
	//abhängig von der realposition den nächsten schritt vorwärts ermitteln
	switch (stepper_y_pos)
	{
		case 1: //position ist 1 soll-schritt ist 4
		{step4_y  stepper_y_pos=4; break;}
		case 2://position ist 2 soll-schritt ist 1
		{step1_y  stepper_y_pos--; break;}
		case 3://position ist 3 soll-schritt ist 2
		{step2_y  stepper_y_pos--; break;}
		case 4://position ist 4 soll-schritt ist 3
		{step3_y stepper_y_pos--; break;}
		default:
		break;
	}
}

void stepper_y_move (int32_t steps) // +32767 bis -32768  steps
{
	steps_y +=  steps; //sollschritte zu akutuelle schritte dazu addieren
}



//////////////////////////////////////////////////////////////////////////////////////
//								Z-Achse												//
//////////////////////////////////////////////////////////////////////////////////////



void stepper_z_forward (void)  // char stepper = x, y oder z
{
	//stepper_x_pos ist momentane real position des stepper
	//abhängig von der realposition den nächsten schritt vorwärts ermitteln
	switch (stepper_z_pos)
	{
		case 1: //position ist 1 soll-schritt ist 2
		{step2_z  stepper_z_pos++; break;}
		case 2://position ist 2 soll-schritt ist 3
		{step3_z  stepper_z_pos++; break;}
		case 3://position ist 3 soll-schritt ist 4
		{step4_z  stepper_z_pos++; break;}
		case 4://position ist 4 soll-schritt ist 1
		{step1_z stepper_z_pos=1; break;}
		default:
		break;
	}
}
void stepper_z_backward (void) //  stepper x    1 step rückwerts
{
	//stepper_x_pos ist momentane real position des stepper
	//abhängig von der realposition den nächsten schritt vorwärts ermitteln
	switch (stepper_y_pos)
	{
		case 1: //position ist 1 soll-schritt ist 4
		{step4_z  stepper_z_pos=4; break;}
		case 2://position ist 2 soll-schritt ist 1
		{step1_z  stepper_z_pos--; break;}
		case 3://position ist 3 soll-schritt ist 2
		{step2_z  stepper_z_pos--; break;}
		case 4://position ist 4 soll-schritt ist 3
		{step3_z stepper_z_pos--; break;}
		default:
		break;
	}
}

void stepper_z_move (int32_t steps) // +32767 bis -32768  steps
{
	steps_z +=  steps; //sollschritte zu akutuelle schritte dazu addieren
}
