/*
 ============================================================================
 Name        : LCD_private.h
 Author      : Manar Hashem
 Date		 : Oct 21, 2023
 Version     : 1.0
 Description : LCD_private header file
 ============================================================================
 */

#ifndef HAL_SEVSEG_SEVSEG_PRIVATE_H_
#define HAL_SEVSEG_SEVSEG_PRIVATE_H_


#define FourBits_MODE		4
#define EightBits_MODE		8
/* Bit	      Settings
 * I/D:       0 = Decrease cursor position		1 = Increment cursor position
 * D: 	      0 = Display off					1 = Display on
 * S:	      0 = No display shift				1 = Display shift
 * C: 	      0 = Cursor blink off				1 = Cursor blink on
 * B: 	      0 = Decrease cursor position		1 = Increment cursor position
 * S/C:	      0 = Move Cursor					1 = Don't Move
 * R/L:	      0 = Shift Left					1 = Shift Right
 * DL:	      0 = 4-Bit Interface				1 = 8-Bit Interface
 * N:	      0 = 1/8 or 1/11 Duty (1 Line)		1 = 1/16 Duty (2 Lines)
 * F:	      0 = 5x7 dots						1 = 5x11 dots
 * BF:	      0 = Can accept instruction		1 = Internal operation
 * */
/*---------------------------------------------------------------------------------------------------*/
/*Function Set
RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
=== === === === === === === === === ===
 0   0   0   0   1   DL  N   F   *   *
*/
#define FUNCTION_SET_8BIT_2LINES_5X7_DOTS  (u8) 0x38
#define FUNCTION_SET_4BIT_2LINES_5X7_DOTS  (u8) 0x28
/*---------------------------------------------------------------------------------------------------*/
/*Display On Off Control command 00001DCB
 * 1- D = 1 --> Display On
 * 2- C = 1 --> Cursor On
 * 3- B = 0 --> Cursor Off
 * */

#define DISPLAY_OFF   					   (u8) 0x08  //0b0001000, D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define DISPLAY_ON_CURSOR_ON_BLink_OFF     (u8) 0x0E  //0b0001110
#define DISPLAY_ON_CURSOR_OFF              (u8) 0x0C  //0b0001100, D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
/*---------------------------------------------------------------------------------------------------*/
/*Clear Display*/
#define DISPLAY_CLEAR                      (u8) 0x01
/*---------------------------------------------------------------------------------------------------*/
/*Entry Mode Set*/
#define ENTRY_MODE_SET                     (u8) 0x06	//  S = 0 (no screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
#define DISPLAY_SHIFT		 			   (u8) 0x1C
/*---------------------------------------------------------------------------------------------------*/
/*Return Display to its original position 00h  0000001-*/
#define RETURN_HOME                        (u8) 0x02
/*---------------------------------------------------------------------------------------------------*/

#define MOVE_CURSOR_RIGHT                  (u8) 0x14
#define MOVE_CURSOR_LEFT                   (u8) 0x10

/*---------------------------------------------------------------------------------------------------*/
/*Set CGRAM Address*/
#define SET_CGRAM_ADDRESS  (u8)(0x40)
/*---------------------------------------------------------------------------------------------------*/
/*Set DDRAM Address*/
#define SET_DDRAM_ADDRESS  (u8)(0x80)

#endif /* HAL_SEVSEG_SEVSEG_PRIVATE_H_ */
