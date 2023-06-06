/*Include header files*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"


                                            /*FUNCTIONS IMPLEMENTATIONS*/

/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinMode                                                                                      */
/*Function description: This function defines the mode of operation of a specific GPIO Pin in the STM32-F401CC MCU        */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode                                                        */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Mode: INPUT_FLOATING, INPUT_PULL_UP, INPUT_PULL_DOWN, ANALOG, OUTPUT_OPEN_DRAIN, OUTPUT_PUSH_PULL,ALTERNATE_FUNC */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidSetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode)
{
    if((Copy_u8PortID > PORTC) || (Copy_u8PinID>PIN15))
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case PORTA:
                switch (Copy_u8Mode)
                {
                    case INPUT_FLOATING:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input floating*/
                        CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_UP:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-UP*/
                        SET_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_DOWN:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-DOWN*/
                        CLR_BIT(GPIOA_PUPDR,(Copy_u8PinID*2));
                        SET_BIT(GPIOA_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case OUTPUT_OPEN_DRAIN:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as OUTPUT_OPEN_DRAIN*/
                        SET_BIT(GPIOA_OTYPER,Copy_u8PinID);
                        break;

                    case OUTPUT_PUSH_PULL:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as OUTPUT_PUSH_PULL*/
                        CLR_BIT(GPIOA_OTYPER,Copy_u8PinID);
                        break;

                    case ALTERNATE_FUNC:
                        /* Configure the I/O direction mode as alternate function */
                        CLR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        break;

                    case ANALOG:
                        /* Configure the I/O direction mode as analog */
                        SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                        break;

                    default:
                        break;
                }
                break;
                
            case PORTB:
                switch (Copy_u8Mode)
                {
                    case INPUT_FLOATING:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input floating*/
                        CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_UP:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-UP*/
                        SET_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_DOWN:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-DOWN*/
                        CLR_BIT(GPIOB_PUPDR,(Copy_u8PinID*2));
                        SET_BIT(GPIOB_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case OUTPUT_OPEN_DRAIN:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        /*Configure Bin mode as OUTPUT_OPEN_DRAIN*/
                        SET_BIT(GPIOB_OTYPER,Copy_u8PinID);
                        break;

                    case OUTPUT_PUSH_PULL:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as OUTPUT_PUSH_PULL*/
                        CLR_BIT(GPIOA_OTYPER,Copy_u8PinID);
                        break;

                    case ALTERNATE_FUNC:
                        /* Configure the I/O direction mode as alternate function */
                        CLR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        break;

                    case ANALOG:
                        /* Configure the I/O direction mode as analog */
                        SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                        break;

                    default:
                        break;
                }
                break;

            case PORTC:
                switch (Copy_u8Mode)
                {
                    case INPUT_FLOATING:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input floating*/
                        CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_UP:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-UP*/
                        SET_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case INPUT_PULL_DOWN:
                        /* Configure the I/O direction mode as Input */
                        CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as input PULL-DOWN*/
                        CLR_BIT(GPIOC_PUPDR,(Copy_u8PinID*2));
                        SET_BIT(GPIOC_PUPDR,((Copy_u8PinID*2)+1));
                        break;

                    case OUTPUT_OPEN_DRAIN:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as OUTPUT_OPEN_DRAIN*/
                        SET_BIT(GPIOC_OTYPER,Copy_u8PinID);
                        break;

                    case OUTPUT_PUSH_PULL:
                        /* Configure the I/O direction mode as Output */
                        SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        /*Configure pin mode as OUTPUT_PUSH_PULL*/
                        CLR_BIT(GPIOC_OTYPER,Copy_u8PinID);
                        break;

                    case ALTERNATE_FUNC:
                        /* Configure the I/O direction mode as alternate function */
                        CLR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        break;

                    case ANALOG:
                        /* Configure the I/O direction mode as analog */
                        SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                        SET_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
                
        }

    }
}

/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinSpeed                                                                                     */
/*Function description: This function defines the output speed of a specific GPIO Pin in the STM32-F401CC MCU             */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: LOW_SPEED , MEDIUM_SPEED , HIGH_SPEED , V_HIGH_SPEED                                                      */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Speed)
{
    if((Copy_u8PortID > PORTC) || (Copy_u8PinID>PIN15))
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case PORTA:
                switch (Copy_u8Speed)
                {
                    case LOW_SPEED:
                        /*Configure pin the I/O output speed to low speed*/
                        CLR_BIT(GPIOA_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case MEDIUM_SPEED:
                        /*Configure pin the I/O output speed to medium speed*/
                        SET_BIT(GPIOA_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOA_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        CLR_BIT(GPIOA_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOA_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case V_HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        SET_BIT(GPIOA_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOA_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    default:
                        break;
                }
                break;
                
            case PORTB:
                switch (Copy_u8Speed)
                {
                    case LOW_SPEED:
                        /*Configure pin the I/O output speed to low speed*/
                        CLR_BIT(GPIOB_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case MEDIUM_SPEED:
                        /*Configure pin the I/O output speed to medium speed*/
                        SET_BIT(GPIOB_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOB_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        CLR_BIT(GPIOB_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOB_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case V_HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        SET_BIT(GPIOB_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOB_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;
                        
                    default:
                        break;
                }
                break;

            case PORTC:
                switch (Copy_u8Speed)
                {
                    case LOW_SPEED:
                        /*Configure pin the I/O output speed to low speed*/
                        CLR_BIT(GPIOC_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case MEDIUM_SPEED:
                        /*Configure pin the I/O output speed to medium speed*/
                        SET_BIT(GPIOC_OSPEEDER,(Copy_u8PinID*2));
                        CLR_BIT(GPIOC_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        CLR_BIT(GPIOC_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOC_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;

                    case V_HIGH_SPEED:
                        /*Configure pin the I/O output speed to high speed*/
                        SET_BIT(GPIOC_OSPEEDER,(Copy_u8PinID*2));
                        SET_BIT(GPIOC_OSPEEDER,((Copy_u8PinID*2)+1));
                        break;
                        
                    default:
                        break;
                }
                break;

            default:
                break;
                
        }
    }
}

/**************************************************************************************************************************/
/*Function name: GPIO_voidSetPinValue                                                                                     */
/*Function description: This function sets GPIO Pin Value in ODR Register in the STM32-F401CC MCU                         */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: LOW , HIGH                                                                                                */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    /*i/p validation*/
    if((Copy_u8PortID > PORTC) || (Copy_u8PinID > PIN15))
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case PORTA: 
                switch(Copy_u8Value)
                {
                    case LOW:   CLR_BIT(GPIOA_ODR,Copy_u8PinID);
                                break;
                    case HIGH:  SET_BIT(GPIOA_ODR,Copy_u8PinID);
                                break;
                    default:    break;
                }
                break;
            case PORTB: 
                switch(Copy_u8Value)
                {
                    case LOW:   CLR_BIT(GPIOB_ODR,Copy_u8PinID);
                                break;
                    case HIGH:  SET_BIT(GPIOB_ODR,Copy_u8PinID);
                                break;
                    default:    break;
                }
                break;
            case PORTC: 
                switch(Copy_u8Value)
                {
                    case LOW:   CLR_BIT(GPIOC_ODR,Copy_u8PinID);
                                break;
                    case HIGH:  SET_BIT(GPIOC_ODR,Copy_u8PinID);
                                break;
                    default:    break;
                }
                break;
            default:                            
                break;
        }        
    }
}


/**************************************************************************************************************************/
/*Function name: GPIO_voidDirectSetResetPinValue                                                                          */
/*Function description: This function sets GPIO Pin Value directly in BSRR Register in the STM32-F401CC MCU               */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value                                                       */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: RST , SET                                                                                                 */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void GPIO_voidDirectSetResetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    /*i/p validation*/
    if((Copy_u8PortID > PORTC) || (Copy_u8PinID > PIN15))
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case PORTA: switch(Copy_u8Value)
                        {
                            case SET:   GPIOA_BSRR = (1<<Copy_u8PinID);
                                        break;
                            case RST:   GPIOA_BSRR = (1<<(Copy_u8PinID+16));
                                        break;
                        }
                        break;
            case PORTB: switch(Copy_u8Value)
                        {
                            case SET:   GPIOB_BSRR = (1<<Copy_u8PinID);
                                        break;
                            case RST:   GPIOB_BSRR = (1<<(Copy_u8PinID+16));
                                        break;
                        }
                        break;
            case PORTC: switch(Copy_u8Value)
                        {
                            case SET:   GPIOC_BSRR = (1<<Copy_u8PinID);
                                        break;
                            case RST:   GPIOC_BSRR = (1<<(Copy_u8PinID+16));
                                        break;
                        }
                        break;
            default:                            break;
        }        
    }
}


/**************************************************************************************************************************/
/*Function name: GPIO_u8GetPinValue                                                                                       */
/*Function description: This function gets value of GPIO Pin from IDR Register in the STM32-F401CC MCU                    */
/*i/p arguments: u8 Copy_u8PortID, u8 Copy_u8PinID                                                                        */
/*Copy_u8PortID: PORTA , PORTB, PORTC                                                                                     */
/*Copy_u8PinID: PIN0 -> PIN15                                                                                             */
/*Copy_u8Speed: RST , SET                                                                                                 */
/*Return type: u8                                                                                                         */
/**************************************************************************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 Local_u8PinValue = 0;
    /*i/p validation*/
    if((Copy_u8PortID > PORTC) || (Copy_u8PinID > PIN15))
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case PORTA: Local_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8PinID);    break;
            case PORTB: Local_u8PinValue = GET_BIT(GPIOB_IDR, Copy_u8PinID);    break;
            case PORTC: Local_u8PinValue = GET_BIT(GPIOC_IDR, Copy_u8PinID);    break;
            default:                                                            break;
        }        
    }
    return Local_u8PinValue;
}
