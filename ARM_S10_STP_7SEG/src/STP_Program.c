/*Include Header files from LIB Layer*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*Include my own header files*/
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

#include "STP_Interface.h"
#include "STP_Config.h"
#include "STP_Private.h"


/******************************************************************/
/*Func. Name: STP_voidInit                                       */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the Seven-segment port as output-PP    */
/******************************************************************/
void STP_voidInit(void)
{
	/*set port direction as output*/
	GPIO_voidSetPinMode(STP_SERIAL_DATA,OUTPUT_PUSH_PULL);
	GPIO_voidSetPinMode(STP_STORE_CLOCK,OUTPUT_PUSH_PULL);
	GPIO_voidSetPinMode(STP_SHIFT_CLOCK,OUTPUT_PUSH_PULL);
}


/******************************************************************/
/*Func. Name: STP_voidSetData                                     */
/*i/p arguments: u8 u8_data                                        */
/*return: void                                                    */
/*Description: writes the data to the seven-segment port         */
/******************************************************************/
void STP_voidSendByte(u8 Copy_u8Data)
{
	u8 Local_u8Counter;
	u8 Local_u8Bit;

	//GPIO_voidSetPinValue(STP_STORE_CLOCK,LOW);

	for(Local_u8Counter = 8; Local_u8Counter > 0; Local_u8Counter--)
	{
		Local_u8Bit = 	GET_BIT(Copy_u8Data, Local_u8Counter-1);

		GPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u8Bit);

		/*SEND PULSE TO SHIFT CLOCK*/
		// GPIO_voidDirectSetResetPinValue(STP_SHIFT_CLOCK,SET);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK,HIGH);
		SYSTICK_voidSetBusyWaitus(1);
		// GPIO_voidDirectSetResetPinValue(STP_SHIFT_CLOCK,RST);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK,LOW);	
		SYSTICK_voidSetBusyWaitus(1);
	}

	/*SEND PULSE TO STORE CLOCK*/
	GPIO_voidSetPinValue(STP_STORE_CLOCK,HIGH);
    SYSTICK_voidSetBusyWaitus(1);
	GPIO_voidSetPinValue(STP_STORE_CLOCK,LOW);
    SYSTICK_voidSetBusyWaitus(1);
}


void STP_voidSendHalfWord(u16 Copy_u16Data)
{
	u8 Local_u8Counter;
	u8 Local_u16Bit;

	//GPIO_voidSetPinValue(STP_STORE_CLOCK,LOW);

	for(Local_u8Counter = 16; Local_u8Counter > 0; Local_u8Counter--)
	{
		Local_u16Bit = 	GET_BIT(Copy_u16Data, Local_u8Counter-1);

		GPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u16Bit);

		/*SEND PULSE TO SHIFT CLOCK*/
		// GPIO_voidDirectSetResetPinValue(STP_SHIFT_CLOCK,SET);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK,HIGH);
		SYSTICK_voidSetBusyWaitus(1);
		// GPIO_voidDirectSetResetPinValue(STP_SHIFT_CLOCK,RST);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK,LOW);	
		SYSTICK_voidSetBusyWaitus(1);
	}

	/*SEND PULSE TO STORE CLOCK*/
	GPIO_voidSetPinValue(STP_STORE_CLOCK,HIGH);
    SYSTICK_voidSetBusyWaitus(1);
	GPIO_voidSetPinValue(STP_STORE_CLOCK,LOW);
    SYSTICK_voidSetBusyWaitus(1);
}