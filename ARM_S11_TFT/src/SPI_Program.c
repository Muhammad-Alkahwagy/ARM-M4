/**
 * @file SPI_Program.c
 * @author Muhammad Alkahwagy
 * @brief SPI APIs' implementations
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
/*static void (*SPI1_CallBack)(void) = NULL ;*/

void SPI_voidInit()
{
/*  
    // 2 Line unidirectional data mode selection
	CLR_BIT(SPI1->CR1,15);
	CLR_BIT(SPI1->CR1,14);

	//Disable CRC
	CLR_BIT(SPI1->CR1,13);
	CLR_BIT(SPI1->CR1,12);

	//Data Frame Format ->8-bit
	CLR_BIT(SPI1->CR1,11);

	//Full Duplex
	CLR_BIT(SPI1->CR1,10);

	//SW Slave Management Enable
	SET_BIT(SPI1->CR1,9);
    
	//Internal Slave Select->Master
	SET_BIT(SPI1->CR1,8);

	//LSB Mode
	CLR_BIT(SPI1->CR1,7);

	//BaudRate Prescaler ->clk/2 
	CLR_BIT(SPI1->CR1,5);
	CLR_BIT(SPI1->CR1,4);
	CLR_BIT(SPI1->CR1,3);

	//Master Select
	SET_BIT(SPI1->CR1,2);

	//CLK Polarity -> Idle High-> Falling Edge
	SET_BIT(SPI1->CR1,1);

	//CLK Phase ->Write then Read->Second clk transition
	SET_BIT(SPI1->CR1,0);

	//SPI Enable
	SET_BIT(SPI1->CR1,6);
 */	
	SPI1->CR1 = 0x0347;
}


u8 SPI_u8TrancieveData(u8 Copy_u8Data)
{
 	 /*Clear for Slave Select*/
	GPIO_voidSetPinValue(PORTA,PIN0,LOW) ;
  	/*Send Data*/
	SPI1->DR = Copy_u8Data ;
 	 /*wait Busy flag to finish*/
	while(GET_BIT(SPI1->SR,7)) ;
	/*Set for Slave Select*/
	GPIO_voidSetPinValue(PORTA,PIN0,HIGH) ;
	/*return to data register*/
	return (u8)SPI1->DR ;

}


/*void SPI_voidSetCallBack(void (*Fptr)(void))
{
   SPI1_CallBack = Fptr ;
}*/
