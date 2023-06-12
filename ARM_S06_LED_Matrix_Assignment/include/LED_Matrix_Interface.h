#ifndef HAL_LED_MATRIX_INTERFACE_H
#define HAL_LED_MATRIX_INTERFACE_H


void LEDMatrix_voidInit(void) ;
void LEDMatrix_voidDisplay(u8 *Copy_u8Frame) ;

void LEDMatrix_voidDisplayAnimation(u8 *Copy_u8Array, u8 Copy_u8ArrayLength);


#endif
