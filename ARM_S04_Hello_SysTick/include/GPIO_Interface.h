#ifndef MCAL_GPIO_INTERFACE_H
#define MCAL_GPIO_INTERFACE_H


/*Macros as PortId options*/
#define PORTA                   0
#define PORTB                   1
#define PORTC                   2
#define PORTD                   3
#define PORTE                   4
#define PORTH                   5

/*Macros as PinId options*/
#define PIN0                    0
#define PIN1                    1
#define PIN2                    2
#define PIN3                    3
#define PIN4                    4
#define PIN5                    5
#define PIN6                    6
#define PIN7                    7
#define PIN8                    8
#define PIN9                    9
#define PIN10                   10
#define PIN11                   11
#define PIN12                   12
#define PIN13                   13
#define PIN14                   14
#define PIN15                   15

/*Pin values*/
#define LOW                     0
#define HIGH                    1

#define SET                     0
#define RST                     1


/*Pin modes*/
#define INPUT_FLOATING          0
#define INPUT_PULL_UP           1
#define INPUT_PULL_DOWN         2
#define ANALOG                  3
#define OUTPUT_OPEN_DRAIN       4
#define OUTPUT_PUSH_PULL        5
#define ALTERNATE_FUNC          6

/*Output speeds*/
#define LOW_SPEED               0
#define MEDIUM_SPEED            1
#define HIGH_SPEED              2
#define V_HIGH_SPEED            3


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
void GPIO_voidSetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode);


/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinSpeed                                                                                     */
/*Function description: This function defines the output speed of a specific GPIO Pin in the STM32-F401CC MCU             */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: LOW_SPEED , MEDIUM_SPEED , HIGH_SPEED , V_HIGH_SPEED                                                      */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed);


/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinValue                                                                                     */
/*Function description: This function sets GPIO Pin Value in ODR Register in the STM32-F401CC MCU                         */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: LOW , HIGH                                                                                                */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);


/**************************************************************************************************************************/
/*Function name: GPIO_voidDirectSetResetPinValue                                                                          */
/*Function description: This function sets GPIO Pin Value directly in BSRR Register in the STM32-F401CC MCU               */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: RST , SET                                                                                                 */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidDirectSetResetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);


/**************************************************************************************************************************/
/*Function name: GPIO_u8GetPinValue                                                                                       */
/*Function description: This function gets value of GPIO Pin from IDR Register in the STM32-F401CC MCU                    */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID                                                                        */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: RST , SET                                                                                                 */
/*Return type: u8                                                                                                         */
/**************************************************************************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);


#endif
