/*Include header files*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "systick_Private.h"
#include "systick_Config.h"
#include "systick_Interface.h"


                                            /*FUNCTIONS IMPLEMENTATIONS*/

void SYSTICK_voidInit(void)
{
    /*Apply clock selection from config.h*/
    #if STK_CLK == AHB
        SET_BIT(STK_CTRL,2);
    #elif STK_CLK == AHB_8
        CLR_BIT(STK_CTRL,2);
    #else
        #error "Wrong selection"
    #endif

    /*disable SysTick interrupt*/
    CLR_BIT(STK_CTRL,1);

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,0);

}


void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    /*Load value into STK_LOAD register*/
    STK_LOAD = 1000UL*Copy_u32Ticks;

    /*enable SysTick interrupt*/
    SET_BIT(STK_CTRL,1);

    /*enable SysTick*/
    SET_BIT(STK_CTRL,0);

    /*POLL ON FLAG*/
    while((GET_BIT(STK_CTRL,16)==0));

}


void SYSTICK_voidStopInterval(void)
{
    /*disable SysTick interrupt*/
    CLR_BIT(STK_CTRL,1);

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,0);

    /*reset VAL and LOAD registers*/
    STK_LOAD =0;
    STK_VAL =0;
}

u32 SYSTICK_u32GetElapsedTime(void)
{
    return (STK_LOAD-STK_VAL);   
}

u32 SYSTICK_u32GetRemainingTime(void)
{
    return STK_VAL;
}
