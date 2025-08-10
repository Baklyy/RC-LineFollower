/*
 * WD_private.h
 *
 *  Created on: Jul 29, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_WD_WD_PRIVATE_H_
#define MCAL_WD_WD_PRIVATE_H_

#define WD_u8_WDTCR_REG		*((volatile u8*) 0x41)

#define WD_u8_WDTOE_BIT		4
#define WD_u8_WDE_BIT		3
#define WD_u8_WDP2_BIT		2
#define WD_u8_WDP1_BIT		1
#define WD_u8_WDP0_BIT		0

#define WD_u8_WATCH_DISABLE_MASK	0b00011000

#define WD_u8_PRESCALER_MASK		0b11111000

#endif /* MCAL_WD_WD_PRIVATE_H_ */
