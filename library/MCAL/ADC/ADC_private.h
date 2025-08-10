/*
 * ADC_private.h
 *
 *  Created on: Jul 24, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADC_u8_ADMUX_REG	*((volatile u8*)0x27)

#define ADC_u8_MUX0 	0
#define ADC_u8_MUX1 	1
#define ADC_u8_MUX2 	2
#define ADC_u8_MUX3 	3
#define ADC_u8_MUX4 	4
#define ADC_u8_ADLAR 	5
#define ADC_u8_REFS0 	6
#define ADC_u8_REFS1 	7

#define ADC_u8_MUX_MASK 		0b11100000

#define ADC_u8_REF_VOLT_MASK	0b00111111

#define ADC_u8_ADCSRA_REG	*((volatile u8*)0x26)

#define ADC_u8_ADEN 	7
#define ADC_u8_ADSC 	6
#define ADC_u8_ADATE	5
#define ADC_u8_ADIF 	4
#define ADC_u8_ADIE 	3
#define ADC_u8_ADPS2	2
#define ADC_u8_ADPS1	1
#define ADC_u8_ADPS0	0


#define ADC_u8_PRESCALAR_MASK 	0b11111000

#define ADC_u8_ADCH_REG		*((volatile u8*)0x25)
#define ADC_u8_ADCL_REG		*((volatile u8*)0x24)

#define ADC_u8_SFIOR_REG	*((volatile u8*)0x50)

#define ADC_u8_TRIGGER_SOURCE_MASK 	0b00011111

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
