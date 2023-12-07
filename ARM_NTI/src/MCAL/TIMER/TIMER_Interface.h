/*
 * TIMER_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#include "TIMER_Private.h"

typedef enum
{
	RISING_TIMER,
	FALLING_TIMER
}Trig_t;


void TIMER_Init(void);
void TIMER_ICU1Init(void);

void Timer_InputCaptureEdge(Trig_t trig);

void TIMER_ICU1InterruptEnable(void);
void TIMER_ICU1InterruptDisable(void);

void TIMER_SetCallBack(void(*ptr)(void));
void TIM2_IRQHandler(void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
