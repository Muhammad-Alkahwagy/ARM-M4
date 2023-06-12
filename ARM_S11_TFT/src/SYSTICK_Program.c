/*Include header files*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_Private.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"

//define callback global variable
static void (*STK_Callback)(void) = NULL;  

static u8 STK_u8IntervalMode;

                
                    /*FUNCTIONS IMPLEMENTATIONS*/

void SYSTICK_voidInit(void)
{
    /*Apply clock selection from config.h*/
    #if STK_CLK == AHB
        SET_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
    #elif STK_CLK == AHB_8
        CLR_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
    #else
        #error "Wrong CLK configuration setting"
    #endif

    /*disable SysTick interrupt*/
    CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);

}


void SYSTICK_voidSetBusyWaitus(u32 Copy_u32Ticks)
{
    /*Load value into STK_LOAD register*/
    STK_LOAD = Copy_u32Ticks;

    /*enable SysTick to start timer*/
    SET_BIT(STK_CTRL,STK_CTRL_ENABLE);

    /*POLL ON COUNTFLAG*/
    while((GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG)==0));

    /*Stop timer*/

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
    /*reset register values*/
    STK_LOAD = 0;
    STK_VAL = 0;

}

void SYSTICK_voidSetBusyWaitms(u32 Copy_u32Ticks)
{
    /*Load value into STK_LOAD register*/
    STK_LOAD = 1000UL * Copy_u32Ticks;

    /*enable SysTick to start timer*/
    SET_BIT(STK_CTRL,STK_CTRL_ENABLE);

    /*POLL ON COUNTFLAG*/
    while((GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG)==0));

    /*Stop timer*/

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
    /*reset register values*/
    STK_LOAD = 0;
    STK_VAL = 0;

}


void SYSTICK_voidStopInterval(void)
{
    /*disable SysTick interrupt*/
    CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);

    /*disable SysTick*/
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);

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


void SYSTICK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*ptr)(void))
{
    /*disable timer*/
    CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
    STK_VAL = 0;

    /*Load value into STK_LOAD register*/
    STK_LOAD = Copy_u32Ticks;

    /*enable SysTick to start timer*/
    SET_BIT(STK_CTRL,STK_CTRL_ENABLE);

    /*save callback*/
    STK_Callback = ptr;

    /*Set interval mode to single*/
    STK_u8IntervalMode = STK_INTERVAL_SINGLE;
    
    /*enable SysTick interrupt*/
    SET_BIT(STK_CTRL,STK_CTRL_TICKINT);

}

void SYSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr)(void))
{
    /*Load value into STK_LOAD register*/
    STK_LOAD = Copy_u32Ticks;

    /*enable SysTick to start timer*/
    SET_BIT(STK_CTRL,STK_CTRL_ENABLE);

    /*save callback*/
    STK_Callback = ptr;

    /*Set interval mode to periodic*/
    STK_u8IntervalMode = STK_INTERVAL_PERIOD;
    
    /*enable SysTick interrupt*/
    SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
    
}

void SysTick_Handler(void)
{
    u8 Local_u8TempVariable = 0;

    if(STK_u8IntervalMode == STK_INTERVAL_SINGLE)
    {
        /*disable STK interrupt*/
        CLR_BIT(STK_CTRL,STK_CTRL_TICKINT);

        /*stop timer*/
        CLR_BIT(STK_CTRL,STK_CTRL_ENABLE);
        /*reset register values*/
        STK_LOAD =0;
        STK_VAL =0;
    }
    
    STK_Callback(); // callback notification

    /*clear interrupt flag*/
    Local_u8TempVariable = GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG);

}