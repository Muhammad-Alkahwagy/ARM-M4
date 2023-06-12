#ifndef MCAL_NVIC_INTERFACE_H
#define MCAL_NVIC_INTERFACE_H


#define G4B_SG0B    3       // 16 Groups , 0  Subgroup 
#define G3B_SG1B    4       // 8  Groups , 2  Subgroups 
#define G2B_SG2B    5       // 4  Groups , 4  Subgroups
#define G1B_SG3B    6       // 2  Groups , 8  Subgroups 
#define G0B_SG0B    7       // 0  Group  , 16 Subgroups

/**************************************************************************************************************************/
/*Function name: NVIC_voidEnablePeripheralInterrupt                                                                       */
/*Function description: This function enables external interrupt of a specific peripheral in the STM32-F401CC MCU         */
/*i/p arguments: u8 Copy_u8IntID : 0 -> 84                                                                                */
/*Return type: void                                                                                                       */
/**************************************************************************************************************************/
void NVIC_voidEnablePeripheralInterrupt(u8 Copy_u8IntID);


void NVIC_voidDisablePeripheralInterrupt(u8 Copy_u8IntID);
void NVIC_voidSetPendingFlag(u8 Copy_u8IntID);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntID);
void NVIC_voidSetPriorityConfiguration(u8 Copy_u8PriorityOption);
void NVIC_voidSetIntPriority(u8 Copy_u8IntID, u8 Copy_u8GroupID, u8 Copy_u8SubGroupID);


#endif