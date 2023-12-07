/*==============================================================================*
 * File        : TIMER_PRIVATE.h												*
 * Description : This file includes Addresses of TIMER 						    *
 * Author      : Mahmoud Gharib Embedded SW Engineer 							*
 * Date        : 																*
 * Git account : https://github.com/Mahmoud-Gharib								*
 * mail        : mahmoudgharib99999@gmail.com 		                            *
 * version     : 1 v                                                            *
 *==============================================================================*/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/*==========================================================================*
*	-----> Macros	=>  		TIMER2 , TIMER3	, TIMER4					*
*			*  Base_Address is	0x40000000 , 0x40000400 , 0x40000800		*
*===========================================================================*/
#define MTIMER2_BASE_ADDRESS     0x40000000
#define MTIMER3_BASE_ADDRESS     0x40000400
#define MTIMER4_BASE_ADDRESS     0x40000800

/*================================================================*
*	-----> Macros												  *
*			*  Register Map										  *
*=================================================================*/

typedef struct
{
	u32 volatile TIMER_CR1       ;
	u32 volatile TIMER_CR2       ;
	u32 volatile TIMER_SMCR      ;
	u32 volatile TIMER_DIER      ;
	u32 volatile TIMER_SR        ;
	u32 volatile TIMER_EGR       ;
	u32 volatile TIMER_CCMR1     ;
	u32 volatile TIMER_CCMR2     ;
	u32 volatile TIMER_CCER      ;
	u32 volatile TIMER_CNT       ;
	u32 volatile TIMER_PSC       ;
	u32 volatile TIMER_ARR       ;
	u32 volatile RESERVED1 		 ;
	u32 volatile TIMER_CCR1      ;
	u32 volatile TIMER_CCR2      ;
	u32 volatile TIMER_CCR3      ;
	u32 volatile TIMER_CCR4      ;
	u32 volatile RESERVED2 		 ;
	u32 volatile TIMER_DCR       ;
	u32 volatile TIMER_DMAR      ;
}TIMER_TypeDef;

/*================================================================*
*	-)Struct Macros :											  *
*			*  Base_Address TIMER2 ,  TIMER3 , TIMER4			  *
*=================================================================*/
#define MTIMER2      ((TIMER_TypeDef *)MTIMER2_BASE_ADDRESS)
#define MTIMER3      ((TIMER_TypeDef *)MTIMER3_BASE_ADDRESS)
#define MTIMER4      ((TIMER_TypeDef *)MTIMER4_BASE_ADDRESS)

#endif 
