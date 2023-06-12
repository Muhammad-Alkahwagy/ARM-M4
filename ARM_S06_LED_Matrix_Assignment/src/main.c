#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LED_Matrix_Interface.h"

u8 Muhammad[] = {254, 2, 4, 248, 4, 2, 254, 0, 0, 0, 120, 128, 128, 128, 120, 0, 0, 0, 255, 16, 8, 8, 248, 0, 0, 0, 112, 136, 136, 72, 240, 0,
                  0, 0, 248, 8, 248, 8, 240, 0, 0, 0, 248, 8, 248, 8, 240, 0, 0, 0, 112, 136, 136, 72, 240, 0, 0, 0, 112, 136, 136, 136, 255, 0};
u8 M[8] = {254, 2, 4, 248, 4, 2, 254, 0};
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

		LEDMatrix_voidDisplayAnimation(Muhammad,64);
		//LEDMatrix_voidDisplay(M);
	}
}

