#include "stm32f4xx_hal.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t				pin;
}GPIO_LED_TypeDef;

GPIO_LED_TypeDef GPIO_LED[] = 
{
	{GPIOF, GPIO_PIN_9},
	{GPIOF, GPIO_PIN_10}
};

void LED_on(int led_id)
{
	HAL_GPIO_WritePin(GPIO_LED[led_id].port, GPIO_LED[led_id].pin, GPIO_PIN_RESET);
}

void LED_off(int led_id)
{
	HAL_GPIO_WritePin(GPIO_LED[led_id].port, GPIO_LED[led_id].pin, GPIO_PIN_SET);
}

