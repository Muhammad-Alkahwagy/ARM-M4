#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

void APP_voidDelayMs(u32 Copy_u32Delay);

#define GPIOA_MODER	   (*((volatile u32*)(0x40020000)))

#define GPIOA_ODR	   (*((volatile u32*)(0x40020014)))


void main()
{


	/*step1: sys clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*step2: enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(0,0);

	/*step3: configure pin A0 as output*/
	SET_BIT(GPIOA_MODER,0);

	/*step4: configure pin A0 as HIGH*/
	SET_BIT(GPIOA_ODR, 0);

	while(1)
	{

		/*step5: toggle LED*/
		SET_BIT(GPIOA_ODR,0);
		APP_voidDelayMs(10000);

		CLR_BIT(GPIOA_ODR,0);
		APP_voidDelayMs(10000);
	}
}

void APP_voidDelayMs(u32 Copy_u32Delay)
{
	for(u32 i = 0 ; i< Copy_u32Delay *300 ; i++ )
	{
		asm("NOP");
	}
}
