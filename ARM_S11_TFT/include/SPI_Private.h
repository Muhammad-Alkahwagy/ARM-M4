/**
 * @file SPI_Interface.h
 * @author Muhammad Alkahwagy
 * @brief SPI registers and private macros
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*File Guard*/  
#ifndef MCAL_SPI_PRIVATE_H
#define MCAL_SPI_PRIVATE_H

typedef struct {

	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;

}SPI;

#define SPI1 ((volatile SPI*)0x40013000)



#endif

