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

#define TIMER_CR2                    *((volatile u32*) (TIMER1_BASEADDRESS +0x04))
#define CEN     0
#define UDIS    1
#define URS     2
#define DIR		4
#define CMS0	5
#define CMS1	6
#define APPE    7

#define TIMx_SR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x10))//interrupt flag register
#define UIF    0    // OV INTERRUPT
#define CC1IF  1    // ICU INTERRUPT
#define TIMx_CNT                         *((volatile u32*) (TIMER1_BASEADDRESS +0x24)) //count register
#define TIMx_PSC                         *((volatile u32*) (TIMER1_BASEADDRESS +0x28)) // prescaler register
#define TIMx_ARR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x2C)) //reload register

#define TIMx_EGR                         *((volatile u32*) (TIMER1_BASEADDRESS +0x14)) // enable icu
#define UG        1
#define TIMx_CCMR1                       *((volatile u32*) (TIMER1_BASEADDRESS +0x18)) // filter (icf)and mode
#define CC1S      0 //ACTIVR ICU 0->1
#define IC1PSC    2  //DISAPLE PRESCALLER 2->3
#define IC1F      4  //FILTER DURATION 4->7
#define CC2S      9  //IC2 is mapped on TI1 8->9


#define TIMx_CCER                        (*((volatile u32*) (TIMER1_BASEADDRESS +0x18))) // rising or falling(cc1p)
#define  CC1E     0 //ENABLE ICU
#define  CC1P     1 // ICU RISINGOR
#define  CC2P     5 // ICU FALLING

#define TIMx_CCR1                        (*((volatile u32*) (TIMER1_BASEADDRESS +0x34)))
#define TIMx_CCR2                        (*((volatile u32*) (TIMER1_BASEADDRESS +0x38)))
#define TIMx_RCR                        (*((volatile u32*) (TIMER1_BASEADDRESS +0x30)))
#define TIMx_DIER                        *((volatile u32*) (TIMER1_BASEADDRESS +0x0c))//ICU interrupt
#define UIE    0    // OV INTERRUPT
#define CC1IE  1    //ICU INTERRUPT
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
