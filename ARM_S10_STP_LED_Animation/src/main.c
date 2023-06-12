/**
 * @file main.c
 * @author Muhammad Alkahwagy
 * @brief Serial to parallel LED Animation
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "STP_Interface.h"


int main()
{
    /* Configure the system clock */
    RCC_voidInitSysClk();

    /*Enable clock for GPIOA*/
    RCC_voidEnablePeripheralClk(AHB1,0);

    /*Systick init*/
    SYSTICK_voidInit();

    /*STP init*/
    STP_voidInit();

    while(1)
    {
       for(u8 i = 0; i <8; i++)
       {
           STP_voidSendSynchronous(1<<i);
           SYSTICK_voidSetBusyWaitms(500);
       }
    }
}
