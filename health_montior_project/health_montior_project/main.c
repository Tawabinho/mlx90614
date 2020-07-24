/*
 * health_montior_project.c
 *
 * Created: 7/22/2020 8:42:04 PM
 * Author : Ahmed EL-Tawab
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "mlx90614.h"
#include "lcd_.h"
#include "lcd_config.h"
#include "i2c.h"
void convert(unsigned int data){
		lcd_char_( (data/10000)+0x30 );
		lcd_char_( ((data/1000)%10)+0x30 );
		lcd_char_( ((data/100)%10)+0x30 );
		lcd_char_('.');
		lcd_char_( ((data/10)%10)+0x30 );
}
int main(void)
{
	i2c_int();
	DDRC|=(1<<2);
	DDRC|=(1<<0);
	DDRC|=(1<<1);
	double temp;
    lcd_int_();
	MLX90614_Init(0x48);
	_delay_ms(10);
	lcd_command_(0x80);
	lcd_string_("hello");
	_delay_ms(1000);
	lcd_clear();
	mlx90614_write(0x5A,0x07);
    while (1) 
    {
		temp=mlx90614_read(0x5A,0x07);
		toggle_bit_(PORTC,2);
		_delay_ms(200);
		_delay_ms(20);
		temp*=0.02;
		temp-=273.15;
		temp*=100;
		lcd_command_(0x80);
		lcd_string_("the temp= ");
		lcd_command_(0xc0);
		convert(temp);
    }
}

