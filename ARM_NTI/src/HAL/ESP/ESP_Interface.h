/*
 * ESP_Interface.h
 *
 *  Created on: Nov 30, 2023
 *      Author: lenovo
 */

#ifndef HAL_ESP_ESP_INTERFACE_H_
#define HAL_ESP_ESP_INTERFACE_H_

void ESP_Init(void);
u8 ESP_Get(void);
void ESP_Post(c8 data);

void RX(void);
#endif /* HAL_ESP_ESP_INTERFACE_H_ */
