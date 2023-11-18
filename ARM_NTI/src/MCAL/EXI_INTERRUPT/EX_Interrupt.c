/*
 * EX_Interrupt.c
 *
 *  Created on: Nov 7, 2023
 *      Author: lenovo
 */

#include <stdio.h>
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "EXI_Interrupt_Interface.h"
#include "EXI_Interrupt_Private.h"
#include "EXI_Interrupt_Config.h"

static void (*CallBack)(void)=NULL_PTR;

void EXI_Init(void)
{

#if   EXI_MODE==RISING
	SIT_BIT(EXTI_RTSR,EXI_LINE);
#elif EXI_MODE==FALLING
	SIT_BIT(EXTI_FTSR,EXI_LINE);
#elif EXI_MODE==ON_CHANGE
	SIT_BIT(EXTI_RTSR,EXI_LINE);
	SIT_BIT(EXTI_FTSR,EXI_LINE);
#endif

}

void EXI_Enable(Lin_t line)
{
	SIT_BIT(EXTI_IMR,line);
}

void EXI_Disable(Lin_t line )
{
	CLR_BIT(EXTI_IMR,line);
}

void EXI_SoftwareTrigger(Lin_t line)
{
	SIT_BIT(EXTI_SWIER,line);
	CLR_BIT(EXTI_PR,line);
}

void EXI_SoftwareTriggerDisable(Lin_t line)
{
	SIT_BIT(EXTI_PR,line);
}

void EXI_SignalLatch(Lin_t line,Mode_t mode)
{
	switch (mode)
	{
	case RISING:  SIT_BIT(EXTI_RTSR,line);
	break;
	case FALLING: SIT_BIT(EXTI_FTSR,line);
	break;
	case ON_CHANGE:  SIT_BIT(EXTI_RTSR,line);
	SIT_BIT(EXTI_FTSR,line);
	break;
	}
}

void EXI_SetCallBack(void(*ptr)(void))
{
	CallBack=ptr;

}

void EXTI0_IRQHandler(void)
{
	CallBack();

}
