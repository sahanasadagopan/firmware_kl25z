#include "MKL25Z4.h"
#include "core_cmFunc.h"
#include <stdio.h>

#include "nordic_module.h"

void spi0_init()

{
	int baud_divisor;
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK; // enabling the clock and the gate for spi
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // giving clock and gate to the port
	PORTC_PCR4 = PORT_PCR_MUX(1); // PCS0
	PORTC_PCR5 = PORT_PCR_MUX(2); //alt 2
	PORTC_PCR6 = PORT_PCR_MUX(2); //MOSI
	PORTC_PCR7 = PORT_PCR_MUX(2);
	PTC_BASE_PTR->PDDR |= 1<<4;
	SPI0_C1 = SPI_C1_SPE_MASK|SPI_C1_MSTR_MASK ;//Enable master and enable SPI0
	SPI0_BR = SPI_BR_SPR(3)|SPI_BR_SPPR(0); // Setting the baud rate
}

unsigned char spi_send(char m)
{
	uint8_t ch =0;
	SPI0_D=m;

//	 while(WAIT_SPRF);
	 ch=SPI0_D;

	while(WAIT_SPTEF);
	SPI0_D=0xFF;

	 while(WAIT_SPRF);
	 ch=SPI0_D;
  return m;
}

