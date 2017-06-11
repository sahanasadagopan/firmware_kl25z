/*
 * ADC.h
 *
 *  Created on: Jun 4, 2017
 *      Author: sahan
 */

#ifndef SOURCES_ADC_H_
#define SOURCES_ADC_H_
void adc_init(void);
unsigned short adc_read();
int adc_calibrate();
#endif /* SOURCES_ADC_H_ */
