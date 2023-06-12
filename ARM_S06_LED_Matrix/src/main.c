#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LED_Matrix_Interface.h"

u8 Heisenberg[8] = {1, 13, 237, 160, 160, 237, 13, 1};

void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*enable GPIO clock for PORT B*/
	RCC_voidEnablePeripheralClk(AHB1,1);

	SYSTICK_voidInit();

	LEDMatrix_voidInit();


	while(1)
	{
	LEDMatrix_voidDisplay(Heisenberg);
	}
}
