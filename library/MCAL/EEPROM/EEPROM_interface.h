/*
 * EEPROM_config.h
 *  Created on: Aug 9, 2025
 * Author: Mahmoud Abdel-fattah
 * Description: Interfacing file for EEPROM driver
 */

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"




void EEPROM_voidWrite(u16 Copy_u16Address, u8 Copy_u8Data);
u8   EEPROM_u8Read(u16 Copy_u16Address);




#endif /* MCAL_EEPROM__EEPROM_INTERFACE_H_ */


