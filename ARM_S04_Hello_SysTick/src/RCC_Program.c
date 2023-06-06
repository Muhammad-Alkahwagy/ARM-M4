/*Include header files*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../include/RCC_Private.h"
#include "../include/RCC_Config.h"
#include "../include/RCC_Interface.h"


/*FUNCTIONS IMPLEMENTATIONS*/
void RCC_voidInitSysClk(void)
{
    #if   RCC_SYSCLKSRC == HSE_CRYSTAL
        /*Enable HSE*/
        SET_BIT(RCC_CR, 16);
        /*Disable Bypass*/
        CLR_BIT(RCC_CR, 18);
        /*Sys Clk Source --> HSE*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    
    #elif RCC_SYSCLKSRC == HSE_RC
        /*Enable HSE*/
        SET_BIT(RCC_CR, 16);
        /*Enable Bypass*/
        SET_BIT(RCC_CR, 18);
        /*Sys Clk Source --> HSE*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    
    #elif RCC_SYSCLKSRC == HSI
        /*Enable HSI*/
        SET_BIT(RCC_CR, 0);
        /*Sys Clk Source --> HSI*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);

        /*set prescaler*/ //2
        SET_BIT(RCC_CFGR,7);

    #elif RCC_SYSCLKSRC == PLL
        /**/
        //#if PLL_CLK_INPUT == HSI

    #else
        #error "Invalid choice of clock source!"

	#endif
}

/*Copy_u8BusID: AHB1 , AHB2 , APB1 , APB2*/
/*Copy_u8PeripheralID: 0->31 */
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
    /*Input Validation*/
    if(Copy_u8PeripheralID > 31)
    {
        /*Do None*/
    }    
    else
    {
        switch (Copy_u8BusID)
        {
        case AHB1: SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralID);   break;
        case AHB2: SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralID);   break;
        case APB1: SET_BIT(RCC_APB1ENR, Copy_u8PeripheralID);   break;
        case APB2: SET_BIT(RCC_APB2ENR, Copy_u8PeripheralID);   break;
        
        default:
            break;
        }
    }

}

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
    /*Input Validation*/
    if(Copy_u8PeripheralID > 31)
    {
        /*Do None*/
    }    
    else
    {
        switch (Copy_u8BusID)
        {
        case AHB1: CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralID);   break;
        case AHB2: CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralID);   break;
        case APB1: CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralID);   break;
        case APB2: CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralID);   break;
        
        default:
            break;
        }
    }

}
