#include "MKL25Z4.h"
#include "core_cmFunc.h"
#include <stdio.h>

#include "nordic_module.h"

void spi0_init()

{
	int baud_divisor;
	//SPI0_C1|=~(SPI_C1_SPE_MASK);//disable spi
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK; // enabling the clock and the gate for spi
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // giving clock and gate to the port


	//GPIOC_PSOR |=GPIO_PDOR_PDO(0x10);
	//GPIOC_PDDR |= GPIO_PDDR_PDD(0x10);
	PORTC_PCR4 = PORT_PCR_MUX(1); // PCS0
	PORTC_PCR5 = PORT_PCR_MUX(2); //alt 2
	PORTC_PCR6 = PORT_PCR_MUX(2); //MOSI
	PORTC_PCR7 = PORT_PCR_MUX(2);
	PTC_BASE_PTR->PDDR |= 1<<4;

	//GPIOC_PSOR |=GPIO_PDOR_PDO(0x10);
	//GPIOC_PDDR |= GPIO_PDDR_PDD(0x10);
	/*PORTD_PCR0 = PORT_PCR_MUX(1); // PCS0
	PORTD_PCR1 = PORT_PCR_MUX(2); //alt 2
	PORTD_PCR2 = PORT_PCR_MUX(2); //MOSI
	PORTD_PCR3 = PORT_PCR_MUX(2);
	PTD_BASE_PTR->PDDR |= 1<<4;*/


	SPI0_C1 = 0x50;
	SPI0_BR = 0x03;
}

unsigned char spi_send(char m)
{
	uint8_t ch =0;

//	 while(WAIT_SPTEF);
	SPI0_D=m;

//	 while(WAIT_SPRF);
	 ch=SPI0_D;

	while(WAIT_SPTEF);
	SPI0_D=0xFF;

	 while(WAIT_SPRF);
	 ch=SPI0_D;
  return m;
}

