/*
 * KPD_program.c
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"
#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

u8 KPD_Keys[KPD_u8_NUM_OF_ROWS][KPD_u8_NUM_OF_COLUMNS] = {{'7','8','9','/'},
														  {'4','5','6','*'},
														  {'1','2','3','-'},
														  {'#','0','=','+'}};

u8 KPD_Alphabets[KPD_u8_NUM_OF_ROWS][KPD_u8_NUM_OF_COLUMNS] = {{'A','B','C','D'},
															   {'E','F','G','H'},
															   {'I','J','K','L'},
															   {'M','N','O','P'}};


u8 (*KPD_pu8_Layout)[KPD_u8_NUM_OF_COLUMNS];

void KPD_voidINIT()
{
	switch(KPD_u8_INITIAL_LAYOUT)
		{
		case KPD_u8_NUMBERS_LAYOUT:
			KPD_pu8_Layout = KPD_Keys;
			break;
		case KPD_u8_ALPHABETS_LAYOUT:
			KPD_pu8_Layout = KPD_Alphabets;
		}


	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_ROW_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_ROW_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_ROW_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_ROW_PIN3,DIO_u8_OUTPUT);

	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_ROW_PIN0,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_ROW_PIN1,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_ROW_PIN2,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_ROW_PIN3,DIO_u8_HIGH);

	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_COLUMN_PIN0,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_COLUMN_PIN1,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_COLUMN_PIN2,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_COLUMN_PIN3,DIO_u8_INPUT);


	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_COLUMN_PIN0,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_COLUMN_PIN1,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_COLUMN_PIN2,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_u8_PORT, KPD_u8_COLUMN_PIN3,DIO_u8_HIGH);
}

u8 KPD_u8ReadKey()
{
	u8 KPD_u8RowPins[KPD_u8_NUM_OF_ROWS] = {KPD_u8_ROW_PIN0,KPD_u8_ROW_PIN1,
			KPD_u8_ROW_PIN2,KPD_u8_ROW_PIN3};
	u8 KPD_u8ColumnsPins[KPD_u8_NUM_OF_COLUMNS] = {KPD_u8_COLUMN_PIN0,
			KPD_u8_COLUMN_PIN1,KPD_u8_COLUMN_PIN2,KPD_u8_COLUMN_PIN3};

	u8 KPD_u8Char = 0;
	for(u8 KPD_u8_ROWi = 0; KPD_u8_ROWi < KPD_u8_NUM_OF_ROWS; KPD_u8_ROWi++)
	{
		DIO_u8SetPinValue(KPD_u8_PORT,KPD_u8RowPins[KPD_u8_ROWi],DIO_u8_LOW);
		for(u8 KPD_u8_COLUMNi = 0; KPD_u8_COLUMNi < KPD_u8_NUM_OF_COLUMNS; KPD_u8_COLUMNi++)
		{
			u8 KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
			delay_ms(20);
			KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
			if(KPD_u8PinState == DIO_u8_LOW)
			{
				KPD_u8Char = KPD_pu8_Layout[KPD_u8_ROWi][KPD_u8_COLUMNi];
				while(KPD_u8PinState == DIO_u8_LOW)
				{
					KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
				}

			}
		}
		DIO_u8SetPinValue(KPD_u8_PORT,KPD_u8RowPins[KPD_u8_ROWi],DIO_u8_HIGH);
	}
	return KPD_u8Char;
}

u8 KPD_u8WaitAndReadKey()
{
	// same as KPD_u8ReadKey() but stops the program till the user enters an input
	while(1)
	{
		u8 KPD_u8RowPins[KPD_u8_NUM_OF_ROWS] = {KPD_u8_ROW_PIN0,KPD_u8_ROW_PIN1,
					KPD_u8_ROW_PIN2,KPD_u8_ROW_PIN3};
			u8 KPD_u8ColumnsPins[KPD_u8_NUM_OF_COLUMNS] = {KPD_u8_COLUMN_PIN0,
					KPD_u8_COLUMN_PIN1,KPD_u8_COLUMN_PIN2,KPD_u8_COLUMN_PIN3};

			u8 KPD_u8Char = 0;
			for(u8 KPD_u8_ROWi = 0; KPD_u8_ROWi < KPD_u8_NUM_OF_ROWS; KPD_u8_ROWi++)
			{
				DIO_u8SetPinValue(KPD_u8_PORT,KPD_u8RowPins[KPD_u8_ROWi],DIO_u8_LOW);
				for(u8 KPD_u8_COLUMNi = 0; KPD_u8_COLUMNi < KPD_u8_NUM_OF_COLUMNS; KPD_u8_COLUMNi++)
				{
					u8 KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
					delay_ms(20);
					KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
					if(KPD_u8PinState == DIO_u8_LOW)
					{
						KPD_u8Char = KPD_pu8_Layout[KPD_u8_ROWi][KPD_u8_COLUMNi];
						while(KPD_u8PinState == DIO_u8_LOW)
						{
							KPD_u8PinState = DIO_u8GetPinValue(KPD_u8_PORT,KPD_u8ColumnsPins[KPD_u8_COLUMNi]);
						}
						DIO_u8SetPinValue(KPD_u8_PORT,KPD_u8RowPins[KPD_u8_ROWi],DIO_u8_HIGH);
						return KPD_u8Char;
					}
				}
				DIO_u8SetPinValue(KPD_u8_PORT,KPD_u8RowPins[KPD_u8_ROWi],DIO_u8_HIGH);
			}
	}

}

void KPD_u8SetLayout(u8 KPD_u8_Layout)
{
	switch(KPD_u8_INITIAL_LAYOUT)
			{
			case KPD_u8_NUMBERS_LAYOUT:
				KPD_pu8_Layout = KPD_Keys;
				break;
			case KPD_u8_ALPHABETS_LAYOUT:
				KPD_pu8_Layout = KPD_Alphabets;
			}

}

void KPD_u8ToggleLayout()
{
	if(KPD_pu8_Layout == KPD_Keys)
	{
		KPD_pu8_Layout = KPD_Alphabets;
	}
	else
	{
		KPD_pu8_Layout = KPD_Keys;
	}

}
