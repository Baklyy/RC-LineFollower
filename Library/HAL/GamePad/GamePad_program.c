/*
 * GamePad_program.c

 *
 *  Created on: Aug 4, 2025
 *      Author: Mohamed Atif
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/dio_interface.h"
#include "GamePad_interface.h"
#include "GamePad_config.h"
#include "GamePad_private.h"
  /*   FRAME : 255 1 1 1 2 VAR1 VAR2 0  */
	button_t GamePad_ButtonPressed(u8 *frame)
	{
		button_t LocalButtonState = BUTTON_ERROR;
//	   if (sizeof(frame) != 8)
//	   {
//		   return BUTTON_ERROR;
//	   }


		   if  (frame[0] != 255)
		   {
			   return BUTTON_ERROR;
		   }
		   if (frame[1] != 1)
		   {
			   return BUTTON_ERROR;
		   }
		   if (frame[2] != 1)
		   {
		   		return BUTTON_ERROR;
		   }
		  if  (frame[3] != 1)
		  {
		  		return BUTTON_ERROR;
		  }
		   if (frame[4] != 2)
		   {
		  		 return BUTTON_ERROR;
		   }
		   if (frame[7] != 0)
		   {
		   		 return BUTTON_ERROR;
		   }
		   switch(frame[5])
			   {
			   case 0:
			switch(frame[6])
				   	{
				   		case 0:LocalButtonState = NO_BUTTON_PRESSED;break;
				   		case 1:LocalButtonState = UP;break;
				   		case 2:LocalButtonState = DOWN;break;
				   		case 4:LocalButtonState = LEFT;break;
				   		case 8:LocalButtonState = RIGHT;break;
				   		default:LocalButtonState = BUTTON_ERROR;
				   	}
			break;
			   case 1:LocalButtonState = START;break;
			   case 2:LocalButtonState = SELECT;break;
			   case 4:LocalButtonState = TRIANGLE;break;
			   case 8:LocalButtonState = CIRCLE;break;
			   case 16:LocalButtonState = CROSS;break;
			   case 32:LocalButtonState = SQUARE;break;
			   default:LocalButtonState= BUTTON_ERROR;
			   }






	   return LocalButtonState;
	}

