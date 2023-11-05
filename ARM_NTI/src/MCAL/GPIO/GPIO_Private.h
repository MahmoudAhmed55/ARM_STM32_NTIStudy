

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS       0x40010800
#define GPIOB_BASE_ADDRESS       0x40010C00
#define GPIOC_BASE_ADDRESS       0x40011000

/*REGISTER_ADDRESS_FOR_PORTA*/
#define GPIOA_CRL                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X00))
#define GPIOA_CRH                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X04))
#define GPIOA_IDR                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X08))
#define GPIOA_ODR                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C))
#define GPIOA_BSR                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X10))
#define GPIAO_BRR                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X14))
#define GPIOA_LCK                 *((volatile u32*) (GPIOA_BASE_ADDRESS +0X18))

/*REGISTER_ADDRESS_FOR_PORTB*/
#define GPIOB_CRL                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X00))
#define GPIOB_CRH                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X04))
#define GPIOB_IDR                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X08))
#define GPIOB_ODR                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X0C))
#define GPIOB_BSR                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X10))
#define GPIAB_BRR                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X14))
#define GPIOB_LCK                 *((volatile u32*) (GPIOB_BASE_ADDRESS +0X18))

/*REGISTER_ADDRESS_FOR_PORTC*/
#define GPIOC_CRL                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X00))
#define GPIOC_CRH                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X04))
#define GPIOC_IDR                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X08))
#define GPIOC_ODR                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X0C))
#define GPIOC_BSR                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X10))
#define GPIAC_BRR                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X14))
#define GPIOC_LCK                 *((volatile u32*) (GPIOC_BASE_ADDRESS +0X18))

#endif
