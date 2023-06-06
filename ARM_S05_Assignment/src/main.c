	/*NVIC_Assignment1*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "NVIC_Interface.h"
#include "SSEG_Interface.h"


void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*enable GPIO clock for PORT B*/
	RCC_voidEnablePeripheralClk(AHB1,1);

	SYSTICK_voidInit();

	SSEG1_voidInit();
	SSEG2_voidInit();

	GPIO_voidSetPortMode(PORTB,OUTPUT_PUSH_PULL);	//LEDs

	NVIC_voidEnablePeripheralInterrupt(7);	//EXTI1
	NVIC_voidEnablePeripheralInterrupt(35);	//SPI1
	NVIC_voidEnablePeripheralInterrupt(37);	//USART1

	while(1)
	{
		NVIC_voidSetPendingFlag(7);
		NVIC_voidSetPendingFlag(35);
		NVIC_voidSetPendingFlag(37);
	}
}

void EXTI1_IRQHandler(void)
{
	//LED animation
	for(u8 i =0; i<8; i++)
	{
		GPIO_voidSetByteValue(PORTB,LOW_BYTE,0x01<<i);
		SYSTICK_voidSetBusyWait(250);
	}

}

void SPI1_IRQHandler(void)
{
	//7-SEG1 up-counting
	for(u8 i = 0; i<10; i++)
	{
		SSEG1_voidSendDigit(i);
		SYSTICK_voidSetBusyWait(1000);
	}
}


void USART1_IRQHandler(void)
{
	//7-SEG2 down-counting
	for(u8 i = 0; i<=9; i++)
	{
		SSEG2_voidSendDigit(9-i);
		SYSTICK_voidSetBusyWait(1000);
	}
}
