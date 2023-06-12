/**
 * @file main.c
 * @author Muhammad Alkahwagy
 * @brief Serial to parallel with 7-SEG
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
#include "SSEG_Interface.h"

//digits macros .gfedcba
#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111

#define DIGITS       {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE}

int main()
{

	u8 Digits[10]= DIGITS;

    /* Configure the system clock */
    RCC_voidInitSysClk();

    /*Enable clock for GPIOA*/
    RCC_voidEnablePeripheralClk(AHB1,0);

    /*Systick init*/
    SYSTICK_voidInit();

    /*STP init*/
    STP_voidInit();
    //SSEG_voidInit();

    while(1)
    {
       for(u8 i = 0; i <= 9; i++)
       {
    	   STP_voidSendByte(Digits[i]);
           SYSTICK_voidSetBusyWaitms(1000);
       }
    }
}
