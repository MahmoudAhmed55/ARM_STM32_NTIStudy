/*
 * NVIC_Interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: lenovo
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#define GROUP3 0X05FA0300   // CONSIDER BASE ADDRESS FOR SCB
#define GROUP4 0X05FA0400
#define GROUP5 0X05FA0500
#define GROUP6 0X05FA0600
#define GROUP7 0X05FA0700

typedef enum
{
	WWDG=0,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7,
	ADC1_2,
	USB_HP_CAN_TX,
	USB_LP_CAN_RX0,
	CAN_RX1,
	CAN_SCE,
	EXTI9_5,
	TIM1_BRK,
	TIM1_UP,
	TIM1_TRG_COM,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
    I2C1_EV,
	I2C1_ER,
    I2C2_EV,
    I2C2_ER,
    SPI,
    SPI2,
    USART1,
    USART2,
    USART3,
    EXTI15_10,
    RTCAlarm,
}Interrupt_t;

typedef enum
{
	Set_Enable0=0,
	Set_Enable1,
	Set_Enable2,
	Clear_Enable0,
	Clear_Enable1,
	Clear_Enable2,
	Set_Pending0,
	Set_Pending1,
	Set_Pending2,
	Clear_Pending0,
	Clear_Pending1,
	Clear_Pending2,
	Active_Bit0,
	Active_Bit1,
	Active_Bit2,

}InterruptVariable_t;

void Interrupt_Set_Enable(Interrupt_t num);
void Interrupt_Clear_Enable(Interrupt_t num);
void Interrupt_Set_Pending(Interrupt_t num);
void Interrupt_Clear_Pending(Interrupt_t num);
u8 Interrupt_Active_Bit(Interrupt_t num);
u8 Read_Interrupt_Status(InterruptVariable_t status ,Interrupt_t num);


void Set_InterruptPriority2(c8 id,u8 group,c8 sub,u32 Priority_Group);


#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
