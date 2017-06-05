/*
 * main.c
 *
 *  Created on: Jun 5, 2017
 *      Author: sahan
 */
#include "MKL25Z4.h"
#include "ADC.h"
# include "capacitive_touch.h"
#include "nordic_module.h"
void main()
	{
		int temp_1,temp_2,temp_3;
		uint16_t temp;
		adc_init();
		float temperature, temp1;
		temp=adc_read();
		temp1 = (int)((3.3 / 65536) * temp * 1000);
		temperature = 25 - ((temp1 - 716) / 1620);
		int  y;

		TSI_init();
		    uint16_t count;
		    uint16_t k=0;
		    while(1)
		    {
		    	//TSI_Start(11);
		    	TSI_Start(9);
		    	while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK));
		    //	count = TSI_Stop_check();
		    	count = count;
		    	spi_send(temperature);
		    }


	}




