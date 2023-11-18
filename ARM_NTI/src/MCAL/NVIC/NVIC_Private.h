/*
 * NVIC_Private.h
 *
 *  Created on: Nov 6, 2023
 *      Author: lenovo
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#define NVIC_BASEADDRESS                  0xE000E100
#define SYSTEM_CONTROL_BLOCK              0xE000ED00

#define NVIC_ISER0                        *((volatile u32*) (NVIC_BASEADDRESS +0x000))
#define NVIC_ISER1                        *((volatile u32*) (NVIC_BASEADDRESS +0x004))
#define NVIC_ISER2                        *((volatile u32*) (NVIC_BASEADDRESS +0x008))
#define NVIC_ICER0                        *((volatile u32*) (NVIC_BASEADDRESS +0x080))
#define NVIC_ICER1                        *((volatile u32*) (NVIC_BASEADDRESS +0x084))
#define NVIC_ICER2                        *((volatile u32*) (NVIC_BASEADDRESS +0x088))
#define NVIC_ISPR0                        *((volatile u32*) (NVIC_BASEADDRESS +0x100))
#define NVIC_ISPR1                        *((volatile u32*) (NVIC_BASEADDRESS +0x104))
#define NVIC_ISPR2                        *((volatile u32*) (NVIC_BASEADDRESS +0x108))
#define NVIC_ICPR0                        *((volatile u32*) (NVIC_BASEADDRESS +0x180))
#define NVIC_ICPR1                        *((volatile u32*) (NVIC_BASEADDRESS +0x184))
#define NVIC_ICPR2                        *((volatile u32*) (NVIC_BASEADDRESS +0x188))
#define NVIC_IABR0                        *((volatile u32*) (NVIC_BASEADDRESS +0x200))
#define NVIC_IABR1                        *((volatile u32*) (NVIC_BASEADDRESS +0x204))
#define NVIC_IABR2                        *((volatile u32*) (NVIC_BASEADDRESS +0x208))
#define NVIC_IPR0                         *((volatile u32*) (NVIC_BASEADDRESS +0x300))
#define NVIC_IPR20                        *((volatile u32*) (NVIC_BASEADDRESS +0x320))
#define NVIC_STIR                         *((volatile u32*) (NVIC_BASEADDRESS +0xE00))

//Address to set the priority
#define NVIC_IPR_PTR                           ((volatile u8*) (NVIC_BASEADDRESS +0x300))

//
#define SCB_AIRCR                         *((volatile u32*) (SYSTEM_CONTROL_BLOCK +0x0C))

#define VECTKEY      0x05FA0000
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
