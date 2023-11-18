/*
 * TIMER_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_



void TIMER_Init(void);

void TIMER_InterruptEnable(void);
void TIMER_InterruptDisable(void);
void TIMER1_SetCallBack(void(*ptr)(void));
void TIMER1_IRQHandler(void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
