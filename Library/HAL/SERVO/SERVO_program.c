/*********************************************************************************************/
/************  Name   : Abdelrhman HamdallaH *************************************************/
/************  Date   :fourth of august 2025  ************************************************/
/************ this servo driver is intended for the  atmega32A *******************************/
/*************The servo should be connected on OCR1A******************************************/
/*********************************************************************************************/
//LIB
#include "LIB/std_types.h"
#include "LIB/BIT_MATH.h"
#include "LIB/delay.h"

//MCAL
#include "MCAL/TIM/TIM_interface.h"

//HAL
#include "HAL/SERVO/SERVO_interface.h"

void SERVO_voidInit()
{
// for the Servo to move propeply Timer1 should be configured as  :
	/* timer settings:
	 * TIM1_u8_MODE_PWM_FAST_OCR1A
	 * TIM1_u8_PRESCALER_256
	 * clear in comp mode
	 * period = 32.7 ms
	 */


//timier1 init
TIM1_voidPWMInit();

//clear on cmp match
TIM1_voidSetOutputCompareMode(TIM1_u8_TIM1A,2);

//angle 90 at init
SERVO_voidMoveAngle(90);


}


// function desc:  moves the servo based on given angle
//input: u8 angle deg to move the servo (0 to 180)
// output : realtime movement of the servo connected on timer1 ocr
u8 SERVO_voidMoveAngle(u8 angle)
{
// error check
	u8 localservo_error = SERVO_u8_Angle_excuted;
	if (angle<0 || angle > 180) localservo_error = SERVO_u8_Angle_Error;


u8 ocrval = ((u8) (12.0 +(( 67.0/180.0 )*angle)));

//formula to move from 0 to 180;
TIM1_voidSetOCR1A(ocrval);


//return errorstatus
return localservo_error;
}
