/*
 * nordic_lib.c
 *
 *  Created on: Jun 5, 2017
 *      Author: sahan
 */

# include "nordic_lib.h"
# include "nordic_module.h"

#include "MKL25Z4.h"
// initialising nordic module
void nrf_config(){
	NORDIC_CONFIG_MASK_PWR_UP(1);

}

void nrf_write_register(unsigned char address){
     spi_send(0x00|NORDIC_RX_ADDR_P0_BASE);
}
void nrf_write_tx_address(unsigned char address){
	 spi_send(0X00|NORDIC_W_TX_PAYLOAD);
}

void nrf_read_register(unsigned char address){
	spi_send(0x00|address);

}


void nrf_flush_tx(){
	TEST_LOW;
	spi_send(0xE2);
	TEST_HIGH;
}
//transmitting data from nordic
void nrf_transmit_data(uint8_t *write){
	uint8_t ch=0;
	uint8_t l=32;
	NRF_CS_DISABLE();
	NRF_CS_ENABLE();

	WAIT_SPTEF;
	SPI0_D=NORDIC_W_TX_PAYLOAD;
	WAIT_SPRF;
	ch=SPI0_D;
while (l>0)
{
	WAIT_SPTEF;
	SPI0_D= *write;
	WAIT_SPRF;
	ch= SPI0_D;
	l--;
	write++;
}
}

void nrf_config_write() //write to the config register
{
//	while(WAIT_SPTEF);
	//SPI0_D = 0xFF;
	NRF_CS_DISABLE();
	NRF_CS_ENABLE();
	//TEST_HIGH;
	//TEST_LOW; //toggle CS
	nrf_write_register(NORDIC_CONFIG_BASE);
	spi_send(0x03);

}



