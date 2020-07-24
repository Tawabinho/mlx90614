/*
 * lcd_.h
 *
 * Created: 4/23/2020 2:38:20 AM
 *  Author: Ahmed
 */ 


#ifndef LCD__H_
#define LCD__H_
#include "lcd_config.h"
#include "bit_math_.h"
void lcd_command_(char cmd);
void lcd_char_(char data);
void lcd_string_(char *str);
void lcd_clear();
void dec_to_ascii(unsigned int dec);
#endif /* LCD__H_ */