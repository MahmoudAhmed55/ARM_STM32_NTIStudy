/*==============================================================================================*
 * File        : ULTRASONIC_SENSOR_PROGRAM.c													*
 * Description : This file includes ULTRASONIC_SENSOR implementations 					     	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 											*
 * Date        : 																				*
 * Git account : https://github.com/Mahmoud-Gharib												*
 * mail        : mahmoudgharib99999@gmail.com 													*
 * version     : 1 v                                                           	    			*
 *==============================================================================================*/

/*************** LIB ****************/
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

/************ MCAL **********/
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../../MCAL/NVIC/NVIC_Interface.h"

/***************  HAL  *************/
#include "ULTRASONIC_SENSOR_CONFIG.h"
#include "ULTRASONIC_SENSOR_PRIVATE.h"
#include "ULTRASONIC_SENSOR_INTERFACE.h"


volatile u32 T1[4] = { 0 },T2[4] = { 0 },FLAG[4] = { 0 };

void HULTRASONIC_SENSOR_voidInit ( void ) 
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2  , IOPA);
	RCC_EnableClock(APB2  , IOPB);

#if    TIMER    ==   TIMER2
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM2 );
	MTIMER_voidEnable(TIMER);
	MNVIC_voidEnablePeripheral(28);
	MTIMER2_ICUSetCallBack(Func);

#elif  TIMER    ==   TIMER3
	RCC_EnableClock( APB1 , TIM3_EN );
	MTIMER_voidEnable(TIMER);
	Interrupt_Set_Enable(29);
	MTIMER3_ICUSetCallBack(Func);

#elif  TIMER    ==   TIMER4
	MRCC_voidEnablePeripheralClock( APB1_BUS , RCC_TIM4 );
	MTIMER_voidEnable(TIMER);
	MNVIC_voidEnablePeripheral(30);
	MTIMER4_ICUSetCallBack(Func);

#else

#endif

#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	GPIO_SetPinDirection(FIRST_ECHO   , INPUT_PULL_UP_DOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , 0);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);

	GPIO_SetPinDirection(FIRST_TRIG , OUTPUT50MHZ_PUSHPALL);

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	GPIO_SetPinDirection(FIRST_ECHO   , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(SECOND_ECHO  , INPUT_PULL_UP_DOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);

	GPIO_SetPinDirection(FIRST_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(SECOND_TRIG , OUTPUT50MHZ_PUSHPALL);

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	GPIO_SetPinDirection(FIRST_ECHO   , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(SECOND_ECHO  , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(THIRD_ECHO   , INPUT_PULL_UP_DOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL3 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL3 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL3);

	GPIO_SetPinDirection(FIRST_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(SECOND_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(THIRD_TRIG , OUTPUT50MHZ_PUSHPALL);

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	GPIO_SetPinDirection(FIRST_ECHO   , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(SECOND_ECHO  , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(THIRD_ECHO   , INPUT_PULL_UP_DOWN);
	GPIO_SetPinDirection(FOURTH_ECHO  , INPUT_PULL_UP_DOWN);

	MTIMER_voidInit(TIMER , CHANNEL1 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL2 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL3 , ICU , 7 , 65535);
	MTIMER_voidInit(TIMER , CHANNEL4 , ICU , 7 , 65535);

	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL3 , RISING);
	MTIMER_voidInputCaptureEdge(TIMER , CHANNEL4 , RISING);

	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL1);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL2);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL3);
	MTIMER_voidICUInterruptEnable(TIMER , CHANNEL4);

	GPIO_SetPinDirection(FIRST_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(SECOND_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(THIRD_TRIG , OUTPUT50MHZ_PUSHPALL);
	GPIO_SetPinDirection(FOURTH_TRIG , OUTPUT50MHZ_PUSHPALL);

#else

#endif

}

void HULTRASONIC_SENSOR_voidCalculateDistance( u32 *PtrDistance ) 
{
#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	GPIO_SetPinValue(PINA5 , 1);
	SYSTICK_BusyWait_Us(10);
	GPIO_SetPinValue(PINA6 , 0);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	MGPIO_voidSetPinValue(THIRD_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(THIRD_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;
	PtrDistance[2] = ( T2[2] - T1[2] ) / 58;

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	MGPIO_voidSetPinValue(FIRST_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(FIRST_TRIG , LOW);

	MGPIO_voidSetPinValue(SECOND_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(SECOND_TRIG , LOW);

	MGPIO_voidSetPinValue(THIRD_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(THIRD_TRIG , LOW);

	MGPIO_voidSetPinValue(FOURTH_TRIG , HIGH);
	SYSTICK_BusyWait_Us(10);
	MGPIO_voidSetPinValue(FOURTH_TRIG , LOW);

	PtrDistance[0] = ( T2[0] - T1[0] ) / 58;
	PtrDistance[1] = ( T2[1] - T1[1] ) / 58;
	PtrDistance[2] = ( T2[2] - T1[2] ) / 58;
	PtrDistance[3] = ( T2[3] - T1[3] ) / 58;

#else

#endif

}

void Func(void)
{
#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , 1);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,0);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[2] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[2] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	if (FLAG[0] == 0 )
	{
		T1[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 , FALLING);
	}
	else if (FLAG[0] == 1 )
	{
		T2[0] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL1);
		FLAG[0] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL1 ,RISING);
	}

	if (FLAG[1] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[1] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL2);
		FLAG[1] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[2] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[2] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL3);
		FLAG[2] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}

	if (FLAG[3] == 0 )
	{
		T1[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL4);
		FLAG[3] = 1;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 , FALLING);
	}
	else if (FLAG[3] == 1 )
	{
		T2[1] = MTIMER_u16GetCaptureValue(TIMER , CHANNEL4);
		FLAG[3] = 0;
		MTIMER_voidInputCaptureEdge(TIMER , CHANNEL2 ,RISING);
	}
#else

#endif

}
