#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/******************************************************************/
/*Func. Name: SSEG_voidInit                                       */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the Seven-segment port as output       */
/******************************************************************/
void SSEG_voidInit(void);

/******************************************************************/
/*Func. Name: SSEG_voidSendDigit                                  */
/*i/p arguments: Copy_u8Digit: 0-9                                */
/*return: void                                                    */
/*Description: displays a digit from 0 to 9 on the 7-SEG display  */
/******************************************************************/
void SSEG_voidSendDigit(u8 Copy_u8Digit);

#endif
