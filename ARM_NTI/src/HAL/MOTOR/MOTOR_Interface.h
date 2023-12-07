/*
 * MOTOR_Interface.h
 *
 *  Created on: Nov 24, 2023
 *      Author: lenovo
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_

typedef enum{
	M1,
	M2,
	M3,
	M4

}MOTOR_type;
void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_type m);

void MOTOR_CW(MOTOR_type m);

void MOTOR_CCW(MOTOR_type m);

/* speed 0:100*/
/* speed 0:1400*/
void MOTOR_Speed(MOTOR_type m,u8 speed);



#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
