/*
 * tool.h
 * Created: 08.01.2014 16:55:35
 *  Author: Samuel
 */ 
#ifndef TOOL_H_
#define TOOL_H_

#include <avr/io.h>
#include <stdbool.h>


void tool_init (void);
void set_tool_speed (uint16_t speed);// wird von den anderern genutzt von 0 bis 1024



void setPeriod(unsigned long freq);
void enable_intr(void);
void disable_intr(void);
void initialize(unsigned long freq); 
void setPwmDuty(unsigned int duty);
void start(void);
void stop(void);
void setPeriod(unsigned long freq);



#endif /* TOOL_H_ */