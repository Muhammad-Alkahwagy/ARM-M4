/**
 * @file TFT_Program.c
 * @author Muhammad Alkahwagy
 * @brief TFT API's implementations
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "SPI_Interface.h"

#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"


static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
	/* DC is 0 for data */
	GPIO_voidSetPinValue( TFT_DC_PORT , TFT_DC_PIN , LOW );

	/* Send Command */
	SPI_u8TrancieveData( Copy_u8Command );
}

static void TFT_voidWriteData ( u8 Copy_u8Data )
{
	/* DC is 1 for data */
	GPIO_voidSetPinValue( TFT_DC_PORT , TFT_DC_PIN , HIGH );

	/* Send Data */
	SPI_u8TrancieveData( Copy_u8Data );
}

void TFT_voidInit(void)
{
	/*Rest Pulse*/
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH ) ;
	SYSTICK_voidSetBusyWaitms(100) ;
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,LOW) ;
	SYSTICK_voidSetBusyWaitms(1) ;
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH ) ;
	SYSTICK_voidSetBusyWaitms(100) ;
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,LOW) ;
	SYSTICK_voidSetBusyWaitms(100) ;
	GPIO_voidSetPinValue(TFT_RST_PORT,TFT_RST_PIN,HIGH ) ;
	SYSTICK_voidSetBusyWaitms(120) ;

	/*Send Command Sleep Out*/
	TFT_voidWriteCommand(0x11) ;

	/*wait 150 ms*/
	SYSTICK_voidSetBusyWaitms(150) ;

	/*color mode Command*/
	TFT_voidWriteCommand(0x3A) ;
	TFT_voidWriteData(0x05) ; //RGB565

	/*Display Command*/
	TFT_voidWriteCommand(0x29) ;
}

void TFT_voidDisplayImage(const u16 * Copy_ptrImage)
{
	u8 Data;
	/*Set X Address*/
	TFT_voidWriteCommand(0x2A) ;
	/*start*/
	TFT_voidWriteData(0) ;
	TFT_voidWriteData(0) ;
	/*stop*/
	TFT_voidWriteData(0) ;
	TFT_voidWriteData(127) ;

	/*Set y Address*/
	TFT_voidWriteCommand(0x2B) ;
	/*start*/
	TFT_voidWriteData(0) ;
	TFT_voidWriteData(0) ;
	/*stop*/
	TFT_voidWriteData(0) ;
	TFT_voidWriteData(159) ;

	/*RAM Write Command*/
	TFT_voidWriteCommand(0x2C) ;
	/*Display Image*/
	for(u16 counter = 0 ; counter < 20480 ; counter++)
	{
		Data  = Copy_ptrImage[counter] >> 8 ;
		/*write for high byte -->MSB*/
		TFT_voidWriteData(Data) ;

		Data  = Copy_ptrImage[counter] & 0x00FF ;
		/*write for high Low*/
		TFT_voidWriteData(Data) ;
	}
}
