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
	CLR_BIT(TIMER_CR1,DIR);                // UP_COUNTING

	TIMx_PSC=7;                         // prescalLer 1M
	TIMx_ARR=65535;
	SIT_BIT(TIMER_CR1,APPE);
	SIT_BIT(TIMx_EGR,0);
	SIT_BIT(TIMER_CR1,CEN);                  // Enable TIMER1
}


/*WHEN CAPTURE  CCXIF flag (TIMx_SR register) is set CCxOF ALSO
 * e TIMx_CCR1 register becomes read-only.
 * CC1IF flag is set &&CC1OF is also set if at least two consecutive captures
 */
void TIMER_ICU1Init(void)
{

	SIT_BIT(TIMx_CCMR1,CC1S);        //active ch1 ICU as input

	CLR_BIT(TIMx_CCER,CC1P);         //RISING EDGE

	CLR_BIT(TIMx_CCMR1,IC1PSC);    //no prescalLer,capture is done eachtime an edge is detected on the capture input
	CLR_BIT(TIMx_CCMR1,3);

	SIT_BIT(TIMx_CCER,CC1E);  //ENABLE ICU


}



void Timer_InputCaptureEdge(Trig_t trig)
{
	switch (trig)
	{
	case RISING_TIMER:CLR_BIT(TIMx_CCER,CC1P);              //RISING EDGE
	break;
	case FALLING_TIMER:SIT_BIT(TIMx_CCER,CC1P);             //FALLING EDGE
	break;
	}
}

/*The current value of the counter is captured in TIMx_CCR1 register. The CC1IF flag is set,
the corresponding interrupt or DMA request is sent if enabled. The CC1OF flag is set if the
CC1IF flag was already high.*/
void TIMER_ICU1InterruptEnable(void)
{

	SIT_BIT(TIMx_EGR,1);
	SIT_BIT(TIMx_DIER,CC1IE); // RELATED INTURREPUT
	SIT_BIT(TIMx_DIER,0);

}
void TIMER_ICU1InterruptDisable(void)
{
	CLR_BIT(TIMx_EGR,1);
	CLR_BIT(TIMx_DIER,CC1IE);
	CLR_BIT(TIMx_DIER,0);



}


void TIMER_SetCallBack(void(*ptr)(void))
{
	PTR1=ptr;

}

void TIM2_IRQHandler(void)
{
	TIMx_SR=0;
	PTR1();
}
