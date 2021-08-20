/*
 * pwm.c
 *
 *  Created on: 4 sep. 2020
 *      Author: HECTOR ZUÑIGA
 */


#include <lcd.h>
#include "main.h"
#include "pwm.h"


uint8_t u8RightButtonState;
uint8_t u8LeftButtonState;
static uint16_t u16DutyCycle;

//FUNCTON THAT START ALL PINES

void vPwm_Init (void)
{

	GPIO_InitTypeDef GPIO_InitStruct;


	/* GPIO Ports Clock Enable */


	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitStruct.Pin 	 = PushButton1_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull 	 = GPIO_PULLUP;
	HAL_GPIO_Init(PushButton1_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = PushButton2_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull 	 = GPIO_PULLUP;
	HAL_GPIO_Init(PushButton2_GPIO_PORT, &GPIO_InitStruct);
}

/* THIS FUNCITON IS USED TO DECREASE AND CREASE
 * THE VELOCITY OF THE MOTOR USING THE PWM FUNCTION
 * AND A RIGHTBUTTON AND A LEFTBUTTON
 */
void vDecreaseAndCreaseVel (void)
{

	u8RightButtonState = HAL_GPIO_ReadPin(PushButton1_GPIO_PORT, PushButton1_PIN);
	u8LeftButtonState  = HAL_GPIO_ReadPin(PushButton2_GPIO_PORT, PushButton2_PIN);
	u16DutyCycle = 0;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	//THIS IS USED TO CREASE THE VELOCITY

	if(u8RightButtonState == 1 && u8LeftButtonState == 0)
	{
		u16DutyCycle += 3000;
		__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, u16DutyCycle);
	}

	//THIS IS USED TO DECREASE THE VELOCITY

	if(u8LeftButtonState == 1 && u8RightButtonState == 0)
	{
		u16DutyCycle -= 3000;
		__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, u16DutyCycle);
	}
}

