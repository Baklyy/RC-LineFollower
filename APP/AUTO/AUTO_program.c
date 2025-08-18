
#include "avr/delay.h"

#include "LIB/STD_TYPES.h"


#include "HAL/DSC/DSC_interface.h"
#include "HAL/IR/IR_interface.h"
#include "HAL/USS/USS_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/GamePad/GamePad_interface.h"


#include "MCAL/TIM/TIM_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"

#include "APP/RC_SYSTEM/RC_SYSTEM_interface.h"

#include "AUTO_interface.h"
#include "AUTO_private.h"
#include "AUTO_config.h"

extern volatile u8 RC_SYSTEM_u8_Mode;

u8 endLineReached = 0;

void AUTO_voidReCenter()
{
	DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD, AUTO_u16_STANDERED_RPM);
	SERVO_voidMoveAngle(90);
}


void AUTO_voidInit()
{
	//IR
	IR_voidEnable(EXTI_u8_EXTI0); // enable exi 0 Low level
	IR_voidEnable(EXTI_u8_EXTI1); // enable exi 1 Low level

	IR_voidSetCallBack(AUTO_voidIr0,EXTI_u8_EXTI0); // set callback for isr0
	IR_voidSetCallBack(AUTO_voidIr1,EXTI_u8_EXTI1); // set call back for isr1


//enable timer 0 to reset direction after one second
//TIM0_voidInit();


TIM0_voidSetOverFlowCallBack(tim0isr);
TIM0_voidEnableOverFlowInterrupt();

}


void AUTO_voidStart()
{
	AUTO_voidInit();

	AUTO_voidReCenter();
	while(1)
	{
		if(RC_SYSTEM_u8_Mode != RC_SYSTEM_u8_AUTO_MODE)
		{
			return;
		}
//		if(endLineReached)
//		{
//			DSC_voidStop();
//			return;
//		}

		if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
		{
//			UART_voidTransmitNumber(USS_f32GetDistance());
//			UART_voidTransmitNewLine();
			DSC_voidStop();
			//AUTO_voidAvoidObstacle();
		}
//		else
//		{
//			AUTO_voidReCenter();
//		}
	}
}

void AUTO_voidAvoidObstacle( )
{
	SERVO_voidMoveAngle(0);
	u8 leftBlock = 0;
	u8 middleBlock = 0;
	u8 rightBlock = 0;


	for(u8 index = 0; index < 20; index++)
	{
		SERVO_voidMoveAngle(index*3);
		if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
		{
			leftBlock++;
		}
	}

	for(u8 index = 20; index < 40; index++)
	{
		SERVO_voidMoveAngle(index*3);
		if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
		{
			middleBlock++;
		}
	}

	for(u8 index = 40; index < AUTO_u8_MAX_VIEW_SIZE; index++)
	{
		SERVO_voidMoveAngle(index*3);
		if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
		{
			rightBlock++;
		}
	}

	if(middleBlock < 2)
	{
		AUTO_voidReCenter();
	}
	else if(rightBlock < 2)
	{
		//avoid to the right
		AUTO_voidGoToClearSide(AUTO_u8_GO_RIGHT);
	}
	else if(leftBlock < 2)
	{
		//avoid to the left
		AUTO_voidGoToClearSide(AUTO_u8_GO_LEFT);
	}


}


void AUTO_voidGoToClearSide(u8 AUTO_u8_Clear_Side)
{
//	//disable the ir sensors
//	DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,AUTO_u8_AVOIDANCE_RPM);
//	switch(AUTO_u8_Clear_Side)
//	{
//	case AUTO_u8_GO_RIGHT:
//		SERVO_voidMoveAngle(150);
//		_delay_ms(400);
//		//enable right ir interrupts again after exiting the track
//
//
//		SERVO_voidMoveAngle(30);
//		_delay_ms(100);
//
//		break;
//	case AUTO_u8_GO_RIGHT:
//		break;
//	}
}



u16 AUTO_count = 0;



void tim0isr()
{

	AUTO_count++;


if (AUTO_count >= ((u16)(0.5*3906)) )
	{
	// prescaler 8
	// 8 mega freq
	// 256 ticks (tim0)
	//after around 3906 interrupt (1 sec it centers)

	AUTO_count=0;
AUTO_voidReCenter(); // center the car
//DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,DSC_u8_FORWARD);// forword 100RPM

	}

}


// IR

u8 AUTO_IR0state = 1; //enabled by default
u8 AUTO_IR1state = 1; //enabled by default


void AUTO_voidIRen(u8 Copy_u8EXTINo )
{

IR_voidEnable(Copy_u8EXTINo); // enable exi 0 Low level

}

void AUTO_voidIRdis(u8 Copy_u8EXTINo)
{
IR_voidDisable(Copy_u8EXTINo);



}


void AUTO_voidIr0()
{
//line detected at right direction

//	if(DIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN3) == 0)
//	{
//		endLineReached = 1;
//		return;
//	}


	DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,AUTO_u16_SLOW_RPM);// forword 50RPM
	SERVO_voidMoveAngle(AUTO_u8RIGHT); // move right
	AUTO_count = 0;

//if any ir is enabled it will enable the other one
//	if (AUTO_IR1state == 0)
//		{
//		AUTO_IR1state = 1;
//		AUTO_voidIRen(1);
//
//		}

}

void AUTO_voidIr1()
{
//line detected at left direction

//	if(DIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN2) == 0)
//		{
//			endLineReached = 1;
//			return;
//		}

	DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,AUTO_u16_SLOW_RPM);// forword 50RPM

	SERVO_voidMoveAngle(AUTO_u8LEFT); // move left
	AUTO_count = 0;

//if any ir is enabled it will enable the other one
//	if (AUTO_IR0state == 0)
//	{
//
//	AUTO_IR0state = 1;
//	AUTO_voidIRen(0);
//
//	}

}
