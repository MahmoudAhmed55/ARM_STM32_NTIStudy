/*
 * TIMER_Private.h
 *
 *  Created on: Nov 17, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define   TIMER1_BASEADDRESS      (0x40012C00)


#define TIMER_CR1                    *((volatile u32*) (TIMER1_BASEADDRESS +0x00))//timer control register
#define CEN     0
#define UDIS    1
#define URS     2
#define DIR		4
#define CMS0	5
#define CMS1	6
#define APPE    7

#define TIMx_SR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x10))//interrupt flag register
#define UIF    0    // OV INTERRUPT

#define TIMx_CNT                         *((volatile u32*) (TIMER1_BASEADDRESS +0x24)) //count register
#define TIMx_PSC                         *((volatile u32*) (TIMER1_BASEADDRESS +0x28)) // prescaler register
#define TIMx_ARR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x2C)) //reload register

#define TIMx_EGR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x14)) // enable icu
#define TIMx_CCMR1                       *((volatile u32*) (TIMER1_BASEADDRESS +0x18)) // filter (icf)and mode
#define TIMx_CCER                        *((volatile u32*) (TIMER1_BASEADDRESS +0x18)) // rising or falling(cc1p)
#define TIMx_CCR1                        *((volatile u32*) (TIMER1_BASEADDRESS +0x34))
#define TIMx_DIER                        *((volatile u32*) (TIMER1_BASEADDRESS +0x0c))//ICU interrupt
#define UIE    0    // OV INTERRUPT
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
