/*
 * bit_math_.h
 *
 * Created: 4/22/2020 10:16:09 PM
 *  Author: Ahmed
 */ 


#ifndef BIT_MATH__H_
#define BIT_MATH__H_
#define set_bit_(var,bit)			var|= (1<<bit)
#define clear_bit_(var,bit)			var&=~(1<<bit)
#define toggle_bit_(var,bit)		var^=(1<<bit)
#define get_bit_(var,bit)			((var>>bit)&1)
#endif /* BIT_MATH__H_ */