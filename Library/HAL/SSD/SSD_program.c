/*
 * program.c
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"


#include "MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

//the functions are all made for a common cathode SSD
//the '!' operator is put on every pin value parameter
//in the function call to DIO_u8SetPinValue() to
//use the module for anode SSD


u8 SSD_Digits[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,1,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}};

void SSD_voidINIT(void)
{
	DIO_u8SetPortDirection(SSD_u8_INITIAL_PORT,DIO_u8_OUTPUT);
	DIO_u8SetPortValue(SSD_u8_INITIAL_PORT,!DIO_u8_LOW);
}


u8 SSD_u8Write(u8 num)
{
	if(num > 9)
	{
		return 1;
	}

	for(u8 DIO_u8_PINi = 0; DIO_u8_PINi < 7;DIO_u8_PINi++)
	{
		DIO_u8SetPinValue(SSD_u8_INITIAL_PORT,DIO_u8_PINi,!SSD_Digits[num][DIO_u8_PINi]);
	}

	return 0;
}

u8 SSD_u8Enable()
{
	DIO_u8SetPinValue(SSD_u8_INITIAL_PORT,SSD_u8_INITIAL_ENABLE_PIN,!DIO_u8_LOW);

	return 0;
}

u8 SSD_u8Disable()
{
	DIO_u8SetPinValue(SSD_u8_INITIAL_PORT,SSD_u8_INITIAL_ENABLE_PIN,!DIO_u8_HIGH);

	return 0;
}


