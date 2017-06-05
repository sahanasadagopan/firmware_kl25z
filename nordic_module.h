/*
 * nordic_module.h
 *
 *  Created on: Jun 5, 2017
 *      Author: sahan
 */

#ifndef SOURCES_NORDIC_MODULE_H_
#define SOURCES_NORDIC_MODULE_H_

void spi0_init();
#define TEST_LOW GPIOC_PCOR |= GPIO_PCOR_PTCO(0x10)  //debug pin
#define TEST_HIGH GPIOC_PSOR |= GPIO_PSOR_PTSO(0x10) //debug pin
#define NRF_CS_ENABLE() (PTC_BASE_PTR->PCOR |= 1<<4)
#define NRF_CS_DISABLE() (PTC_BASE_PTR->PSOR |= 1<<4)
#define WAIT_SPTEF ( !(SPI_S_REG(SPI0) & SPI_S_SPTEF_MASK))
#define WAIT_SPRF  ( !(SPI_S_REG(SPI0) & SPI_S_SPRF_MASK))

unsigned char spi_send(char m);



#endif /* SOURCES_NORDIC_MODULE_H_ */
