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


/*Macros as PortId options*/
#define PORTA                   0
#define PORTB                   1
#define PORTC                   2
#define PORTD                   3
#define PORTE                   4
#define PORTH                   5

/*Macros as PinId options*/
#define PIN0                    0
#define PIN1                    1
#define PIN2                    2
#define PIN3                    3
#define PIN4                    4
#define PIN5                    5
#define PIN6                    6
#define PIN7                    7
#define PIN8                    8
#define PIN9                    9
#define PIN10                   10
#define PIN11                   11
#define PIN12                   12
#define PIN13                   13
#define PIN14                   14
#define PIN15                   15

/*Pin values*/
#define LOW                     0
#define HIGH                    1

#define SET                     0
#define RST                     1


/*Pin modes*/
#define INPUT_FLOATING          0
#define INPUT_PULL_UP           1
#define INPUT_PULL_DOWN         2
#define ANALOG                  3
#define OUTPUT_OPEN_DRAIN       4
#define OUTPUT_PUSH_PULL        5
#define ALTERNATE_FUNC          6

/*Output speeds*/
#define LOW_SPEED               0
#define MEDIUM_SPEED            1
#define HIGH_SPEED              2
#define V_HIGH_SPEED            3


#endif