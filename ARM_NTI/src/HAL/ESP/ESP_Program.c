/*
 * ESP_Program.c
 *
 *  Created on: Nov 30, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

#include"ESP_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"

void ESP_Init(void)
{
	//ECHO_DISABLE:
	UART_Send_String("ATE0\r\n");

	//DELAY FOR OK ESP:
	SYSTICK_BusyWait_Ms(2000);

	//ENABLE ESP STATION MODE :
	UART_Send_String("AT+CWMODE=1\r\n");

	//DELAY FOR OK ESP:
	SYSTICK_BusyWait_Ms(2000);

}

void ESP_Connect(void)
{
	UART_Send_String("AT+CWJAP_CUR=M&S,Ms01551320444@\r\n");
}





