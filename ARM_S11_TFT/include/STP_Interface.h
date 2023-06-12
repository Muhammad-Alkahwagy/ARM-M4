#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H


/******************************************************************/
/*Func. Name: STP_voidInit                                       */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the STP pins as output       */
/******************************************************************/
void STP_voidInit(void);

/******************************************************************/
/*Func. Name: STP_voidSendSynchronous                             */
/*i/p arguments: Copy_u8Digit: 0-9                                */
/*return: void                                                    */
/*Description: displays a digit from 0 to 9 on the 7-SEG display  */
/******************************************************************/
void STP_voidSendByte(u8 Copy_u8Data);
void STP_voidSendHalfWord(u16 Copy_u16Data);



#endif
