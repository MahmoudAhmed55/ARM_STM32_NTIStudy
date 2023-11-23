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
#include "TIMER_Config.h"

static void (*PTR1)(void)=NULL_PTR;
static void (*PTR2)(void)=NULL_PTR;




void TIMER1_Init(void)
{
	CLR_BIT(TIMER_CR1,DIR);                // UP_COUNTING

	TIMx_PSC=71;                         // prescalLer 1M

	SIT_BIT(TIMER_CR1,7);	                //enable autoreload
	TIMx_ARR=0XFFFF;
	SIT_BIT(TIMER_CR1,CEN);                  // Enable TIMER1
}

void TIMER1_AutoReload(u32 over)
{
	TIMx_ARR=over;        //OVF
	SIT_BIT(TIMER_CR1,7);
}

void TIMER1_ICU1Init(void)
{
	CLR_BIT(TIMER_CR1,CEN);    // Disable TIMER1

	SIT_BIT(TIMx_CCMR1,CC1S); //active ch1 ICU as input
	SIT_BIT(TIMx_CCMR1,1);

	/*SIT_BIT(TIMx_CCMR1,IC1F); //FILTER DURATION 8 SAMPLE
	SIT_BIT(TIMx_CCMR1,5);*/

	CLR_BIT(TIMx_CCMR1,IC1PSC); //no prescalLer,capture is done eachtime an edge is detected on the capture input
	CLR_BIT(TIMx_CCMR1,3);

	CLR_BIT(TIMx_CCER,CC1P);    //RISING EDGE

	SIT_BIT(TIMx_CCER,CC1E);  //ENABLE ICU

	SIT_BIT(TIMER_CR1,CEN);    // Enable TIMER1
}

void TIMER1_ICUI2nit(void)
{
	//TIMER_CR2

	CLR_BIT(TIMER_CR1,CEN);    // Disable TIMER1

	CLR_BIT(TIMER_CR2,7);//CH1 T1 SELECT

	SIT_BIT(TIMx_CCMR1,1); //active ch2 ICU as input

	CLR_BIT(TIMx_CCMR1,IC1PSC); //no prescalLer,capture is done eachtime an edge is detected on the capture input
	CLR_BIT(TIMx_CCMR1,3);

	SIT_BIT(TIMx_CCER,CC1P);    //RISING EDGE

	SIT_BIT(TIMx_CCER,CC1E);  //ENABLE ICU

	SIT_BIT(TIMER_CR1,CEN);    // Enable TIMER1
}

void Timer1_InputCaptureEdge(Trig_t trig)
{
	switch (trig)
	{
	case RISING_TIMER:CLR_BIT(TIMx_CCER,CC1P);              //RISING EDGE
	break;
	case FALLING_TIMER:SIT_BIT(TIMx_CCER,CC1P);             //FALLING EDGE
	break;
	}
}


void TIMER1_InterruptEnable(void)
{
	SIT_BIT(TIMx_DIER,UIE);
}
void TIMER1_InterruptDisable(void)
{
	CLR_BIT(TIMx_DIER,UIE);
}


void TIMER1_ICU1InterruptEnable(void)
{
	SIT_BIT(TIMx_EGR,1);
	SIT_BIT(TIMx_DIER,CC1IE);
	SIT_BIT(TIMx_DIER,UIE);
}
void TIMER1_ICU1InterruptDisable(void)
{
	CLR_BIT(TIMx_EGR,1);
	CLR_BIT(TIMx_DIER,CC1IE);
	CLR_BIT(TIMx_DIER,5);

}


void TIMER1_SetCallBack(void(*ptr)(void))
{
	PTR1=ptr;

}

void TIM1_UP_IRQHandler(void)
{
	PTR1();
	CLR_BIT(TIMx_SR,UIF);
}

void TIMER1_ICUSetCallBack(void(*ptr)(void))
{
	PTR2=ptr;

}

void TIM1_CC_IRQHandler(void)
{
	PTR2();

}
