/*
 * capacitive_touch.c
 *
 *  Created on: Jun 5, 2017
 *      Author: sahan
 */



#include "MKL25Z4.h"
#include "ADC.h"
#include "string.h"
static int i = 0;

void TSI_init()
{
	SIM_SCGC5 |= SIM_SCGC5_TSI_MASK; // Enabling TSI access control
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; // clock for portB

	TSI0_GENCS|=TSI_GENCS_MODE(0);
	TSI0_GENCS|=TSI_GENCS_REFCHRG(2);//2uA discharge
	TSI0_GENCS|=TSI_GENCS_DVOLT(0);//POWER RAIL:1.03V
	TSI0_GENCS|=TSI_GENCS_EXTCHRG(7);//64uA
	TSI0_GENCS|=TSI_GENCS_PS(2);//PRESCALER DIVIDE BY 4
	TSI0_GENCS|=TSI_GENCS_NSCN(15);//16 SCANS
	TSI0_GENCS|=TSI_GENCS_STPE_MASK;
	TSI0_GENCS|= TSI_GENCS_TSIEN_MASK;
	
	PORTB_PCR16 = PORT_PCR_MUX(0);      // PTB16 as touch channel 9
	PORTB_PCR17 = PORT_PCR_MUX(0);      // PTB17 as touch channel 10
}

void TSI_Start(int CH_IP)
{
	TSI0_DATA|=TSI_DATA_TSICH(CH_IP);// selecting TSI channel through the Data register
	TSI0_DATA|=TSI_DATA_SWTS_MASK;// Start scanning 
}

uint16_t TSI_Stop_check()
{
	TSI0_GENCS |= TSI_GENCS_EOSF_MASK; // checking for software aknowledgement 
	return TSI0_DATA & TSI_DATA_TSICNT_MASK; // return the Data value and the scan counter value got by the oscilator
}
