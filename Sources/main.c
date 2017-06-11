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
#include "nordic_lib.h"
void main()
	{
		int temp_1,temp_2,temp_3;
		uint16_t temp;
		// initialising the adc module
		adc_init();
		float temperature, temp1;
		// The value from the adc got
		temp=adc_read();
		// calculation for temperature coversion
		temp1 = (int)((3.3 / 65536) * temp * 1000);
		temperature = 25 - ((temp1 - 716) / 1620);
		int  y;

		TSI_init();// initialising TSI module
		    uint16_t count;
		    uint16_t k=0;
		    int tap=0;
		    while(1)
		    {
		   
		    	TSI_Start(9);// start to scan
		    	
		    	while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK)); // checked for the oscillator value
		    	count = TSI_Stop_check();// stoped scanning
		    	count = count;
                if(count>0x26){
		    	
		    	uint8_t k[32]={temperature, temperature, temperature};
		    	uint8_t *k_ptr;
		    	k_ptr=k;
		    	spi0_init();
		    	spi_send(temperature);// sending the temperature value through SPI
		    	nrf_transmit_data(k_ptr);// THE NORDIC transmits value
                tap=tap+1;
                }

		    }


	}




