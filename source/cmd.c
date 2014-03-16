/*
 * cmd.c
 *
 * Created: 22.01.2014 15:33:15
 *  Author: Samuel
 */ 
#include "cmd.h"


bool cmd_mode = false;
bool gcode_mode = false;


void cmd_handler(char command[250])
{
if (gcode_mode==true)
 {
	gcode_handler(command);				
 }
else	//kein g code mode prüfe das command
 {
		
		
	if (strncmp(command,"cmd",3)==0)
	{
		cmd_mode=true;
		usb_send_str("\r\nCommand line mode - OK \r\n");
	}

	if (cmd_mode==true)
	{
	
		if (command[0]=='?' || (strncmp(command,"help",4)==0)  )
			{
			usb_send_str(
			"\r\n A wild help meue apperars -  after i write this thing ...\r\n"
			"uptime \t- zeige uptime\r\n"
			"led on \t- led an\r\n"
			"led off \t- led aus\r\n"
			"movex # \t-  bewegt in x richtung mir (-)# umdrehungen \r\n"
			"movey # \t-  bewegt in y richtung mir (-)# umdrehungen \r\n"
			"movez # \t-  bewegt in z richtung mir (-)# umdrehungen \r\n"
			"temp \t- get temperature (does not work good)\r\n"
			"gcode \t- enter special g code menu\r\n"
			"exit \t- exit comand line mode\r\n"
			"help \t- show help menu\r\n$"
			);	
				
			}
		 else if (strncmp(command,"uptime",6)==0)
			{
			usb_send_str("\r\nuptime:");
			usb_send_int(millis());
			usb_send_str("\r\n$");
			}		 
		 		
		else if (strncmp(command,"led on",6)==0)
			{
			 E6_on;
			 usb_send_str("\r\n led eingeschaltet \r\n$");
			 }
		else if (strncmp(command,"led off",7)==0)
			{
				E6_off;
				usb_send_str("\r\n led ausgeschaltet \r\n$");
			}
			
			
			/////////////////  Rechnung vorschub  movex  //////////////////////////
			//
			//  move x - fräßer in X-Richtung fahren, der wert nach x muss ausgelsen werden
			//  Stepper 1,8° -> 200 Steps pro umdrehung 
			//  1 umdrehung 1mm vorschub    1Step = 0,005mm = 5µm
			//  mm/0,005mm = steps  und   mm*200=steps
			//  vorzeichen ?
			//
			///////////////////////////
			
			//entferne "movex " oder gehe nach das leer
			//prüfe ob nächstes zeichen '-' (oder + wenn kein -) 
			//suche nächstes leer (oder '\0') (nach der zahl)
			//suche nächsten punkt (trennt kommazahlen 5.205 mm)
			//wenn das leer(oder '\0') vor dem punkt liegt -> zhal ist keine kommazahlt  -> atoi
			//wenn das leer(oder '\0') nach dem punkt liegt - als kommazahl einlesen
			
			
			////////////////////  Rechnung / Überlegung Feldlänge Variabelgröße float int ?  //////////////////
			//
			//		68cm		*	60cm		*	20cm
			//		680 mm		*	600 mm		*	200 mm
			//		136.000		*	120.000		*	40.000		Steps
			//	
			//
			//		int16_t			  +/- 32.767	=> 163,835 mm		-> 16 cm
			//		uint16_t    		  65.536	=> 327,67 mm		-> 32 cm
			//
			//		int32_t	   +/- 2.147.483.648	=> 10737418,24 mm	-> 1073741 cm -> 10737 m
			//		uint32_t	   4.294.967.295	=> 21474836,48 mm	-> 2147483 cm -> 21474 m
			//		
			//		
			//////////////////////////////////////////////////////////////////////////////////////////////////////
			
		else if (strncmp(command,"movex ",6)==0)
		{  
			stepper_x_move (  200 *  (atol	(command+6)));
			usb_send_str(" \r\n$");
		 }	
			
		else if (strncmp(command,"movey ",6)==0)
		{
			stepper_y_move (  200 *  (atol	(command+6)));
			usb_send_str(" \r\n$");
		}
		else if (strncmp(command,"movez ",6)==0)
		{
			stepper_z_move (  200 *  (atol	(command+6)));
			usb_send_str(" \r\n$");
		}					
			
		else if (strncmp(command,"temp",4)==0)
		{	
			
			for(uint8_t i =0;i<10;i++){
				sleep_ms(100);
				usb_send_str("\r\n AVR Core Temp:  ");
				usb_send_int( readADC(20)+ 15);
				usb_send_str(" °C");
			}
		usb_send_str("\r\n$");
		}	  
		
		
		  else if (strncmp(command,"gcode",5)==0)
			{
			gcode_mode=true;
			cmd_mode =false;
			usb_send_str("You are in Gcode-Mode now  -  ESC to leave \r\n>");
			}		 
		 	
		 else if (strncmp(command,"exit",4)==0)
			{
			 cmd_mode=false;
			 usb_send_str("\r\n Command line closed");
			 }
		 else if (strncmp(command,"boot",4)==0)
			{
			 usb_send_str("\r\n =========================================================\r\n||\t\t Bootloader mode\t\t\t ||\r\n ========================================================= ");
			 bootloader();
			 }
		else if (strncmp(command,"cmd",3)==0)
			{
			 usb_send_str("\r\n$");
			}	
		 else //unbekanntes commando
			{
			usb_send_str("\r\n unknown command '?' for help\r\n$");
			}	 		
	}
	else //cmd mode ist deaktiviert
	{
		usb_send_str(command);
		usb_send_str("\r\n type 'cmd' to enter command line mode\r\n");
	}
	
 } //else (kein g code)
}//cmd_handler


void gcode_handler(char command[250])
{
	
	// phrase check and execute  g code commands here
	//command planner?




	//das gehört hier spätern nicht her ist aber im moment zum testen einfacher so 	
	// TEST //////////////////////////////////////////////////////////////////////////////////////////////////////////
	uint16_t tmp=0;
	switch (command[0])
	{
		case 27: //escape -> bootloader
			gcode_mode=false;
			cmd_mode = true;
			usb_send_str("\r\nBack to cmd mode\r\n$");
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
		
		case 32: //leer 
		 stepper_x_move(-20000);
		 stepper_y_move(-20000);
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
		"ESC to leave gcode mode"
		"?:  hilfe \r\n");
		break;
		
		default:      // Anweisungen wenn keine der oben definierten Bedingungen erfüllt ist
		usb_send_str("unbekannter befehl  -  ? für hilfe");
		break;
	}
	// ENDE TEST //////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	
	
}