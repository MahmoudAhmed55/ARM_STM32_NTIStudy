/*===============================================================================================================*
 * File        : ULTRASONIC_SENSOR_CONFIG.h  																	 *
 * Description : The Optiones for ULTRASONIC_SENSOR Which Developer Choose From Which What Is Appropriate To App *															   	*
 * Author      : Mahmoud Gharib Embedded SW Engineer 															 *
 * Date        : 																								 *
 * Git account : https://github.com/Mahmoud-Gharib																 *
 * mail        : mahmoudgharib99999@gmail.com 													   				 *
 * version     : 1 v                       	                                    								 *
 *===============================================================================================================*/
#ifndef ULTRASONIC_SENSOR_CONFIG_H
#define ULTRASONIC_SENSOR_CONFIG_H

/*==============================================*
*		- TIMER option :          	  			*
*			         1) TIMER2  			    *
*			         2) TIMER3					*
*					 3) TIMER4				    *
*==============================================*/ 
#define TIMER   TIMER3

/*==============================================*
*	- N. OF ULTRASONIC SENSOE option :          *
*			         1) ONE  			    	*
*			         2) TWO						*
*					 3) THREE				    *
*					 4) FOUR					*
*==============================================*/ 
#define N_OF_ULTRASONIC_SENSOR   	ONE


/*==============================================*
*   ECHO option :                               *
*	=> TIMER_2 :								*
*			1)FIRST_ECHO 	==> GPIOA   , PIN0  *
*			2)SECOND_ECHO   ==> GPIOA	, PIN1	*
*			3)THIRD_ECHO	==> GPIOA	, PIN2	*
*			4)FOURTH_ECHO	==> GPIOA	, PIN3	*
*												*
*	=> TIMER_3 :								*
*			1)FIRST_ECHO 	==> GPIOA   , PIN6  *
*			2)SECOND_ECHO   ==> GPIOA	, PIN7	*
*			3)THIRD_ECHO	==> GPIOB	, PIN0	*
*			4)FOURTH_ECHO	==> GPIOB	, PIN1	*
*												*
*	=> TIMER_4 :								*
*			1)FIRST_ECHO 	==> GPIOB   , PIN6  *
*			2)SECOND_ECHO   ==> GPIOB	, PIN7	*
*			3)THIRD_ECHO	==> GPIOB	, PIN8	*
*			4)FOURTH_ECHO	==> GPIOB	, PIN9	*
*												*
*		 TRIG option :  any Pins				*
*==============================================*/ 

#define 	ONE     0
#define 	TWO     1
#define 	THREE   2
#define 	FOUR    3



#if   N_OF_ULTRASONIC_SENSOR    ==     ONE
	#define FIRST_ECHO       IOPA , PINA6

	#define FIRST_TRIG       IOPA , PINA5

#elif N_OF_ULTRASONIC_SENSOR    ==     TWO
	#define FIRST_ECHO       GPIOA , PIN6
	#define SECOND_ECHO      GPIOA , PIN7

	#define FIRST_TRIG		GPIOA , PIN5
	#define SECOND_TRIG     GPIOB , PIN0

#elif N_OF_ULTRASONIC_SENSOR    ==     THREE
	#define FIRST_ECHO       GPIOA  , PIN6
	#define SECOND_ECHO      GPIOA	, PIN7
	#define THIRD_ECHO       GPIOB	, PIN0

	#define FIRST_TRIG
	#define SECOND_TRIG
	#define THIRD_TRIG

#elif N_OF_ULTRASONIC_SENSOR    ==     FOUR
	#define FIRST_ECHO       GPIOA  , PIN6
	#define SECOND_ECHO      GPIOA	, PIN7
	#define THIRD_ECHO       GPIOB	, PIN0
	#define FOURTH_ECHO      GPIOB	, PIN1

	#define FIRST_TRIG
	#define SECOND_TRIG
	#define THIRD_TRIG
	#define FOURTH_TRIG

#else

#endif


#endif 
