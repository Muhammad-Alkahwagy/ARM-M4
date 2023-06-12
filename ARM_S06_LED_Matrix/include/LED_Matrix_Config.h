/**
 * @file LED_Matrix_Config.h
 * @author Muhammad Alkahwagy (https://github.com/Muhammad-Alkahwagy)
 * @brief 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAL_LED_MATRIX_CONFIG_H
#define HAL_LED_MATRIX_CONFIG_H


/*Please write port,pin in pair*/
#define LED_MATRIX_ROW_PORT     PORTA

#define LEDMAT_ROW0      PIN0
#define LEDMAT_ROW1      PIN1
#define LEDMAT_ROW2      PIN2
#define LEDMAT_ROW3      PIN3
#define LEDMAT_ROW4      PIN4
#define LEDMAT_ROW5      PIN5
#define LEDMAT_ROW6      PIN6
#define LEDMAT_ROW7      PIN7

/*Please write port,pin in pair*/
#define LED_MATRIX_COL_PORT     PORTB
#define LEDMAT_COL0      PIN0
#define LEDMAT_COL1      PIN1
#define LEDMAT_COL2      PIN2     // 3 for jtag
#define LEDMAT_COL3      PIN3     // 4 for jtagA
#define LEDMAT_COL4      PIN4
#define LEDMAT_COL5      PIN5
#define LEDMAT_COL6      PIN6
#define LEDMAT_COL7      PIN7

#define LED_MATRIX_COLS     {LEDMAT_COL0,LEDMAT_COL1,LEDMAT_COL2,LEDMAT_COL3,LEDMAT_COL4,LEDMAT_COL5,LEDMAT_COL6,LEDMAT_COL7}


#endif
