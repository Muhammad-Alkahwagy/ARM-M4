#ifndef MCAL_GPIO_PRIVATE_H
#define MCAL_GPIO_PRIVATE_H


#define GPIOA_BASE_ADDRESS    0x40020000
#define GPIOB_BASE_ADDRESS    0x40020400
#define GPIOC_BASE_ADDRESS    0x40020800

#define GPIOD_BASE_ADDRESS    0x40020C00
#define GPIOE_BASE_ADDRESS    0x40021000
#define GPIOH_BASE_ADDRESS    0x40021C00

//GPIOA Rrgisters
#define GPIOA_MODER           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_OTYPER          *((volatile u32*)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_OSPEEDER        *((volatile u32*)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_PUPDR           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_IDR             *((volatile u32*)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_ODR             *((volatile u32*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_BSRR            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x18))
#define GPIOA_LCKR            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x1C))
#define GPIOA_AFRL            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x20))
#define GPIOA_AFRH            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x24))

//GPIOB Rrgisters
#define GPIOB_MODER           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_OTYPER          *((volatile u32*)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_OSPEEDER        *((volatile u32*)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_PUPDR           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_IDR             *((volatile u32*)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_ODR             *((volatile u32*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_BSRR            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x18))
#define GPIOB_LCKR            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x1C))
#define GPIOB_AFRL            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x20))
#define GPIOB_AFRH            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x24))

//GPIOC Rrgisters
#define GPIOC_MODER           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_OTYPER          *((volatile u32*)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_OSPEEDER        *((volatile u32*)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_PUPDR           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_IDR             *((volatile u32*)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_ODR             *((volatile u32*)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_BSRR            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x18))
#define GPIOC_LCKR            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x1C))
#define GPIOC_AFRL            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x20))
#define GPIOC_AFRH            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x24))


#define LOW_BYTE_MASK	0x
#endif
