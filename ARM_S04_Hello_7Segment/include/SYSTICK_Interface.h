#ifndef MCAL_SYSTICK_INTERFACE_H
#define MCAL_SYSTICK_INTERFACE_H


/*FUNCTIONS PROTOTYPES*/

/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinMode                                                                                      */
/*Function description: This function defines the mode of operation of a specific GPIO Pin in the STM32-F401CC MCU        */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode                                                        */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Mode: INPUT_FLOATING, INPUT_PULL_UP, INPUT_PULL_DOWN, ANALOG, OUTPUT_OPEN_DRAIN, OUTPUT_PUSH_PULL,ALTERNATE_FUNC */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void SYSTICK_voidInit(void);

void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks);

void SYSTICK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*ptr)(void));
void SYSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr)(void));

void SYSTICK_voidStopInterval(void);

u32 SYSTICK_u32GetElapsedTime(void);

u32 SYSTICK_u32GetRemainingTime(void);


#endif