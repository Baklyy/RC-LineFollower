/*
 * LCD_interface.h
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_u8_ClearDisplay 0b00000001

#define LCD_u8_MAX_FRACTION_DIGITS 			3
#define LCD_u8_MAX_FRACTION_DIGITS_FACTOR	1000
#define LCD_u8_MINMUM_FRACTION				0.001

void LCD_voidInit();

void LCD_voidSendInstrution(u8 instruction);

void LCD_voidSetPos(u8 x,u8 y);

void LCD_voidWriteChar(u8 ch);

void LCD_voidPrintStr(u8* str);

void LCD_voidShiftRightDisplay();

void LCD_voidShiftLeftDisplay();

void LCD_voidWriteInteger(u32 integer);

void LCD_voidWriteFraction(u32 frac);

void LCD_voidWriteNumber(f32 num);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
