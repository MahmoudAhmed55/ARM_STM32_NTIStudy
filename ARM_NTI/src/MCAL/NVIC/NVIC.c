/*
 * NVIC.C
 *
 *  Created on: Nov 6, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

void Interrupt_Set_Enable(Interrupt_t num)
{
	if (num<32)
	{
		SIT_BIT(NVIC_ISER0,num);
	}
	else if (num>31&&num<64)
	{
		num=num-32;
		SIT_BIT(NVIC_ISER1,num);
	}
	/*else if (num>63&&num<68)
	{
		num=num-64;
		SIT_BIT(NVIC_ISER2,num);
	}*/
}

void Interrupt_Clear_Enable(Interrupt_t num)
{
	if (num<32)
	{
		SIT_BIT(NVIC_ICER0,num);
	}
	else if (num>31&&num<64)
	{
		num=num-32;
		SIT_BIT(NVIC_ICER1,num);
	}
	/*else if (num>63&&num<68)
	{
		num=num-64;
		SIT_BIT(NVIC_ICER2,num);
	}*/

}

void Interrupt_Set_Pending(Interrupt_t num)
{
	if (num<32)
	{
		SIT_BIT(NVIC_ISPR0,num);
	}
	else if (num>31&&num<64)
	{
		num=num-32;
		SIT_BIT(NVIC_ISPR1,num);
	}
	/*else if (num>63&&num<68)
	{
		num=num-64;
		SIT_BIT(NVIC_ISPR2,num);
	}*/
}

void Interrupt_Clear_Pending(Interrupt_t num)
{
	if (num<32)
	{
		SIT_BIT(NVIC_ICPR0,num);
	}
	else if (num>31&&num<64)
	{
		num=num-32;
		SIT_BIT(NVIC_ICPR1,num);
	}
	/*else if (num>63&&num<68)
	{
		num=num-64;
		SIT_BIT(NVIC_ICPR2,num);
	}*/
}

u8 Interrupt_Active_Bit(Interrupt_t num)
{
	u8 read=0;
	if (num<32)
	{
		read=READ_BIT(NVIC_IABR0,num);
	}
	else if (num>31&&num<64)
	{
		num=num-32;
		read=READ_BIT(NVIC_IABR1,num);
	}
	/*else if (num>63&&num<68)
	{
		num=num-64;
		read=READ_BIT(NVIC_IABR2,num);
	}*/
	return read;
}

u8 Read_Interrupt_Status(InterruptVariable_t status ,Interrupt_t num)
{
	u8 read=0;
	switch(status)
	{
	case Set_Enable0:
		read=READ_BIT(NVIC_ISER0,num);
		break;
	case Set_Enable1:
		read=READ_BIT(NVIC_ISER1,num);
		break;
	case Set_Enable2:
		read=READ_BIT(NVIC_ISER2,num);
		break;
	case Clear_Enable0:
		read=READ_BIT(NVIC_ICER0,num);
		break;
	case Clear_Enable1:
		read=READ_BIT(NVIC_ICER1,num);
		break;
	case Clear_Enable2:
		read=READ_BIT(NVIC_ICER2,num);
		break;
	case Set_Pending0:
		read=READ_BIT(NVIC_ISPR0,num);
		break;
	case Set_Pending1:
		read=READ_BIT(NVIC_ISPR1,num);
		break;
	case Set_Pending2:
		read=READ_BIT(NVIC_ISPR2,num);
		break;
	case Clear_Pending0:
		read=READ_BIT(NVIC_ICPR0,num);
		break;
	case Clear_Pending1:
		read=READ_BIT(NVIC_ICPR1,num);
		break;
	case Clear_Pending2:
		read=READ_BIT(NVIC_ICPR2,num);
		break;
	case Active_Bit0:
		read=READ_BIT(NVIC_IABR0,num);
		break;
	case Active_Bit1:
		read=READ_BIT(NVIC_IABR1,num);
		break;
	case Active_Bit2:
		read=READ_BIT(NVIC_IABR2,num);
		break;
	}
	return read;
}


void Set_InterruptPriority2(c8 id,u8 group,c8 sub,u32 Priority_Group)
{
	SCB_AIRCR=Priority_Group;
	u8 local_priority= sub | (group<<(Priority_Group-GROUP3)/256);

	// EXI_INTERRUPTSS ONLY
	if (id>=0)
	{
		NVIC_IPR_PTR[id]=(local_priority<<4);
	}
}
