/*
 * EEPROM_program.c
 *  Created on: Aug 9, 2025
 * Author: Mahmoud Abdel-fattah
 * Description: Implementation of EEPROM driver
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/EEPROM/ EEPROM_interface.h"
#include "MCAL/EEPROM/ EEPROM_private.h"
#include "MCAL/EEPROM/EEPROM_config.h"






void EEPROM_voidWrite(u16 Copy_u16Address, u8 Copy_u8Data)
{
    /* Wait for completion of previous write */
    while (GET_BIT(EECR, EEWE));

    /* Set up address and data registers */
    EEARL = (u8)Copy_u16Address;
    EEARH = (u8)(Copy_u16Address >> 8);

    EEDR = Copy_u8Data;

    /* Write logical one to EEMWE */
    SET_BIT(EECR, EEMWE);

    /* Start eeprom write by setting EEWE */
    SET_BIT(EECR, EEWE);
}

u8 EEPROM_u8Read(u16 Copy_u16Address)
{
    /* Wait for completion of previous write */
    while (GET_BIT(EECR, EEWE));

    /* Set up address register */
    EEARL = (u8)Copy_u16Address;
    EEARH = (u8)(Copy_u16Address >> 8);

    /* Start eeprom read by writing EERE */
    SET_BIT(EECR, EERE);

    /* Return data from data register */
    return EEDR;
}
