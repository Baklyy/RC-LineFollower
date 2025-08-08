/*
 * TIM_private.h
 *
 *  Created on: Aug 2, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_TIM_TIM_PRIVATE_H_
#define MCAL_TIM_TIM_PRIVATE_H_

//TIMER0 #defines
#define TIM0_u8_TIMSK_REG	*((volatile u8*) 0x59)

#define TIM0_u8_TOIE_BIT		0
#define TIM0_u8_OCIE_BIT		1

#define TIM0_u8_TIFR_REG		*((volatile u8*) 0x58)

#define TIM0_u8_TOV0_BIT		0
#define TIM0_u8_OCR0_BIT		1

#define TIM0_u8_TCCR0_REG 	*((volatile u8*) 0x53)

#define TIM0_u8_FOC0_BIT		7
#define TIM0_u8_WGM00_BIT		6
#define TIM0_u8_COM01_BIT		5
#define TIM0_u8_COM00_BIT		4
#define TIM0_u8_WGM01_BIT   	3
#define TIM0_u8_CS02_BIT		2
#define TIM0_u8_CS01_BIT		1
#define TIM0_u8_CS00_BIT		0

#define TIM0_u8_COM_MASK	0b11001111


#define TIM0_u8_CLK_PRESCALER_MASK	0b11111000

#define TIM0_u8_TCNT0_REG	*((volatile u8*) 0x52)

#define TIM0_u8_OCR0_REG	*((volatile u8*) 0x5C)
//

//TIMER1 #define
#define TIM1_u8_TIMSK_REG	*((volatile u8*) 0x59)

#define TIM1_u8_TICIE1_BIT		5
#define TIM1_u8_OCIE1A_BIT		4
#define TIM1_u8_OCIE1B_BIT		3
#define TIM1_u8_TOIE1_BIT		2

#define TIM1_u8_TIFR_REG	*((volatile u8*) 0x58)

#define TIM1_u8_ICF1_BIT		5
#define TIM1_u8_OCF1A_BIT		4
#define TIM1_u8_OCF1B_BIT		3
#define TIM1_u8_TOV1_BIT		2

#define TIM1_u8_TCCR1A_REG	*((volatile u8*) 0x4F)

#define TIM1_u8_COM1A1_BIT		7
#define TIM1_u8_COM1A0_BIT		6
#define TIM1_u8_COM1B1_BIT		5
#define TIM1_u8_COM1B0_BIT		4
#define TIM1_u8_FOC1A_BIT		3
#define TIM1_u8_FOC1B_BIT		2
#define TIM1_u8_WGM11_BIT		1
#define TIM1_u8_WGM10_BIT		0

#define TIM1_u8_COM1A_MASK		0b00111111
#define TIM1_u8_COM1B_MASK		0b11001111

#define TIM1_u8_WGM11_10_MASK	0b11111100

#define TIM1_u8_TCCR1B_REG	*((volatile u8*) 0x4E)

#define TIM1_u8_ICNC1_BIT		7
#define TIM1_u8_ICES1_BIT		6
#define TIM1_u8_WGM13_BIT		4
#define TIM1_u8_WGM12_BIT		3
#define TIM1_u8_CS12_BIT		2
#define TIM1_u8_CS11_BIT		1
#define TIM1_u8_CS10_BIT		0

#define TIM1_u8_WGM13_12_MASK 	0b11100111

#define TIM1_u8_CLK_PRESCALER_MASK	0b11111000

#define TIM1_u8_TCNT1H_REG	*((volatile u8*) 0x4D)
#define TIM1_u8_TCNT1L_REG	*((volatile u8*) 0x4C)
#define TIM1_u8_OCR1AH_REG	*((volatile u8*) 0x4B)
#define TIM1_u8_OCR1AL_REG	*((volatile u8*) 0x4A)
#define TIM1_u8_OCR1BH_REG	*((volatile u8*) 0x49)
#define TIM1_u8_OCR1BL_REG	*((volatile u8*) 0x48)
#define TIM1_u8_ICR1H_REG	*((volatile u8*) 0x47)
#define TIM1_u8_ICR1L_REG	*((volatile u8*) 0x46)
//

//Timer2 #define
#define TIM2_u8_TIMSK_REG	*((volatile u8*) 0x59)

#define TIM2_u8_OCIE2_BIT		7
#define TIM2_u8_TOIE2_BIT		6

#define TIM2_u8_TIFR_REG	*((volatile u8*) 0x58)

#define TIM2_u8_OCF2_BIT		7
#define TIM2_u8_TOV2_BIT		6

#define TIM2_u8_TCCR2_REG	*((volatile u8*) 0x45)

#define	TIM2_u8_FOC2_BIT		7
#define	TIM2_u8_WGM20_BIT		6
#define	TIM2_u8_COM21_BIT		5
#define	TIM2_u8_COM20_BIT		4
#define	TIM2_u8_WGM21_BIT		3
#define	TIM2_u8_CS22_BIT		2
#define	TIM2_u8_CS21_BIT		1
#define	TIM2_u8_CS20_BIT		0

#define TIM2_u8_CLK_PRESCALER_MASK	0b11111000

#define TIM2_u8_COM_MASK			0b11001111

#define TIM2_u8_TCNT2_REG	*((volatile u8*) 0x44)
#define TIM2_u8_OCR2_REG	*((volatile u8*) 0x43)

//this register won't be used
#define TIM2_u8_ASSR_REG	*((volatile u8*) 0x42)
//

#endif /* MCAL_TIM_TIM_PRIVATE_H_ */
