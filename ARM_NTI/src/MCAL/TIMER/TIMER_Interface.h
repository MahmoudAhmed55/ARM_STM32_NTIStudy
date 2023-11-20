/*
 * TIMER_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum
{
	RISING_TIMER,
	FALLING_TIMER
}Trig_t;
void TIMER1_Init(void);
void TIMER1_AutoReload(u32 over);
void TIMER1_ICUInit(void);
void Timer1_InputCaptureEdge(Trig_t trig);
void _delay_ms(u32 ticks);
void TIMER1_InterruptEnable(void);
void TIMER1_InterruptDisable(void);
void TIMER1_SetCallBack(void(*ptr)(void));
void TIM1_UP_IRQHandler(void);

void TIMER_ICU1InterruptEnable(void);
void TIMER_ICU1InterruptDisable(void);
void TIMER1_ICUSetCallBack(void(*ptr)(void));
void TIM1_CC_IRQHandler(void);
#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */