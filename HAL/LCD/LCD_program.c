/*
 * LCD_program.c
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit()
{
	DIO_u8SetPortDirection(LCD_u8_DATA_PORT,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_Enable_PORT,LCD_u8_Enable_PIN,DIO_u8_OUTPUT);

	delay_ms(100);
	LCD_voidSendInstruction(0b00111100);
	delay_ms(2);
	LCD_voidSendInstruction(0b00111100);
	delay_ms(2);
	//0b00001DCB, D:SetDisplay, C: cursor, B: Blinking Cursor
	LCD_voidSendInstruction(0b00001111);
	delay_ms(2);
	LCD_voidSendInstruction(LCD_u8_ClearDisplay);
	delay_ms(2);
	LCD_voidSendInstruction(0b00000110);


}

void LCD_voidSendInstruction(u8 instruction)
{
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(LCD_u8_Enable_PORT,LCD_u8_Enable_PIN,DIO_u8_HIGH);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,instruction);

	delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_Enable_PORT,LCD_u8_Enable_PIN,DIO_u8_LOW);
}

void LCD_voidWriteChar(u8 ch)
{
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(LCD_u8_Enable_PORT,LCD_u8_Enable_PIN,DIO_u8_HIGH);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT,ch);

	delay_ms(1);

	DIO_u8SetPinValue(LCD_u8_Enable_PORT,LCD_u8_Enable_PIN,DIO_u8_LOW);
}

void LCD_voidSetPos(u8 y,u8 x)
{
	LCD_voidSendInstruction(0x80 + 0x40*y + x);
}

void LCD_voidPrintStr(u8* str)
{
	u32 i = 0;
	u8 line = 0; //0:
	while(str[i] != '\0')
	{
		if((i != 0) && (i%16 == 0) && (line == 0))
		{
			line = 1;
			LCD_voidSetPos(line,0);
		}
		else if((i%16 == 0) && (line == 1))
		{
			delay_ms(4000);
			line = 0;
			LCD_voidSendInstruction(LCD_u8_ClearDisplay);
			LCD_voidSetPos(line,0);
		}
		LCD_voidWriteChar(str[i]);
		i++;
	}

}


void LCD_voidShiftRightDisplay()
{
	LCD_voidSendInstruction(0b00011100);
}


void LCD_voidShiftLeftDisplay()
{
	LCD_voidSendInstruction(0b00011000);
}

void LCD_voidWriteInteger(u32 integer)
{
	if(integer == 0)
	{
		LCD_voidWriteChar('0');
		return;
	}

	u8 count  = 0;
	u32 invertedInteger = 0;
	while(integer != 0)
	{
		invertedInteger = (integer%10) + invertedInteger*10;
		integer /= 10;
		count++;
	}

	while(count != 0)
	{
		LCD_voidWriteChar(invertedInteger%10 + 48);
		invertedInteger /=10;
		count--;
	}
}

void LCD_voidWriteFraction(u32 frac)
{
	u8 count  = 0;
	u32 invertedFrac = 0;
	while(frac != 0)
	{
		invertedFrac = (frac%10) + invertedFrac*10;
		frac /= 10;
		count++;
	}

	u8 zerosToPrint = LCD_u8_MAX_FRACTION_DIGITS - count;
	while(zerosToPrint)
	{
		LCD_voidWriteChar('0');
		zerosToPrint--;
	}

	while(count != 0)
	{
		LCD_voidWriteChar(invertedFrac%10 + 48);
		invertedFrac /=10;
		count--;
	}
}

void LCD_voidWriteNumber(f32 num)
{

	if(num < 0)
	{
		num *= -1;
		LCD_voidWriteChar('-');
	}

	u32 intNum = (s32)num;
	f32 afterDecimalPoint = num - (f32)intNum;

	LCD_voidWriteInteger(intNum);

	if(afterDecimalPoint > LCD_u8_MINMUM_FRACTION)
	{
		LCD_voidWriteChar('.');
		LCD_voidWriteFraction(afterDecimalPoint*LCD_u8_MAX_FRACTION_DIGITS_FACTOR);
	}
}
