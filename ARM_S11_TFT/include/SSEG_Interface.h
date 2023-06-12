#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/******************************************************************/
/*Func. Name: SSEG1_voidInit                                       */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the Seven-segment port as output       */
/******************************************************************/
void SSEG1_voidInit(void);

/******************************************************************/
/*Func. Name: SSEG1_voidSendDigit                                  */
/*i/p arguments: Copy_u8Digit: 0-9                                */
/*return: void                                                    */
/*Description: displays a digit from 0 to 9 on the 7-SEG display  */
/******************************************************************/
void SSEG1_voidSendDigit(u8 Copy_u8Digit);

void SSEG2_voidInit(void);
void SSEG2_voidSendDigit(u8 Copy_u8Digit);

#endif
