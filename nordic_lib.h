/*
 * nordic_lib.h
 *
 *  Created on: Jun 5, 2017
 *      Author: sahan
 */

#ifndef SOURCES_NORDIC_LIB_H_
#define SOURCES_NORDIC_LIB_H_


#include <stdio.h>
#include <stdint.h>
#define __IO volatile

/** Peripheral NORDIC base address */
#define NORDIC_BASE                                (0x00u)
/** Peripheral NORDIC base pointer */
#define NORDIC                                     ((NORDIC_Type *)NORDIC_BASE)
#define NORDIC_BASE_PTR                            (NORDIC)
#define NORDIC_BASE_ADDRS							{ NORDIC_BASE }
#define NORDIC_BASE_PTRS                            { NORDIC }

typedef struct{
  __IO uint8_t NORDIC_CONFIG;
  __IO uint8_t NORDIC_EN_AA;
  __IO uint8_t NORDIC_EN_RXADDR;
  __IO uint8_t NORDIC_SETUP_AW;
  __IO uint8_t NORDIC_SETUP_RETR;
  __IO uint8_t NORDIC_RF_CH;
  __IO uint8_t NORDIC_RF_SETUP;
  __IO uint8_t NORDIC_STATUS;
  __IO uint8_t NORDIC_OBSERVE_TX;
  __IO uint8_t NORDIC_CD;
  __IO uint8_t NORDIC_RX_ADDR_P0;
  __IO uint8_t NORDIC_RX_ADDR_P1;
  __IO uint8_t NORDIC_RX_ADDR_P2;
  __IO uint8_t NORDIC_RX_ADDR_P3;
  __IO uint8_t NORDIC_RX_ADDR_P4;
  __IO uint8_t NORDIC_RX_ADDR_P5;
  __IO uint8_t NORDIC_TX_ADDR;
  __IO uint8_t NORDIC_RX_PW_P0;
  __IO uint8_t NORDIC_RX_PW_P1;
  __IO uint8_t NORDIC_RX_PW_P2;
  __IO uint8_t NORDIC_RX_PW_P3;
  __IO uint8_t NORDIC_RX_PW_P4;
  __IO uint8_t NORDIC_RX_PW_P5;
  __IO uint8_t NORDIC_FIFO_STATUS;
  	  		uint8_t RESERVED_1[5];
  __IO uint8_t NORDIC_DYNPD;
  __IO uint8_t NORDIC_FEATURE;
} NORDIC_Type, *NORDIC_MemMapPtr;


/* SPI - Register accessors */
#define NORDIC_CONFIG(base)          ((base)->CONFIG)
#define NORDIC_EN_AA(base)           ((base)->EN_AA)
#define NORDIC_EN_RX_ADDR(base)      ((base)->EN_RX_ADDR)
#define NORDIC_SETUP_AW(base)        ((base)->SETUP_AW)
#define NORDIC_SETUP_RETR(base)      ((base)->SETUP_RETR)
#define NORDIC_RF_CH(base)           ((base)->RF_CH)
#define NORDIC_RF_SETUP(base)        ((base)->RF_SETUP)
#define NORDIC_OBSERVE_TX(base)      ((base)->OBSERVE_TX)
#define NORDIC_CD(base)              ((base)->CD)
#define NORDIC_RX_ADDR_P0(base)      ((base)->RX_ADDR_P0)
#define NORDIC_RX_ADDR_P1(base)      ((base)->RX_ADDR_P1)
#define NORDIC_RX_ADDR_P2(base)      ((base)->RX_ADDR_P2)
#define NORDIC_RX_ADDR_P3(base)      ((base)->RX_ADDR_P3)
#define NORDIC_RX_ADDR_P4(base)      ((base)->RX_ADDR_P4)
#define NORDIC_RX_ADDR_P5(base)      ((base)->RX_ADDR_P5)
#define NORDIC_FIFO_STATUS(base)     ((base)->FIFO_STATUS)
#define NORDIC_ACK_PLD(base)         ((base)->ACK_PLD)
#define NORDIC_TX_PLD(base)          ((base)->TX_PLD)
#define NORDIC_RX_PLD(base)          ((base)->RX_PLD)
#define NORDIC_DYNPD(base)           ((base)->DYNPD)
#define FEATURE(base)                ((base)->FEATURE)

//REGISTER MAP
#define NORDIC_CONFIG_BASE		(0x00)
#define NORDIC_EN_AA_BASE		(0X01)
#define NORDIC_EN_RXADDR_BASE	(0X02)
#define NORDIC_SETUP_AW_BASE	(0x03)
#define NORDIC_SETUP_RETR_BASE	(0x04)
#define NORDIC_RF_CH_BASE		(0x05)
#define NORDIC_RF_SETUP_BASE	(0x06)
#define NORDIC_STATUS_BASE		(0x07)
#define NORDIC_OBSERVE_TX_BASE	(0x08)
#define NORDIC_CD_BASE			(0x09)
#define NORDIC_RX_ADDR_P0_BASE	(0x0A)
#define NORDIC_RX_ADDR_P1_BASE	(0x0B)
#define NORDIC_RX_ADDR_P2_BASE	(0x0C)
#define NORDIC_RX_ADDR_P3_BASE	(0x0D)
#define NORDIC_RX_ADDR_P4_BASE	(0x0E)
#define NORDIC_RX_ADDR_P5_BASE	(0x0F)
#define NORDIC_TX_ADDR_BASE		(0x10)
#define NORDIC_RX_PW_P0_BASE	(0x11)
#define NORDIC_RX_PW_P1_BASE	(0x12)
#define NORDIC_RX_PW_P2_BASE	(0x13)
#define NORDIC_RX_PW_P3_BASE	(0x14)
#define NORDIC_RX_PW_P4_BASE	(0x15)
#define NORDIC_RX_PW_P5_BASE	(0x16)
#define NORDIC_FIFO_STATUS_BASE (0x17)
#define NORDIC_DYNPD_BASE		(0x1C)
#define NORDIC_FEATURE_BASE		(0x1D)

#define NORDIC_CONFIG_MASK_RX_DR(x)       (((uint8_t)(x))<<6)
#define NORDIC_CONFIG_MASK_TX_DS(x)       (((uint8_t)(x))<<5)
#define NORDIC_CONFIG_MASK_MAX_RT(x)      (((uint8_t)(x))<<4)
#define NORDIC_CONFIG_MASK_EN_CRC(x)      (((uint8_t)(x))<<3)
#define NORDIC_CONFIG_MASK_CRCO(x)        (((uint8_t)(x))<<2)
#define NORDIC_CONFIG_MASK_PWR_UP(x)      (((uint8_t)(x))<<1)
#define NORDIC_CONFIG_MASK_PRIM_RX(x)     (((uint8_t)(x))<<0)
//
#define NORDIC_ENAA_P5(x)				(((uint8_t)(x))<<5)
#define NORDIC_ENAA_P4(x)				(((uint8_t)(x))<<4)
#define NORDIC_ENAA_P3(x)				(((uint8_t)(x))<<3)
#define NORDIC_ENAA_P2(x)				(((uint8_t)(x))<<2)
#define NORDIC_ENAA_P1(x)				(((uint8_t)(x))<<1)
#define NORDIC_ENAA_P0(x)				(((uint8_t)(x))<<0)
//
#define NORDIC__EN_RX_ADDR_ERX_P5(x)	(((uint8_t)(x))<<5)
#define NORDIC__EN_RX_ADDR_ERX_P4(x)	(((uint8_t)(x))<<4)
#define NORDIC__EN_RX_ADDR_ERX_P3(x)	(((uint8_t)(x))<<3)
#define NORDIC__EN_RX_ADDR_ERX_P2(x)	(((uint8_t)(x))<<2)
#define NORDIC__EN_RX_ADDR_ERX_P1(x)	(((uint8_t)(x))<<1)
#define NORDIC__EN_RX_ADDR_ERX_P0(x)	(((uint8_t)(x))<<0)
//
#define NORDIC_SETUP_AW_AW(x)           (((uint8_t)(x))<<1)
//
#define NORDIC_SETUP_RETR_ARD(x)        (((uint8_t)(x))<<7)
#define NORDIC_SETUP_RETR_ARC(x)        (((uint8_t)(x))<<3)
//
#define NORDIC_RF_CH_RF_CH(x)            (((uint8_t)(x))<<6)
//
#define NORDIC_RF_SETUP_PLL_LOCK(x)      (((uint8_t)(x))<<4)
#define NORDIC_RF_SETUP_RF_DR(x)         (((uint8_t)(x))<<3)
#define NORDIC_RF_SETUP_RF_PWR(x)        (((uint8_t)(x))<<2)
#define NORDIC_RF_SETUP_LNA_HCURR(x)     (((uint8_t)(x))<<1)
//
#define NORDIC_STATUS_RX_DR(x)            (((uint8_t)(x))<<6)
#define NORDIC_STATUS_TX_DS(x)            (((uint8_t)(x))<<5)
#define NORDIC_STATUS_MAX_RT(x)           (((uint8_t)(x))<<4)
#define NORDIC_STATUS_RX_P_NO(x)          (((uint8_t)(x))<<3)
#define NORDIC_STATUS_TX_FULL(x)          (((uint8_t)(x))<<0)
//
#define NORDIC_OBSERVE_TX_PLOS_CNT(x)     (((uint8_t)(x))<<7)
#define NORDIC_OBSERVE_ARC_CNT(x)         (((uint8_t)(x))<<3)
//
#define NORDIC_OBSERVE_CD_CD(x)           (((uint8_t)(x))<<0)
//

/*#define NORDIC_RX_ADDR_P0(x)              (((uint8_t)(x)<<39))
//
#define NORDIC_RX_ADDR_P1(x)              (((uint8_t)(x)<<39))
//
#define NORDIC_RX_ADDR_P2(x)              (((uint8_t)(x)<<7))
//
#define NORDIC_RX_ADDR_P3(x)              (((uint8_t)(x)<<7))
//
#define NORDIC_RX_ADDR_P4(x)              (((uint8_t)(x)<<7))
//
#define NORDIC_RX_ADDR_P5(x)              (((uint8_t)(x)<<7))*/
//
#define NORDIC_TX_ADDR(x)                 (((uint8_t)(x)<<39))
//
#define NORDIC_RX_PW_P0(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_RX_PW_P1(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_RX_PW_P2(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_RX_PW_P3(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_RX_PW_P4(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_RX_PW_P5(x)                (((uint8_t)(x))<<5)
//
#define NORDIC_DPL_P5(x)				(((uint8_t)(x))<<5)
#define NORDIC_DPL_P4(x)				(((uint8_t)(x))<<4)
#define NORDIC_DPL_P3(x)				(((uint8_t)(x))<<3)
#define NORDIC_DPL_P2(x)				(((uint8_t)(x))<<2)
#define NORDIC_DPL_P1(x)				(((uint8_t)(x))<<1)
#define NORDIC_DPL_P0(x)				(((uint8_t)(x))<<0)
//
#define NORDIC_EN_DPL(x)				(((uint8_t)(x))<<2)
#define NORDIC_EN_ACK_PAY(x)			(((uint8_t)(x))<<1)
#define NORDIC_EN_DYN_ACK(x)			(((uint8_t)(x))<<0)



#define NORDIC_STATUS_TX_DS(x)            (((uint8_t)(x))<<5)
#define NORDIC_STATUS_MAX_RT(x)           (((uint8_t)(x))<<4)
#define NORDIC_STATUS_RX_P_NO(x)          (((uint8_t)(x))<<3)
//#define NORDIC_STATUS_TX_FULL(x)          (((uint8_t)(x))<<6)

//spi commands
#define NORDIC_R_REGISTER     (0x00)
#define NORDIC_W_REGISTER     (0x20)
#define NORDIC_R_RX_PAYLOAD   (0x61)
#define NORDIC_W_TX_PAYLOAD   (0xA0)
#define NORDIC_FLUSH_TX       (0xE1)
#define NORDIC_FLUSH_RX       (0xE2)
#define NORDIC_REUSE_TX_PL    (0xE3)
#define NORDIC_NOP            (0xFF)

void nrf_config();
void nrf_read_register(unsigned char address);
void nrf_write_register(unsigned char address);
void nrf_write_multiple(uint8_t register1, uint8_t *loc, uint8_t size);
void nrf_flush_tx();
void nrf_set_tx_address();
void nrf_transmit_data(uint8_t *write);
void CE_HIGH();
void CE_LOW();
void nrf_config_read();
void nrf_config_write();
uint8_t proffoz_nrf_status_read();

#endif /* SOURCES_NORDIC_LIB_H_ */
