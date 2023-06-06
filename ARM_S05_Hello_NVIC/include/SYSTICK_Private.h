#ifndef MCAL_SYSTICK_PRIVATE_H
#define MCAL_SYSTICK_PRIVATE_H


//SYSTICK Rrgisters
#define STK_CTRL           *((volatile u32*)(0xE000E010))
#define STK_LOAD           *((volatile u32*)(0xE000E014))
#define STK_VAL            *((volatile u32*)(0xE000E018))
#define STK_CALIB          *((volatile u32*)(0xE000E01C))

#define AHB     0
#define AHB_8   1


#endif