/*
 * mlx90416.c
 *
 * Created: 7/22/2020 9:11:18 PM
 *  Author: Ahmed EL-Tawab
 */ 
#include "mlx90614.h"
void MLX90614_Init(unsigned char BaudRate)
{
	
	TWBR=BaudRate;	// set Bit rate value
	TWSR=(0<<TWPS1)|(0<<TWPS0);	//set prescalar value
	
	
}
void mlx90614_write(unsigned char slave_add,unsigned char command){
	i2c_start_condition();
	_delay_ms(1);
	i2c_send_address_W(slave_add);
	toggle_bit_(PORTC,2);
	_delay_ms(200);
	_delay_ms(1);
	i2c_send_data(command);
	toggle_bit_(PORTC,2);
	_delay_ms(200);
	_delay_ms(1);
	i2c_start_condition();
	toggle_bit_(PORTC,2);
	_delay_ms(200);
	
}

double mlx90614_read(unsigned char slave_add,unsigned char command){
	double temp;
	unsigned char pec,data_low,data_high;
	i2c_start_condition();
	_delay_ms(1);
	i2c_send_address_W(slave_add|0x00);
	_delay_ms(1);
	i2c_send_data(command);
	_delay_ms(1);
	i2c_repeat_start();
	_delay_ms(1);
	i2c_send_address_R(slave_add|0x01);
	_delay_ms(1);
	data_low=i2c_recieve_Data();
	_delay_ms(1);
	data_high=i2c_recieve_Data();
	_delay_ms(1);
	pec=i2c_recieve_Data();
	_delay_ms(1);
	i2c_stop_condition();
	temp=data_low;
	temp=((data_high<<8)+data_low);
	return temp;
}