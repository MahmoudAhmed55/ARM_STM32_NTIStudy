/*
 * EXI_Interrupt_Interface.h
 *
 *  Created on: Nov 7, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXI_INTERRUPT_EXI_INTERRUPT_INTERFACE_H_
#define MCAL_EXI_INTERRUPT_EXI_INTERRUPT_INTERFACE_H_


typedef enum
{
	LN0=0,
	LN1,
	LN2,
	LN3,
	LN4,
	LN5,
	LN6,
	LN7,
	LN8,
	LN9,
	LN10,
	LN11,
	LN12,
	LN13,
	LN14,
	LN15,
}Lin_t;

typedef enum
{
	RISING=0,
	FALLING,
	ON_CHANGE
}Mode_t;

void EXI_Init(void);
void EXI_Enable(Lin_t line);
void EXI_Disable(Lin_t line );
void EXI_SoftwareTrigger(Lin_t line);
void EXI_SoftwareTriggerDisable(Lin_t line);
void EXI_SignalLatch(Lin_t line,Mode_t mode);

void EXI_SetCallBack(void(*ptr)(void));
void EXTI0_IRQHandler(void);
#endif /* MCAL_EXI_INTERRUPT_EXI_INTERRUPT_INTERFACE_H_ */

