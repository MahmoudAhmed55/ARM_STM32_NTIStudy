/*
 * ULTRASONIC_Interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: lenovo
 */

#ifndef HAL_ULTRA_SONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRA_SONIC_ULTRASONIC_INTERFACE_H_

void ULTRASONIC_Init(void);
void ULTRASONIC_TRIG(void);
u16 ULTRASONIC_Read(void);
void ICU(void);




#endif /* HAL_ULTRA_SONIC_ULTRASONIC_INTERFACE_H_ */
