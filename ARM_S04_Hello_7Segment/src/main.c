/*Seven Segment Display*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "SSEG_Interface.h"


void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	SYSTICK_voidInit();

	/*configure port A as output*/
	//GPIO_voidSetPortMode(PORTA,OUTPUT_PUSH_PULL);
	SSEG_voidInit();

	while(1)
	{
		for(u8 i = 0; i<10; i++)
		{
			SSEG_voidSendDigit(i);
			SYSTICK_voidSetBusyWait(1000);

		}
	}
}
