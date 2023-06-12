/*Hello Audio*/


#include "lalala.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

//#include "FreeRTOS.h"
//#include "task.h"


void Audio(void)
{

	static u32 i = 0 ;
	while(1)
	{
		GPIO_voidSetByteValue(PORTA,LOW_BYTE,lalala_raw[i]);
		i++;

		if(i == lalala_raw_len)
		{
			i=0;
		}
		//vTaskDelay(125);
	}
}

void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT B*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	GPIO_voidSetPortMode(PORTA,OUTPUT_PUSH_PULL);

	SYSTICK_voidInit();

	SYSTICK_voidSetIntervalPeriodic(125,Audio);
	//SYSTICK_voidSetIntervalSingle(125,Audio);

/* 	//create task1
	xTaskCreate(Audio,NULL,100,NULL,0,NULL);
	//Start OS
	vTaskStartScheduler();
 */
	while(1)
		;
}
