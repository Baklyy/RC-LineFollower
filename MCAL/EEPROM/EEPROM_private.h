/*
 * EEPROM_private.h
 *  Created on: Aug 9, 2025
 * Author: Mahmoud Abdel-fattah
 * Description: Private definitions for EEPROM driver
 */

#ifndef MCAL_EEPROM__EEPROM_PRIVATE_H_
#define MCAL_EEPROM__EEPROM_PRIVATE_H_
#define EEPROM_MAX_ADDRESS 1023

#define EECR   (*(volatile u8*)0x3C) // EEPROM Control Register
#define EEDR   (*(volatile u8*)0x3D) // EEPROM Data Register
#define EEARL   (*(volatile u8*)0x3E)  // EEPROM Address Register Low Byte
#define EEARH   (*(volatile u8*)0x3F)  // EEPROM Address Register High Byte


#define EERE   0   // EEPROM Read Enable
#define EEWE   1   // EEPROM Write Enable
#define EEMWE  2   // EEPROM Master Write Enable

#endif /* MCAL_EEPROM__EEPROM_PRIVATE_H_ */
