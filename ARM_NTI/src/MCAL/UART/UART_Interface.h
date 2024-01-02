/*
 * UART_Interface.h
 *
 *  Created on: Nov 29, 2023
 *      Author: lenovo
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_Init(void);
void UART_Transmit(char data);
u8 UART_Recieve(void);
u8 UART_RecieveBlocked(void);
void UART_Send_String(c8*str);
void UART_Recive_String(c8*str);
u32 UART_Recive_Number(void);
u32 UART_Recive_Number(void);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));
void USART1_IRQHandler(void);

void UART2_Init(void);
void UART2_Transmit(char data);
u8 UART2_Recieve(void);
u8 UART2_RecieveBlocked(void);
void UART2_RX_InterruptEnable(void);
void UART2_RX_InterruptDisable(void);
void UART2_RX_SetCallBack(void (*LocalFptr)(void));
void USART2_IRQHandler(void);
#endif /* MCAL_UART_UART_INTERFACE_H_ */
