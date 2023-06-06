#ifndef MCAL_RCC_INTERFACE_H
#define MCAL_RCC_INTERFACE_H

/*FUNCTIONS PROTOTYPES*/
void RCC_voidInitSysClk(void);  //Select system clock

/*Copy_u8BusID: AHB1 , AHB2 , APB1 , APB2*/
/*Copy_u8PeripheralID: 0->31 */
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);


#endif