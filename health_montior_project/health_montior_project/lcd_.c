/*
 * lcd_.c
 *
 * Created: 4/23/2020 2:38:39 AM
 *  Author: Ahmed
 */ 
#define F_CPU 16000000
#include "lcd_.h"
#include <util/delay.h>
#include <avr/io.h>
void lcd_command_(char cmd){
	PORTA=(PORTA & 0x0F)|(cmd & 0xF0);
	clear_bit_(PORTB,RS);
	set_bit_(PORTB,EN);
	_delay_ms(2);
	clear_bit_(PORTB,EN);
	_delay_ms(3);
	PORTA=(PORTA & 0x0F)|(cmd << 4);
	set_bit_(PORTB,EN);
	_delay_ms(2);
	clear_bit_(PORTB,EN);
	_delay_ms(3);
}
void lcd_char_(char data){
	PORTA=(PORTA & 0x0F)|(data & 0xF0);
	set_bit_(PORTB,RS);
	set_bit_(PORTB,EN);
	_delay_ms(2);
	clear_bit_(PORTB,EN);
	_delay_ms(3);
	PORTA=(PORTA & 0x0F)|(data << 4);
	set_bit_(PORTB,EN);
	_delay_ms(2);
	clear_bit_(PORTB,EN);
	_delay_ms(3);
}
void lcd_string_(char *str){
	while( *str != '\0'){
		
		lcd_char_(*str);
		str++;
	}
}
void lcd_clear(){
	lcd_command_(0x01);
	_delay_ms(2);
	lcd_command_(0x80);
}