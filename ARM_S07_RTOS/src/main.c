/*FreeRTOS-lab1 using semaphore on RGB LED */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
//#include "SYSTICK_Interface.h"
//#include "NVIC_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


SemaphoreHandle_t smphr1;

BaseType_t smph_state;

void Blink_LED1(void)
{
	static u8 flag = 0 ;
	while(1)
	{
		smph_state = xSemaphoreTake(smphr1, 1100);

		if(smph_state == pdTRUE)
		{
			if(flag == 0)
			{
				GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
				flag++;
			}
			else
			{
				GPIO_voidSetPinValue(PORTA,PIN0,LOW);
				flag--;
			}


			xSemaphoreGive(smphr1);
			vTaskDelay(1000);
		}
	}
}


void Blink_LED2(void)
{
	static u8 flag = 0 ;
	while(1)
	{
		smph_state = xSemaphoreTake(smphr1, 2100);

		if(smph_state == pdTRUE)
		{
			if(flag == 0)
			{
				GPIO_voidSetPinValue(PORTA,PIN1,HIGH);
				flag++;
			}
			else
			{
				GPIO_voidSetPinValue(PORTA,PIN1,LOW);
				flag--;
			}
			xSemaphoreGive(smphr1);
			vTaskDelay(2000);
		}
	}
}


void Blink_LED3(void)
{
	static u8 flag = 0 ;
	while(1)
	{
		smph_state = xSemaphoreTake(smphr1, 3100);

		if(smph_state == pdTRUE)
		{
			if(flag == 0)
			{
				GPIO_voidSetPinValue(PORTA,PIN2,HIGH);
				flag++;
			}
			else
			{
				GPIO_voidSetPinValue(PORTA,PIN2,LOW);
				flag--;
			}
			xSemaphoreGive(smphr1);
			vTaskDelay(3000);
		}
	}
}



void main()
{

	/*initialize system clk -> 25 MHz HSE */
	RCC_voidInitSysClk();

	/*enable GPIO clock for PORT A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	//SYSTICK_voidInit();

	GPIO_voidSetPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL);
	GPIO_voidSetPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL);
	GPIO_voidSetPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL);

	//crate binary semaphor
	vSemaphoreCreateBinary(smphr1);


	//create task1	
	xTaskCreate(Blink_LED1,NULL,50,NULL,0,NULL);

	//create task2
	xTaskCreate(Blink_LED2,NULL,50,NULL,0,NULL);

	//create task3
	xTaskCreate(Blink_LED3,NULL,50,NULL,0,NULL);

	//Start OS
	vTaskStartScheduler();

	while(1)
		;
}
