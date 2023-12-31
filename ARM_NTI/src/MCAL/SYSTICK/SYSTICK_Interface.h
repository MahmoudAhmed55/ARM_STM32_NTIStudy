/*
 * SYSTICK_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_


void SYSTICK_Init(void);

void SYSTICK_BusyWait_Us(u32 ticks);
void SYSTICK_BusyWait_Ms(u64 ticks);

void SYSTICK_StopTimer(void);
u32 SYSTICK_GetLIpsedTime(void);
u32 SYSTICK_GetRemainingTime(void);

void SYSTICK_InterruptEnable(void);
void SYSTICK_InterruptDisable(void);
void SYSTICK_IntervalSingle(u32 ticks,void(*ptr)(void));
void SYSTICK_IntervalPeriodic(u32 ticks,void(*ptr)(void));
void SysTick_Handler(void);

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
