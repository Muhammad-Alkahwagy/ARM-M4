#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"


void main()
{

	/*step1: sys clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	SYSTICK_voidInit();

	/*step2: enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*step3: configure pin A0 as output*/
	GPIO_voidSetPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL);
	GPIO_voidSetPinSpeed(PORTA,PIN0,LOW_SPEED);

	while(1)
	{

		/*step5: toggle LED*/
		GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
		SYSTICK_voidSetBusyWait(2000000);

		GPIO_voidSetPinValue(PORTA,PIN0,LOW);
		SYSTICK_voidSetBusyWait(2000000);
	}
}
