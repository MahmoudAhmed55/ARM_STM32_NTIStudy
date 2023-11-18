/*
 * EXI_Interrupt_Private.h
 *
 *  Created on: Nov 7, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXI_INTERRUPT_EXI_INTERRUPT_PRIVATE_H_
#define MCAL_EXI_INTERRUPT_EXI_INTERRUPT_PRIVATE_H_

#define   EXI_BASEADDRESS      (0x40010400)

#define EXTI_IMR                     *((volatile u32*) (EXI_BASEADDRESS +0x00))
#define EXTI_EMR                     *((volatile u32*) (EXI_BASEADDRESS +0x04))
#define EXTI_RTSR                    *((volatile u32*) (EXI_BASEADDRESS +0x08))
#define EXTI_FTSR                    *((volatile u32*) (EXI_BASEADDRESS +0x0C))
#define EXTI_SWIER                   *((volatile u32*) (EXI_BASEADDRESS +0x10))
#define EXTI_PR                      *((volatile u32*) (EXI_BASEADDRESS +0x14))




#define RISING        0
#define FALLING       1
#define ON_CHANGE     2

#define LINE0         0
#define LINE1         1
#define LINE2         2
#define LINE3         3
#define LINE4         4
#define LINE5         5
#define LINE6         6
#define LINE7         7
#define LINE8         8
#define LINE9         9
#define LINE10         10
#define LINE11         11
#define LINE12         12
#define LINE13         13
#define LINE14         14
#define LINE15         15


#endif /* MCAL_EXI_INTERRUPT_EXI_INTERRUPT_PRIVATE_H_ */
