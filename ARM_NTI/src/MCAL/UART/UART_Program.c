/*
 * UART_Program.c
 *
 *  Created on: Nov 29, 2023
 *      Author: lenovo
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Private.h"

static void(*UART_RX_Fptr)(void)=NULL_PTR;
static void(*UART_TX_Fptr)(void)=NULL_PTR;
void UART_Init(void)
{
	//BAUD RATE:
	USART_BRR=0x341;  //115200 baud rate IS 0X45

	//ENABLE TX:
	SIT_BIT(USART_CR1,3);
	//ENABLE RX:
	SIT_BIT(USART_CR1,2);
	//ENABLE UART:
	SIT_BIT(USART_CR1,13);
	//CLEAR SR_FLAG REGISTER:
	USART_SR=0;

}
void UART_Transmit(char data)
{
	USART_DR= data;
	while(READ_BIT(USART_SR,6)==0); //BUSY WAIT TILL THE TRANSFER DONE
	CLR_BIT(USART_SR,6);
	//CLR_BIT(USART_SR,7);

}
u8 UART_Recieve(void)
{
	return USART_DR;
}



void UART_Send_String(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Transmit(str[i]);
	}

}

void UART_Recive_String(c8*str)
{
	u8 i=0;
	str[0]=UART_Recieve();
	while(str[i]!='#')
	{
		i++;
		str[i]=UART_Recieve();

	}
	str[i]=0;
}
void UART_RX_InterruptEnable(void)
{
	SIT_BIT(USART_CR1,5);
}
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(USART_CR1,5);
}

void UART_TX_InterruptEnable(void)
{
	SIT_BIT(USART_CR1,6);
}
void UART_TX_InterruptDisable(void)
{
	CLR_BIT(USART_CR1,6);
}

void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}


/********** IRQ of UART1 *************/
void USART1_IRQHandler(void)
{

	/*if(UART_TX_Fptr != NULL_PTR)
	{
		UART_TX_Fptr();
	}*/

		UART_RX_Fptr();
	//USART_SR=0;
}
