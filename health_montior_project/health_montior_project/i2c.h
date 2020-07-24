/*
 * i2c.h
 *
 * Created: 7/20/2020 9:04:16 PM
 *  Author: Ahmed EL-Tawab
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>
#define F_CPU	16000000
#include "bit_math_.h"
#include <util/delay.h>
void i2c_int();
void i2c_start_condition();
void i2c_send_address_W(unsigned char address);
void i2c_send_address_R(unsigned char address);
void i2c_send_data(unsigned char data);
void i2c_repeat_start();
unsigned char i2c_recieve_Data();
unsigned char i2c_recieve_pec();
void i2c_stop_condition();
#endif /* I2C_H_ */