/*
 * lcd_config.c
 *
 * Created: 4/23/2020 3:29:47 AM
 *  Author: Ahmed
 */ 
#define F_CPU 16000000
#include "lcd_config.h"
#include "lcd_.h"
#include <util/delay.h>
#include <avr/io.h>
void lcd_int_(){
	DDRA=0xff;
	DDRB=0xff;
	clear_bit_(PORTB,RW);
	_delay_ms(8);
	lcd_command_(0x33);
	lcd_command_(0x32);
	lcd_command_(0x28);
	lcd_command_(0x0c);
	lcd_command_(0x06);
	lcd_command_(0x01);
}
