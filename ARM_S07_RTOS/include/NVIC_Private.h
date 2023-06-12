#ifndef MCAL_NVIC_PRIVATE_H
#define MCAL_NVIC_PRIVATE_H

typedef struct
{
    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IABR[32];
    volatile u32 RES[32];
    volatile  u8 IPR[84];

}NVIC_t;

#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC    ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

typedef struct
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;			
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR[3];
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;

}SCB_t;

#define SCB_BASE_ADDRESS     0xE000ED00
#define SCB     ((volatile SCB_t*)(SCB_BASE_ADDRESS))

#define VECT_KEY      0x5FA
#endif