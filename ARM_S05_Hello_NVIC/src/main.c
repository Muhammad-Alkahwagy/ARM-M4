/*Hello_NVIC*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "NVIC_Interface.h"


void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	SYSTICK_voidInit();

	GPIO_voidSetPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL);

	NVIC_voidEnablePeripheralInterrupt(6);


	while(1)
	{
		NVIC_voidSetPendingFlag(6);
	}
}

void EXTI0_IRQHandler(void)
{
	GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
	SYSTICK_voidSetBusyWait(200);
	
	GPIO_voidSetPinValue(PORTA,PIN0,LOW);
	SYSTICK_voidSetBusyWait(200);

}
