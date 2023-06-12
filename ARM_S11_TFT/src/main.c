/**
 * @file main.c
 * @author Muhammad Alkahwagy
 * @brief 
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "SPI_Interface.h"
#include "TFT_Interface.h"
#include "mo.h"

void main()
{

	/*Step 1 : System Clock is 16 MHz From HSI*/
	RCC_voidInitSysClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*Step 3 : Enable SPI1 Peripherial Clock */
	RCC_voidEnablePeripheralClk(APB2,12);

	/*Step 4 : Set Pin Direction ->> Output [CS - RST - A0]*/
	for(u8 i = 0 ; i < 3 ; i++)
	{
		GPIO_voidSetPinMode(PORTA,i,OUTPUT_PUSH_PULL);
	}


	/*Step 5 : Configure SPI PIN*/
	GPIO_voidSetPinMode(PORTA,PIN5,ALTERNATE_FUNC);  // SPI1 serial clock
	GPIO_voidSetPinMode(PORTA,PIN7,ALTERNATE_FUNC);  // SPI1 MOSI
	GPIO_voidSetPinAlternativeFunNo(PORTA,PIN5,AF5);  // SPI1 serial clock
	GPIO_voidSetPinAlternativeFunNo(PORTA,PIN7,AF5);  // SPI1 MOSI

	/*Step 6 : init SPI */
	SPI_voidInit();

	/*Step 7 : init TFT */
	TFT_voidInit();

   /*Step 8 : Display Image*/
	TFT_voidDisplayImage(image_mo);


	while(1)
	{
	}
}
