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
static void(*UART2_RX_Fptr)(void)=NULL_PTR;
void UART_Init(void)
{
	//BAUD RATE:
	USART_BRR=0x341;  //115200 baud rate IS 0X45   9600 baud rate is 0x341

	//ENABLE TX:
	SIT_BIT(USART_CR1,3);
	//ENABLE RX:
	SIT_BIT(USART_CR1,2);
	//ENABLE UART:
	SIT_BIT(USART_CR1,13);
	//CLEAR SR_FLAG REGISTER:
	USART_SR=0;

}
void UART2_Init(void)
{
	//BAUD RATE:
	USART2_BRR=0x341;  //115200 baud rate IS 0X45   9600 baud rate is 0x341

	//ENABLE TX:
	SIT_BIT(USART2_CR1,3);
	//ENABLE RX:
	SIT_BIT(USART2_CR1,2);
	//ENABLE UART:
	SIT_BIT(USART2_CR1,13);
	//CLEAR SR_FLAG REGISTER:
	USART2_SR=0;

}


void UART_Transmit(char data)
{
	USART_DR= data;
	while(READ_BIT(USART_SR,6)==0); //BUSY WAIT TILL THE TRANSFER DONE
	CLR_BIT(USART_SR,6);
	//CLR_BIT(USART_SR,7);

}

void UART2_Transmit(char data)
{
	USART2_DR= data;
	while(READ_BIT(USART2_SR,6)==0); //BUSY WAIT TILL THE TRANSFER DONE
	CLR_BIT(USART2_SR,6);
	//CLR_BIT(USART_SR,7);

}
u8 UART_Recieve(void)
{
	return USART_DR;
}

u8 UART2_Recieve(void)
{
	return USART2_DR;
}

u8 UART_RecieveBlocked(void)
{
	while(READ_BIT(USART_SR,5)==0);
	return USART_DR;
}

u8 UART2_RecieveBlocked(void)
{
	while(READ_BIT(USART2_SR,5)==0);
	return USART2_DR;
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
void UART_Send_Number(u32 num)
{
	UART_Transmit((u8)num);
	UART_Transmit((u8)(num>>8));
	UART_Transmit((u8)(num>>16));
	UART_Transmit((u8)(num>>24));

}
u32 UART_Recive_Number(void)
{
	u8 b0=UART_Recieve();
	u8 b1=UART_Recieve();
	u8 b2=UART_Recieve();
	u8 b3=UART_Recieve();

	u32 num=(u32)b0|(u32)b1<<8 |(u32)b2<<16|(u32)b3<<24;
	return num;

}
void UART_RX_InterruptEnable(void)
{
	SIT_BIT(USART_CR1,5);
}
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(USART_CR1,5);
}

void UART2_RX_InterruptEnable(void)
{
	SIT_BIT(USART2_CR1,5);
}
void UART2_RX_InterruptDisable(void)
{
	CLR_BIT(USART2_CR1,5);
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

void UART2_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART2_RX_Fptr = LocalFptr;
}


/********** IRQ of UART1 *************/
void USART1_IRQHandler(void)
{


	if(UART_RX_Fptr != NULL_PTR)
	{
		UART_RX_Fptr();
	}
}

/********** IRQ of UART2 *************/
void USART2_IRQHandler(void)
{

	if(UART2_RX_Fptr != NULL_PTR)
	{
		UART2_RX_Fptr();
	}
}
