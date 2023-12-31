/*
 * BIT_MATH.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


#define SIT_BIT(REG,BIT)   (REG=(REG|(1<<BIT)))
#define CLR_BIT(REG,BIT)   (REG=(REG&(~(1<<BIT))))
#define TOG_BIT(REG,BIT)   (REG=(REG^(1<<BIT)))
#define READ_BIT(REG,BIT)  (1&(REG>>BIT))


#endif
