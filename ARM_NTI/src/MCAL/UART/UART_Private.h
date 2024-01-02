/*
 * UART_Private.h
 *
 *  Created on: Nov 29, 2023
 *      Author: lenovo
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UART_BASEADDRESS                  (0x40013800)

#define USART_SR                         (*((volatile u32*)(UART_BASEADDRESS +0x00)))
#define USART_DR                         (*((volatile u32*)(UART_BASEADDRESS +0x04)))
#define USART_BRR                        (*((volatile u32*)(UART_BASEADDRESS +0x08)))
#define USART_CR1                        (*((volatile u32*)(UART_BASEADDRESS +0x0C)))
#define USART_CR2                        (*((volatile u32*)(UART_BASEADDRESS +0x10)))


#define UART2_BASEADDRESS                  (0x40004400)

#define USART2_SR                         (*((volatile u32*)(UART2_BASEADDRESS +0x00)))
#define USART2_DR                         (*((volatile u32*)(UART2_BASEADDRESS +0x04)))
#define USART2_BRR                        (*((volatile u32*)(UART2_BASEADDRESS +0x08)))
#define USART2_CR1                        (*((volatile u32*)(UART2_BASEADDRESS +0x0C)))
#define USART2_CR2                        (*((volatile u32*)(UART2_BASEADDRESS +0x10)))

#endif /* MCAL_UART_UART_PRIVATE_H_ */
