/*
 * KPD_config.h
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define KPD_u8_NUM_OF_ROWS 		4
#define KPD_u8_NUM_OF_COLUMNS 	4

#define KPD_u8_PORT			DIO_u8_PORTB

#define KPD_u8_ROW_PIN0		DIO_u8_PIN0
#define KPD_u8_ROW_PIN1		DIO_u8_PIN1
#define KPD_u8_ROW_PIN2		DIO_u8_PIN2
#define KPD_u8_ROW_PIN3		DIO_u8_PIN3


#define KPD_u8_COLUMN_PIN0	DIO_u8_PIN4
#define KPD_u8_COLUMN_PIN1	DIO_u8_PIN5
#define KPD_u8_COLUMN_PIN2	DIO_u8_PIN6
#define KPD_u8_COLUMN_PIN3	DIO_u8_PIN7


#define KPD_u8_INITIAL_LAYOUT 	KPD_u8_NUMBERS_LAYOUT

#endif /* HAL_KPD_KPD_CONFIG_H_ */
