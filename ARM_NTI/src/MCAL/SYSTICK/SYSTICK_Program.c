/*
 * SYSTICK_Program.c
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "SYSTICK_Interface.h"
#include "SYSTIC_Private.h"

static void (*PTR)(void)=NULL_PTR;

void SYSTICK_Init(void)
{

	CLR_BIT(STK_CTRL,2);    /* IF SIT CLOCK=AHB ,IF CLR CLOCK=AHB/8*/
}


void SYSTICK_BusyWait_Us(u32 ticks)
{

	    STK_LOAD=ticks;
		SIT_BIT(STK_CTRL,0);
		while (READ_BIT(STK_CTRL,16)==0);
		CLR_BIT(STK_CTRL,0);
		STK_LOAD=0;
		STK_VAL=0;
}

void SYSTICK_BusyWait_Ms(u64 ticks)
{
	STK_LOAD=0;
	STK_VAL=0;
	ticks=ticks*1000;
	STK_LOAD=ticks;
	SIT_BIT(STK_CTRL,0);
	while (READ_BIT(STK_CTRL,16)==0);
	CLR_BIT(STK_CTRL,0);
	STK_LOAD=0;
	STK_VAL=0;
}

void SYSTICK_StopTimer(void)
{
	CLR_BIT(STK_CTRL,0);
}



u32 SYSTICK_GetLIpsedTime(void)
{
	return (STK_LOAD- STK_VAL);
}

u32 SYSTICK_GetRemainingTime(void)
{
	return STK_VAL;
}

void SYSTICK_InterruptEnable(void)
{
	SIT_BIT(STK_CTRL,1);  //SYSTICK_INTERRUPT
}
void SYSTICK_InterruptDisable(void)
{
	CLR_BIT(STK_CTRL,1);
}

void SYSTICK_IntervalSingle(u32 ticks,void(*ptr)(void))
{
	STK_LOAD=ticks;
	PTR=ptr;
	if(READ_BIT(STK_CTRL,16))
	{
		STK_LOAD=0;
		STK_VAL=0;
	}
}
void SYSTICK_IntervalPeriodic(u32 ticks,void(*ptr)(void))
{
	STK_LOAD=ticks;
	PTR=ptr;
}

void SysTick_Handler(void)
{
	PTR();
}
