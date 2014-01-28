

shonkyCNC
=========

my cnc project hardware based on TinyMega (aka JockiBoard) und LM293


target was creating a cheap cnc and learning about programming and stuff

Atmel Studio 6 was used to develop this stuff
for everyone who isnt using Atmel Studio Makefile is in source/debug


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
