/*
 * i2c.c
 *
 * Created: 7/20/2020 9:04:27 PM
 *  Author: Ahmed EL-Tawab
 */ 
#include "i2c.h"
void i2c_int(){
	TWBR=0x00;
	TWBR=0x48;
}
void i2c_start_condition(){
	TWCR|=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x08);
}
void i2c_send_address_W(unsigned char address){
	TWDR=address;
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	while((TWSR&0xf8)!=0x18);
}
void i2c_send_data(unsigned char data){
	TWDR=data;
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x28);
}
void i2c_repeat_start(){
	TWCR|=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x10);	
}
void i2c_send_address_R(unsigned char address){
	TWDR=address;
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x40);
}
unsigned char i2c_recieve_Data(){
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x50);
	return TWDR;
}
unsigned char i2c_recieve_pec(){
	TWCR|=(1<<TWEN)|(1<<TWINT);
	while(get_bit_(TWCR,TWINT)==0);
	while((TWSR&0xf8)!=0x58);
	return TWDR;
}
void i2c_stop_condition(){
	TWCR|=(1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
}