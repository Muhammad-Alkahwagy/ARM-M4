#ifndef MCAL_SYSTICK_PRIVATE_H
#define MCAL_SYSTICK_PRIVATE_H


//SYSTICK Rrgisters
#define STK_CTRL           *((volatile u32*)(0xE000E010))   //SysTick control and status register
#define STK_LOAD           *((volatile u32*)(0xE000E014))   //SysTick reload value register
#define STK_VAL            *((volatile u32*)(0xE000E018))   //SysTick current value register
#define STK_CALIB          *((volatile u32*)(0xE000E01C))   //SysTick calibration value register

/*STK_CTRL bits*/
#define STK_CTRL_ENABLE         0       //Enable: Counter enable
#define STK_CTRL_TICKINT        1       //Tick interrupt / SysTick exception request enable
#define STK_CTRL_CLKSOURCE      2       //CLK source selection bit(0: (AHB/8) , 1: Processor clock (AHB))
#define STK_CTRL_COUNTFLAG      16      //Counter flag: returns 1 if timer counted to 0 since last time it was read


#define STK_INTERVAL_SINGLE     0    //Single interval
#define STK_INTERVAL_PERIOD     1    //Periodic interval

#define AHB         0
#define AHB_8       1


#endif