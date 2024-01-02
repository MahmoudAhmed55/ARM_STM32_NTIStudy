/*
 * VtoI_Interface.h
 *
 *  Created on: Dec 4, 2023
 *      Author: lenovo
 */

#ifndef APP_VTOI_VTOI_INTERFACE_H_
#define APP_VTOI_VTOI_INTERFACE_H_

void VtoI_Init(void);
void VtoI_APP(void);
void VtoI_Com(void);
void RC_Control(void);


void CAR_Init(void);
void moveForward(void);
void movebackward(void);
void Car_Stop(void);
void MOVE_RIGHT(void);
void MOVE_LEFT(void);
void LANEFOLLOW_Init(void);

void RX1(void);
void RX2(void);


#endif /* APP_VTOI_VTOI_INTERFACE_H_ */
