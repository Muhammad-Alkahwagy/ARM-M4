/**
 * @file LED_Matrix_Program.c
 * @author Muhammad Alkahwagy (https://github.com/Muhammad-Alkahwagy)
 * @brief  Driver of LED Matrix
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LED_Matrix_Interface.h"
#include "LED_Matrix_Private.h"
#include "LED_Matrix_Config.h"

/*Array of LED Matrix columns*/
u8 Columns[8] = LED_MATRIX_COLS;


/**
 * @brief 
 * 
 */
void LEDMatrix_voidInit(void)
{
    /*Set mode for LED_Matrix Rows as Output*/
    GPIO_voidSetPortMode(LED_MATRIX_ROW_PORT,OUTPUT_PUSH_PULL);

    /*Set mode for LED_Matrix Columns as Output*/
    //GPIO_voidSetPortMode(LED_MATRIX_COL_PORT,OUTPUT_PUSH_PULL);
    for(u8 Localu8Iterator = 0; Localu8Iterator < 8; Localu8Iterator++)
    {
        GPIO_voidSetPinMode(LED_MATRIX_COL_PORT,Columns[Localu8Iterator],OUTPUT_PUSH_PULL);
    }

}

/**
 * @brief 
 * 
 * @param Copy_u8Frame 
 */
void LEDMatrix_voidDisplay(u8 *Copy_u8Frame)
{
    for(u8 Localu8Iterator =0; Localu8Iterator < 8; Localu8Iterator++)
    {
        /*Disable all Columns*/
        LEDMatrix_voidDisableCols();
        /*Set Row value*/
        LEDMatrix_voidSetRowVlaues(Copy_u8Frame[Localu8Iterator]);
        /*Enable column*/
        GPIO_voidSetPinValue(LED_MATRIX_COL_PORT, Columns[Localu8Iterator], LOW);
        /*Delay for 2.5 ms*/
        SYSTICK_voidSetBusyWaitus(2500);
    }
}

/**
 * @brief 
 * 
 */
static void LEDMatrix_voidDisableCols(void)
{
    for(u8 Localu8Iterator = 0; Localu8Iterator < 8; Localu8Iterator++)
    {
        GPIO_voidSetPinValue(LED_MATRIX_COL_PORT,Columns[Localu8Iterator],HIGH);
    }

}

/**
 * @brief 
 * 
 * @param Copy_u8Frame 
 */
static void LEDMatrix_voidSetRowVlaues(u8 Copy_u8Frame)
{
    for(u8 Localu8Iterator = LEDMAT_ROW0; Localu8Iterator <= LEDMAT_ROW7; Localu8Iterator++)
    {
        GPIO_voidSetPinValue(LED_MATRIX_ROW_PORT,Localu8Iterator,GET_BIT(Copy_u8Frame,Localu8Iterator));
    }
}
