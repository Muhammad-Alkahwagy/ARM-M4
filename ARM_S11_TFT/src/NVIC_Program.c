/*Include header files*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Private.h"
#include "NVIC_Config.h"
#include "NVIC_Interface.h"

static u8 Global_u8PriorityOption;

                                /*FUNCTIONS IMPLEMENTATIONS*/

void NVIC_voidEnablePeripheralInterrupt(u8 Copy_u8IntID)
{
    NVIC ->ISER[Copy_u8IntID /32] = (1<< (Copy_u8IntID %32));
}


void NVIC_voidDisablePeripheralInterrupt(u8 Copy_u8IntID)
{
    NVIC ->ICER[Copy_u8IntID /32] = (1<< (Copy_u8IntID %32));
}


void NVIC_voidSetPendingFlag(u8 Copy_u8IntID)
{
    NVIC ->ISPR[Copy_u8IntID /32] = (1<< (Copy_u8IntID %32));
}


void NVIC_voidClearPendingFlag(u8 Copy_u8IntID)
{
    NVIC ->ICPR[Copy_u8IntID /32] = (1<< (Copy_u8IntID %32));
}

/*Copy_u8PriorityOption: G4B_SG0B , G3B_SG1B , G2B_SG2B , G1B_SG3B , G0B_SG0B */
void NVIC_voidSetPriorityConfiguration(u8 Copy_u8PriorityOption)
{
    Global_u8PriorityOption = Copy_u8PriorityOption;
    
    SCB -> AIRCR = VECT_KEY | (Copy_u8PriorityOption << 8);
}


void NVIC_voidSetIntPriority(u8 Copy_u8IntID, u8 Copy_u8GroupID, u8 Copy_u8SubGroupID)
{
    u8 Local_u8Priority = Copy_u8SubGroupID | (Copy_u8GroupID << Global_u8PriorityOption - 3);
    
    NVIC ->IPR[Copy_u8IntID] = (Local_u8Priority << 4);
}
