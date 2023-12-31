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

extern volatile char str[100];
extern volatile u8 i;

void ESP_Init(void)
{
	UART_Send_String("ATE0\r\n");
	SYSTICK_BusyWait_Ms(10);
}

u8 ESP_Get(void)
{
	UART_RX_InterruptEnable();
	UART_Send_String("AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("AT+CIPSEND=55\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
	i=0;
	SYSTICK_BusyWait_Ms(150);

	return str[37];
}

void ESP_Post(c8  data)
{
	u8 arr[8]={'l','e','d','=',data,'\r','\n',0};

	UART_RX_InterruptDisable();
	UART_Send_String("AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("AT+CIPSEND=142\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("POST /script.php HTTP/1.1\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("Host: ntigreaters.scienceontheweb.net\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("Content-Type: application/x-www-form-urlencoded\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("Content-Length: 6\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String("\r\n");
	SYSTICK_BusyWait_Ms(10);
	UART_Send_String(arr);
	SYSTICK_BusyWait_Ms(150);

}

