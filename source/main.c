/*
 * Created: 30.10.2013 22:08:51
 *  Author: Samuel Munz
 */ 

/*////////////////////////////////////////////////////////////////////////////////////////////////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PinOut TinyMega (aka JockiBoard)  :	http://shackspace.de/wiki/doku.php?id=project:tinymega

USB-Serial Device with command line

B0,1,2,3 Driver X Axis
B4,5,6,7 Driver Y Axis
C6:		Enable/Disable Drivers
C7:		PWM out for Tool
D3:		Seriell_TX
D4,5,6,7 Driver Z Axis
D2:		Seriall_RX
F0:		General Analog Input for Toolspeed etc.
F1:		Switch Matrix Analog input

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*/////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "main.h"

ISR(INT0_vect) 
	{
	// interrupt code goes here	
	disable_stepper;
	set_tool_speed(0);//stop tool
	steps_x=steps_y=steps_z=0; //fahr nirgens hin
	//usb_send_str("NOTAUS\r\n");	
	E6_on;
	get_switch();
	}

int main(void)
{
	clock_prescale_set(clock_div_1);	//clock prescaler auf  1 =>  16MHz
	MCUCR = (1 << JTD);					//jtag ausschalten
	MCUCR = (1 << JTD);					//this need to be executed twice 
	
	DDRE|=(1 << PE6); //debug led als ausgang
	DDRB = 0xff;//alle als ausgang zu treibern x+y
	DDRD |= (1 << DDD4) | (1 << DDD5)| (1 << DDD6)| (1 << DDD7); //ausg�nge f�r z achse
	
	DDRC |= (1 << DDC7) ; //Pin C7 als PWM ausgang
	DDRC |= (1 << DDC6) ; //Pin C6 als ENABLE/DISLABLE Stepper an L293D
	
	
	
	adc_init();	//external_vref // siehe adc.h
	usb_init(); 
	timer_init();
	sleep_ms(250);
	
	enable_stepper;
	//interupt0 test
	DDRD &= ~(1 << DDD0); // pin d0 als eingang (interrupt notaus)
	PORTD |= (1 << PD0); // pullup aktiviern
	EICRA &= ~(  (1<<ISC00) | (1<<ISC01)  ); // sets the interrupt type bei low interrupt ausl�sen
	sleep_ms(10);
	EIMSK |= (1<<INT0); // activiern des interrupts
	sleep_ms(10);
	char inputbuffer[250]={0};
	uint16_t counter = 0;
	
 while(1)   
 {
	if (usb_serial_available())
	 {
	  inputbuffer[counter]= usb_serial_getchar();
	  usb_serial_putchar(inputbuffer[counter]);
	  usb_serial_flush_input();
	  counter++;
	  if (inputbuffer[counter-1]==127)// 127 = del-?  console sagt 127=backspace  auf jeden fall löschen...
	  {
			if (counter>1)//counter is mind 2 D delete 2 chars from string
			{
				counter-=2; //set couter postion -2  (1 for char to delet an one for delet char)
			}
			else
			{
				counter=0;
			}
	  }
	  
	  if ( (counter>= 20) || (inputbuffer[counter-1]==13) ) //sind 20 zeichern erreicht oder enter ger�ckt
	   {
		 inputbuffer[counter-1]='\0'; //enter entfernen und string terminieren
		 cmd_handler(inputbuffer);
		 memset	(&inputbuffer,0,250);//memset fills array &inputbuffer with 0's
		counter =0; //z�hler zur�cksetzten string soll wieder ab 0 gef�llt werden
		}//if stringende 
	  }//if usbserial availab�le						
    }//while 1
}//main




void sleep_us(uint16_t us){
	while(us){
		us--;
		_delay_us(1);
	}
}

void sleep_ms(uint16_t ms){
	while(ms){
		ms--;
		_delay_ms(1);
	}
}

void bootloader (void)
{
	MCUCR  |=  (1 << IVCE);  //IVCE  = 1		//register f�r restret
	MCUCR  |=  (1 << IVSEL); //IVSEL = 1		//register f�r restret
	TIMSK0 = 0;             //Timer-Interrupt ausschalten
	TIMSK1 = 0;				//noch ein Timer-Interrupt ausschalten
	TIMSK4 = 0;				//und noch einer
	sleep_ms(500);
	asm volatile ("jmp 0x3800");
}


uint8_t get_switch(void) //lese adc und ermittle welche taste ger�ckt wurde
{
	uint16_t input = readADC(1);
/*
ADC-Values for 7 switches
71	195
201	325
327	450
451	555
556	680
681	810
811	933
*/
		if (input>= 67 && input <= 195) //200 bis 600
			{usb_send_str("\r\nbutton 1");return 1;}	
		else if (input>= 201 && input <= 325) //601 bis 750
			{usb_send_str("\r\nbutton 2");return 2;}
		else if (input>= 327 && input <= 450) //751 bis 1024
			{usb_send_str("\r\nbutton 3");return 3;}
		else if (input>= 451 && input <= 555) //751 bis 1024
			{usb_send_str("\r\nbutton 4");return 4;}
		else if (input>= 556 && input <= 680) //751 bis 1024
			{usb_send_str("\r\nbutton 5");return 5;}
		else if (input>= 681 && input <= 810) //751 bis 1024
			{usb_send_str("\r\nbutton 6");return 6;}
		else if (input>= 811 && input <= 933) //751 bis 1024
			{usb_send_str("\r\nbutton 7");return 7;}									
				
				
		else
			{usb_send_str("\r\nunable to read button");return 0;}

}



