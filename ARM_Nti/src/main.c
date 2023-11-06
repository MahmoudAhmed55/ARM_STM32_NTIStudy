/*
 * main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mahmoud Ahmed Ismail
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"

#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"

void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
    DIO_Init();
    Pin_t i;

    while (1)
    {
    	for (i=PINA0;i<35;i++)
    	{
    		 GPIO_SetPinValue(i,HIGH);
    		 for(u16 i=0;i<500;i++);
    	}

    	for (i=PINA0;i<35;i++)
    	   {
    	     GPIO_SetPinValue(i,LOW);
    	     for(u16 i=0;i<500;i++);
    	    }

    }



}


