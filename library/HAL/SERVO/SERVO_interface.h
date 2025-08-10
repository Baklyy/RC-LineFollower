/*********************************************************************************************/
/************  Name   : Abdelrhman HamdallaH *************************************************/
/************  Date   :fourth of august 2025  ************************************************/
/************ this servo driver is intended for the atmega32A ********************************/
/*********************************************************************************************/

#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

#define SERVO_u8_Angle_Error    1
#define SERVO_u8_Angle_excuted  0





// function desc:  initilizes timer1 as fastPWM 10 bit 256 prescaling
//input: none
//output : none
void SERVO_voidInit(void);
//

// function desc:  moves the servo based on given angle
//input: u8 angle deg to move the servo (0 to 180)
// resolution = 3 degrees
// output : realtime movement of the servo connected on timer1 ocr1A

u8 SERVO_voidMoveAngle(u8 angle);
//









#endif
