/*
 * LCD_Interface.h
 *
 *  Created on: Nov 19, 2023
 *      Author: lenovo
 */

#ifndef MCAL_LCD_LCD_INTERFACE_H_
#define MCAL_LCD_LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_Clear(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(c8*str);
void LCD_GoTo(u8 line,u8 cell);
void LCD_WriteNumber(s32 num);
void LCD_Write4D(s16 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_CustomChar(u8 address,u8*pattern);



#endif /* MCAL_LCD_LCD_INTERFACE_H_ */
