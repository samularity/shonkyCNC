//===============================acd.c==============================================
#include "adc.h"

uint16_t readADC( uint8_t adc_channel)
{
	uint32_t adc_Value = 0;
	
	// ADC deactivate
	ADCSRA &= ~(1<<ADEN);
	ADCSRA &= ~(1<<ADSC);

	switch (adc_channel) //choose adc channel
	{
		case 0:  adc_ch0; break;
		case 1:  adc_ch1; break;
		case 4:  adc_ch4; break;
		case 5:  adc_ch5; break;
		case 6:  adc_ch6; break;
		case 7:  adc_ch7; break;
		case 8:  adc_ch8; break;
		case 9:  adc_ch9; break;
		case 10:  adc_ch10; break;
		case 11:  adc_ch11; break;
		case 12:  adc_ch12; break;
		case 13:  adc_ch13; break;
		case 20: adc_temp; break;
		default:  {return (0);}	//error
	}

	ADCSRA |= (1<<ADEN); // ADC on
	ADCSRA |= (1<<ADSC); // and init
	while(ADCSRA & (1 << ADSC)); //test empty measurement

	//delete measurement value
	ADCH = 0x00;
	ADCL = 0x00;

	// choose average
	for (uint8_t g = 0; g < 4; g++) {
		ADCSRA |= (1<<ADSC); //start measurment
		while(ADCSRA & (1 << ADSC)); // wait for finish
		adc_Value = adc_Value + ( ADC ); // save
	}
	adc_Value = adc_Value /4 ; //divide by 4

	return adc_Value;
}

void adc_init () // adc init
{
	//choose internal_vref or external_vref here (definded im macros adc.h)
	//internal_vref   
	external_vref //use external Vref
	
	DDRF &= ~(( 1 << PF0 )|( 1 << PF1 ))   ;  // PIN F0 and F1 as input 
	ADMUX &= ~(1<<ADLAR); //auf oder abrunden
	adc_temp //choose channel for first empty measurment
	ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)); //Prescaler  125KHz
	ADCSRA &= ~(1<<ADATE); //no trigger mode
	ADCSRB |= (1<<ADHSM);//high speed mode
	ADCSRA |= (1<<ADEN); //turn on
	ADCSRA |= (1<<ADSC); //init
	while(ADCSRA & (1 << ADSC)); //empty test measurment
}

