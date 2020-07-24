/*
 * mlx90614.h
 *
 * Created: 7/22/2020 8:47:24 PM
 *  Author: Ahmed EL-Tawab
 */ 


#ifndef MLX90614_H_
#define MLX90614_H_
#define F_CPU	16000000
#include "i2c.h"
#include "bit_math_.h"
#include <util/delay.h>
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
void MLX90614_Init(unsigned char BaudRate);
void mlx90614_write(unsigned char slave_add,unsigned char command);
double mlx90614_read(unsigned char slave_add,unsigned char command);
#endif /* MLX90614_H_ */