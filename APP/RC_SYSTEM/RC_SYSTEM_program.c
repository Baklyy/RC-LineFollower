/*
 * RC_SYSTEM_program.c
 *
 *  Created on: Aug 10, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"

#include "MCAL/UART/UART_interface.h"
#include "MCAL/TIM/TIM_interface.h"
#include "MCAL/GPI/GPI_interface.h"

#include "HAL/DSC/DSC_interface.h"
#include "HAL/GamePad/GamePad_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/USS/USS_interface.h"

#include "APP/AUTO/AUTO_interface.h"
#include "APP/MAN/MAN_interface.h"

#include "RC_SYSTEM_interface.h"
#include "RC_SYSTEM_config.h"

volatile u8 RC_SYSTEM_u8_Mode = RC_SYSTEM_u8_MAN_MODE;

volatile u8 Frame[8];
volatile u8 byteIndex = 0;
volatile button_t lastButton = NO_BUTTON_PRESSED;
volatile button_t lastButtonState = NO_BUTTON_PRESSED;


void RC_SYSTEM_ReceiveISR(void)
{

    u8 receivedByte = UART_u16Read(); // Read the incoming byte
    Frame[byteIndex++] = receivedByte;

    if(Frame[0] != 255)
    {
    	byteIndex = 0;
    }

    if (byteIndex >= 8)
    {
        // Frame complete, process it
        lastButton = GamePad_JoyStickMoved((u8*)Frame);

        // Reset for next frame
        byteIndex = 0;
    }

    if((lastButton == SELECT) && (lastButtonState != SELECT))
    {
    	//RC_SYSTEM_u8_Mode = (RC_SYSTEM_u8_Mode == RC_SYSTEM_u8_AUTO_MODE)?RC_SYSTEM_u8_MAN_MODE:RC_SYSTEM_u8_AUTO_MODE;
    	lastButtonState = SELECT;
    	if(RC_SYSTEM_u8_Mode == RC_SYSTEM_u8_AUTO_MODE)
    	{
    		RC_SYSTEM_u8_Mode = RC_SYSTEM_u8_MAN_MODE;
    	}
    	else
    	{
    		RC_SYSTEM_u8_Mode = RC_SYSTEM_u8_AUTO_MODE;
    	}
    }
    else if((lastButton != SELECT) && (lastButtonState == SELECT))
    {
    	lastButtonState = NO_BUTTON_PRESSED;
    }
}


void RC_SYSTEM_voidInit()
{
	DSC_voidInit();
	SERVO_voidInit();
	USS_voidInit();
	UART_voidInit();
	UART_voidSetReceiveCallBack(RC_SYSTEM_ReceiveISR);
	UART_voidEnableReceiveInterrupt();

	GPI_voidInit();
}

void RC_SYSTEM_voidStart()
{
	RC_SYSTEM_voidInit();

	while(1)
	{
		if(RC_SYSTEM_u8_Mode == RC_SYSTEM_u8_AUTO_MODE)
		{
			AUTO_voidStart();
		}
		else
		{
			MAN_voidStart();
		}
	}
}
