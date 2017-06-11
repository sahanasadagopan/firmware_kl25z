/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include "ADC.h"
static int i = 0;

void adc_init()
{
	//Enabling the Clocks
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;	// ADC 0 clock
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	// PTB0 clock
	adc_calibrate();
	ADC0_CFG1 = 0; // Reset register

	
	ADC0_CFG1 = ADC_CFG1_ADICLK(0)|//Bus clock selected
					    ADC_CFG1_MODE(3)|//16 bit mode for conversion(resolution)
					    ADC_CFG1_ADIV(1);//clock div
	
	ADC0_CFG2 |= ADC_CFG2_ADLSTS(3);
			ADC0_SC3 = 0; // Reset SC3
	ADC0_SC2  |= ADC_SC2_DMAEN_MASK;//Activating DMA
	ADC0_SC1A =31;
	ADC0_SC1A =26;
		

	}

	int adc_calibrate()
	{
		ADC0_CFG1 = ADC_CFG1_ADICLK(0)|//Bus clock selected
				    ADC_CFG1_MODE(3)|//16 bit mode for conversion(resolution)
				    ADC_CFG1_ADIV(1)|//clock div
					ADC_CFG1_ADLPC_MASK |
					ADC_CFG1_ADLSMP_MASK ;

			ADC0_SC3 |= ADC_SC3_AVGE_MASK |		// Enable HW average
						ADC_SC3_AVGS(3)   |		// Set HW average of 32 samples
						ADC_SC3_CAL_MASK|      //Start calibration process
						ADC_SC3_ADCO_MASK;		// Continous Conversion Enabled


			uint16_t calib = 0; // calibration variable

		while(ADC0_SC3 & ADC_SC3_CAL_MASK); // Wait for calibration to end

		if(ADC0_SC3 & ADC_SC3_CALF_MASK)	// Check for successful calibration
			return 1;



		calib = ADC0_CLPS + ADC0_CLP4 + ADC0_CLP3 +
			 ADC0_CLP2 + ADC0_CLP1 + ADC0_CLP0;
			calib /= 32;
			calib |= 0x8000; 	// Set MSB

		ADC0_PG = calib;
		calib = 0;
		calib += ADC0_CLMS + ADC0_CLM4 + ADC0_CLM3 +
				 ADC0_CLM2 + ADC0_CLM1 + ADC0_CLM0;
		calib /= 32;
		calib |= 0x8000;	// Set MSB
		ADC0_MG = calib;

		return 0;
	}

	uint16_t adc_read()
	{
		//adc_init();
		ADC0_SC1A = 0x9A;     // Write to SC1A to start conversion
		while(ADC0_SC2 & ADC_SC2_ADACT_MASK); 	 // Conversion in progress
		while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Run until the conversion is complete
		return ADC0_RA;
	}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
