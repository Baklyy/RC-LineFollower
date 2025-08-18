#include "LIB/STD_TYPES.h"

#include "MCAL/TIM/TIM_interface.h"

#include "HAL/DSC/DSC_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "HAL/GamePad/GamePad_interface.h"
#include "HAL/USS/USS_interface.h"
#include "HAL/IR/IR_interface.h"

#include "APP/RC_SYSTEM/RC_SYSTEM_interface.h"

#include "MAN_interface.h"
#include "MAN_private.h"
#include "MAN_config.h"

extern volatile u8 RC_SYSTEM_u8_Mode;
extern volatile button_t lastButton;

void MAN_voidInit()
{
	IR_voidDisable(EXTI_u8_EXTI0);
	IR_voidDisable(EXTI_u8_EXTI1);

	TIM0_voidDisableOverFlowInterrupt();
}

void MAN_voidStart()
{
	MAN_voidInit();

	 while (1)
	    {
		 if(RC_SYSTEM_u8_Mode != RC_SYSTEM_u8_MAN_MODE)
		 {
			 return;
		 }

		 switch(lastButton)
		 {
		 case forward:
			 if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
			 {
				 DSC_voidStop();
			 }
			 else{
			 DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,MAN_u8_CAR_SPEED);
			 SERVO_voidMoveAngle(MAN_u8_SERVO_CENTER);
	    	 }
			 break;
		 case forwardRight:
			 if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
			 {
				 DSC_voidStop();
			 }
			 else{
			 DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,MAN_u8_CAR_SPEED);
			 SERVO_voidMoveAngle(MAN_u8_SERVO_RIGHT);
			 }
		 	 break;
		 case forwardLeft:
			 if(USS_f32GetDistance() < USS_f32_COLLISION_DIST)
			 {
				 DSC_voidStop();
			 }else{
			 DSC_voidSetDirectionAndRPM(DSC_u8_FORWARD,MAN_u8_CAR_SPEED);
			 SERVO_voidMoveAngle(MAN_u8_SERVO_LEFT);
			 }
			 break;
		 case backward:
			 DSC_voidSetDirectionAndRPM(DSC_u8_BACKWORD,MAN_u8_CAR_SPEED);
			 SERVO_voidMoveAngle(MAN_u8_SERVO_CENTER);
			 break;
		 case backwardRight:
			 DSC_voidSetDirectionAndRPM(DSC_u8_BACKWORD,MAN_u8_CAR_SPEED);
			 SERVO_voidMoveAngle(MAN_u8_SERVO_RIGHT);
		 	 break;
		 case backwardLeft:
			 DSC_voidSetDirectionAndRPM(DSC_u8_BACKWORD,MAN_u8_CAR_SPEED);
			SERVO_voidMoveAngle(MAN_u8_SERVO_LEFT);
		 	 break;
		 default:
			 DSC_voidStop();
			 SERVO_voidMoveAngle(MAN_u8_SERVO_CENTER);
			 break;
		 }


	    }
}


