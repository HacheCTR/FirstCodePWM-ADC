/*
 * leds.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Mi PC
 */
#include <lcd.h>
#include "leds.h"
#include "stdbool.h"

static bool EstButtonN = false;
uint8_t au8Text [11] = {'G','r','e','e','n','L','e','d','O','n'};
uint8_t au8OText [12] = {'O','r','a','n','g','e','L','e','d','O','n'};
uint8_t ButtonStateN;

//Function to start the LEDS Pins and Pushbutton
void vInit_Leds(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	//__HAL_RCC_GPIOH_CLK_ENABLE();

	GPIO_InitStruct.Pin 	 = GreenLed_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GreenLed_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = OrangeLed_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(OrangeLed_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = PushButton_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull 	 = GPIO_PULLUP;
	HAL_GPIO_Init(PushButton_GPIO_PORT, &GPIO_InitStruct);
}

//Functions to print the led on and change this with PushButton

void vLedFunction(void)
{
	ButtonStateN = HAL_GPIO_ReadPin (PushButton_GPIO_PORT, PushButton_PIN);

	//All this is used to turn on the led green and the led orange in different time

	if (ButtonStateN == 0 && HAL_GPIO_ReadPin (OrangeLed_GPIO_PORT, OrangeLed_PIN)== 0)        //start with green led on
	{
		HAL_GPIO_WritePin(GreenLed_GPIO_PORT, GreenLed_PIN, GPIO_PIN_SET); //green PIN 6
	}
	if((ButtonStateN == 0) && (EstButtonN == 1))                                               //When Buttons is on for the first time
	{
		EstButtonN = false;
	}
	else if((ButtonStateN == 1) && (EstButtonN == 0))
	{

		HAL_GPIO_TogglePin(OrangeLed_GPIO_PORT, OrangeLed_PIN); //pin 8 = green led
		EstButtonN = true;
	}
	if(ButtonStateN == 1 && HAL_GPIO_ReadPin (OrangeLed_GPIO_PORT, OrangeLed_PIN)== 1 && HAL_GPIO_ReadPin (GreenLed_GPIO_PORT, GreenLed_PIN)== 1)
	{
		HAL_GPIO_TogglePin(GreenLed_GPIO_PORT, GreenLed_PIN);
	}
	if(HAL_GPIO_ReadPin (PushButton_GPIO_PORT, PushButton_PIN) == 1 && HAL_GPIO_ReadPin (OrangeLed_GPIO_PORT, OrangeLed_PIN)== 0 && HAL_GPIO_ReadPin (GreenLed_GPIO_PORT, GreenLed_PIN)== 0)
	{
		HAL_GPIO_TogglePin(GreenLed_GPIO_PORT, GreenLed_PIN);
	}

	// this part of the code is used to print on the lcd witch led is on and off

	if(HAL_GPIO_ReadPin (GreenLed_GPIO_PORT, GreenLed_PIN) == 1 && HAL_GPIO_ReadPin (PushButton_GPIO_PORT, PushButton_PIN) == 1)
	{
		vLcd_command(CLEAR_DISPLAY);
		vLcd_puts(au8Text, 11);
	}
	else if(HAL_GPIO_ReadPin (GreenLed_GPIO_PORT, GreenLed_PIN) == 0 && HAL_GPIO_ReadPin (PushButton_GPIO_PORT, PushButton_PIN) == 1)
	{
		vLcd_command(CLEAR_DISPLAY);
		vLcd_puts(au8OText, 12);

	}
}
