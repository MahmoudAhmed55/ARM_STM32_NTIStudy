/*
 * SYSTICK_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_


void SYSTICK_Init(void);
void SYSTICK_BusyWait(u32 ticks);
void SYSTICK_IntervalSingle(u32 ticks,void(*ptr)(void));
void SYSTICK_IntervalPeriodic(u32 ticks,void(*ptr)(void));
void SYSTICK_StopTimer(void);
u32 SYSTICK_GetLIpsedTime(void);
u32 SYSTICK_GetRemainingTime(void);


#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
