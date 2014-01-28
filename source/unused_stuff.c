

/////////////////////////////////////////////////////////
//
//	 a file like this shouldnt even exist
//			
//
//////////////////////////////////////////////////////////


/*
 * unused_stuff.c
 *
 * Created: 23.01.2014 11:14:01
 *  Author: Samuel

///////////////////  TEST  //////////////////////////////////////////////////////////////////////////////////////
			
	if (usb_serial_available())
	{
		char input =usb_serial_getchar();
		//usb_serial_putchar(input);
		usb_serial_flush_input();
		uint16_t tmp = 0;
		switch (input)
		{
		case 27: //escape -> bootloader
			usb_send_str("\r\n\t BOOTLOADER");
			bootloader();
			break;
			
		case 'y':
			E6_off;
			enable_stepper;
			usb_send_str("\r\nenable stepper\r\n");
			break;	
			
		case 'w':		
			stepper_x_move(1);//1 step vor
			usb_serial_putchar('^');
			break;
		
		case 's':
			stepper_x_move(-1);//1 step zurück
			usb_serial_putchar('v');
			break;
		
		case 'r':	//114=r  ^=94
				stepper_x_move(200);//200 steps vor (1 umdrehung)
				usb_send_str("(^ 200)");
				break;
		
		case 'f':  //102=f v=118
			stepper_x_move(-200);//200 step zurückr (1umdrehung)
			usb_send_str("(v 200)");
			break;
			
			
		case 'd':		
			stepper_y_move(1);//1 step vor
			usb_serial_putchar('<');
			break;
		
		case 'a':	
			stepper_y_move(-1);//1 step zurück
			usb_serial_putchar('>');
			break;			
			
			
		case 'q':  
			stepper_y_move(-200);//200 step zurückr (1umdrehung)
			usb_send_str("(< 200)");
			break;	
			
		case 'e':  
			stepper_y_move(+200);//200 step zurückr (1umdrehung)
			usb_send_str("(> 200)");
			break;	
						
		case 'o':
			stepper_x_move(200);
			stepper_y_move(200);
			usb_send_str(" \r\n diagonal okay\r\n");	
			break;
			
		case 'p':
			stepper_x_move(-200);
			stepper_y_move(-200);
			usb_send_str("- diagonal okay\r\n");
			break;
		
		case '+':
			stepper_z_move(20);
			break;
			
		case '-':
			stepper_z_move(-20);
			break;
		
		case 'z': //tool stop
			set_tool_speed(0); // wird von den anderern genutzt von 0 bis 1024
			usb_send_str("\r\ntool stop \r\n");
			break;		
		
		case 'i': //initalisier tool (pwm timer starten)
			tool_init ();
			usb_send_str("\r\ntool init done \r\n");
			break;

		case 't': //initalisier tool (pwm timer starten)
			
			tmp = readADC(0);
			set_tool_speed (tmp);
			usb_send_str("\r\ntool speed set to: ");
			usb_send_int(tmp);
			break;		
		
		case 'ß' : //wie ?
		case '?' :
			usb_send_str("  ?  hilft");
		
			usb_send_str("\r\n==================================================\r\n\r\n"
							" Einzelstep: \r\n" 
							"w:\tvor X achse \r\n"
							"s:\tzur\129ck X achse \r\n"
							"a:\tvor Y achse \r\n"
							"d:\tzurück Y achse \r\n\r\n"
							
							" 1 umdrehung step: \r\n"		
							"r:\tvor X achse \r\n"			
							"f:\tzurück X achse \r\n"
							"q:\tvor Y achse \r\n"			
							"e:\tzurück Y achse \r\n\r\n"	
															
							"o:\tvor X+Y achse \r\n"			
							"p:\tzurück X+Y achse \r\n\r\n"
															
							" Tool: \r\n"						
							"t: Set tool speed (poti wert)\r\n"
							"i: init tool (512)\r\n"
							"z: stop tool	\r\n\r\n"		
							
							"y aktiviert die treiber nach notaus\r\n"	
							"ESC: Bootloader \r\n"							
							"?:  hilfe \r\n");							
			break;
			
		default:      // Anweisungen wenn keine der oben definierten Bedingungen erfüllt ist
			usb_send_str("unbekannter befehl  -  ? für hilfe");
			break;
		}
		
		*/
		/*
		if (input==115) //
		{
			usb_send_str((unsigned char *)"\r\n\t clk / 256");
			TCCR1B=0;
			TCCR1B = (1 << WGM12) | (1 << CS12); //prescaler und ctc mode = clk/256
		}

		if (input==116) //t
		{
			usb_send_str((unsigned char *)"\r\n\t  clk /  8");
			TCCR1B=0;
			TCCR1B = (1 << WGM12) | (1 << CS11)| (1 << CS10);//  TCCR1B Prescaler = clk/8, CTC mode
		}

		if (input==117)//u
		{
			usb_send_str((unsigned char *)"\r\n\t clk /  1");
			TCCR1B=0;
			TCCR1B = (1 << WGM12) | (1 << CS10); //prescaler und ctc mode = clk/1
		}
		
		
		if (input==118)//v
		{
			usb_send_str((unsigned char *)"\r\n\t OCR1A = ");
			uint16_t tmp = readADC(0);
			OCR1A = tmp;
			usb_send_int(tmp);
		}
		
		*/
	
	/*	
	}			
	*/			
				
//////////////  TEST ENDE   ///////////////////////////////////////////////////////////////////////////////////////////

