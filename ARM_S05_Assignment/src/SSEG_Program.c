/*Include Header files from LIB Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Include my own header files*/
#include "GPIO_Interface.h"

#include "SSEG_Interface.h"
#include "SSEG_Config.h"
#include "SSEG_Private.h"


/******************************************************************/
/*Func. Name: SSEG1_voidInit                                       */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the Seven-segment port as output-PP    */
/******************************************************************/
void SSEG1_voidInit(void)
{
	/*set port direction as output*/
	GPIO_voidSetPortMode(SSEG1_PORT,OUTPUT_PUSH_PULL);
}

void SSEG2_voidInit(void)
{
	/*set port direction as output*/
	GPIO_voidSetPortMode(SSEG2_PORT,OUTPUT_PUSH_PULL);
}

/******************************************************************/
/*Func. Name: SSEG1_voidSendDigit                                  */
/*i/p arguments: Copy_u8Digit: 0-9                                */
/*return: void                                                    */
/*Description: displays a digit from 0 to 9 on the 7-SEG display  */
/******************************************************************/
void SSEG1_voidSendDigit(u8 Copy_u8Digit)
{
	if(Copy_u8Digit > 9)
	{
		/*Do none*/
	}
	else
	{
		u8 Local_ArrDigits[10]= DIGITS;

		GPIO_voidSetByteValue(SSEG1_PORT,SSEG1_BYTE,Local_ArrDigits[Copy_u8Digit]);
	}
}


void SSEG2_voidSendDigit(u8 Copy_u8Digit)
{
	if(Copy_u8Digit > 9)
	{
		/*Do none*/
	}
	else
	{
		u8 Local_ArrDigits[10]= DIGITS;

		GPIO_voidSetByteValue(SSEG2_PORT,SSEG2_BYTE,Local_ArrDigits[Copy_u8Digit]);
	}
}


