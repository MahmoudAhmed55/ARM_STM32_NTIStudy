/*
 * Timer_Program.c
 *
 *  Created on: Nov 17, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "TIMER_Interface.h"
#include "TIMER_Private.h"
//#include "TIMER_Config.h"

static void (*PTR1)(void)=NULL_PTR;
void TIMER_Init(void)
{
	CLR_BIT(TIMER_CR1,DIR);  // UP_COUNTING

	TIMx_PSC=36;          // prescaler 1M

	TIMx_ARR=20000;        //OVF

	SIT_BIT(TIMER_CR1,CEN);  // UP_COUNTING
}

void TIMER_InterruptEnable(void)
{
	SIT_BIT(TIMx_DIER,UIE);
}
void TIMER_InterruptDisable(void)
{
	CLR_BIT(TIMx_DIER,UIE);
}

void TIMER1_SetCallBack(void(*ptr)(void))
{
	PTR1=ptr;

}

void TIM1_UP_TM10_IRQHandler(void)
{

	PTR1();
	CLR_BIT(TIMx_SR,UIF);
}
