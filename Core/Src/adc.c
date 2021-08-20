/*
 * adc.c
 *
 *  Created on: Sep 6, 2020
 *      Author: HECTOR ZUÑIGA
 */

#include "lcd.h"
#include "main.h"
#include "adc.h"
#include "pwm.h"

uint8_t au8TextPot [4];
static uint16_t u16Adc1;
uint8_t u8Percentage;
uint8_t u8Hundreds;
uint8_t u8Tens;
uint8_t u8Units;

/* This function is used to print on the LCD
 * the value of &hadc in ASCCI code reading
 * units, tens, hundreds and thousands of the
 * variable u16Adc1
 */
void vConvertIntToASCII(void)
{
	u16Adc1 			 = HAL_ADC_GetValue(&hadc1);
	u8Percentage = (u16Adc1 * 100) / 4095;									    //Converting ADC to Percentage
	u8Hundreds   = (u8Percentage) / 100;										//Obtaining Hundreds
	u8Tens  	 = (u8Percentage - (u8Hundreds * 100)) / 10;					//Obtaining Tens
	u8Units		 = (u8Percentage - (u8Hundreds * 100 + u8Tens * 10));			//Obtaining Units

	vConvertToASCII();

	//The array is used to send to LCD the ASCII numbers.

	au8TextPot[0] = u8Hundreds;
	au8TextPot[1] = u8Tens;
	au8TextPot[2] = u8Units;
	au8TextPot[3] = 0x25;

	//Calling Functions of LCD.h to print on this

	vLcd_gotoxy(1, 2);
	vLcd_puts(au8TextPot, 4);
}

void vConvertToASCII(void)
{
//-------Calling Functions to Start ADC-------//

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

//Code to convert to ASCII reading//

	//----HUNDREDS----//

	if(u8Hundreds == 0)
	{
		u8Hundreds = 0x30;
	}
	if(u8Hundreds == 1)
	{
		u8Hundreds = 0x31;
	}
	if(u8Hundreds == 2)
	{
		u8Hundreds = 0x32;
	}
	if(u8Hundreds == 3)
	{
		u8Hundreds = 0x33;
	}
	if(u8Hundreds == 4)
	{
		u8Hundreds = 0x34;
	}
	if(u8Hundreds == 5)
	{
		u8Hundreds = 0x35;
	}
	if(u8Hundreds == 6)
	{
		u8Hundreds = 0x36;
	}
	if(u8Hundreds == 7)
	{
		u8Hundreds = 0x37;
	}
	if(u8Hundreds == 8)
	{
		u8Hundreds = 0x38;
	}
	if(u8Hundreds == 9)
	{
		u8Hundreds = 0x39;
	}

	//----TENS----//

	if(u8Tens == 0)
	{
		u8Tens = 0x30;
	}
	if(u8Tens == 1)
	{
		u8Tens = 0x31;
	}
	if(u8Tens == 2)
	{
		u8Tens = 0x32;
	}
	if(u8Tens == 3)
	{
		u8Tens = 0x33;
	}
	if(u8Tens == 4)
	{
		u8Tens = 0x34;
	}
	if(u8Tens == 5)
	{
		u8Tens = 0x35;
	}
	if(u8Tens == 6)
	{
		u8Tens = 0x36;
	}
	if(u8Tens == 7)
	{
		u8Tens = 0x37;
	}
	if(u8Tens == 8)
	{
		u8Tens = 0x38;
	}
	if(u8Tens == 9)
	{
		u8Tens = 0x39;
	}

	//----UNITS----//

	if(u8Units == 0)
	{
		u8Units = 0x30;
	}
	if(u8Units == 1)
	{
		u8Units = 0x31;
	}
	if(u8Units == 2)
	{
		u8Units = 0x32;
	}
	if(u8Units == 3)
	{
		u8Units = 0x33;
	}
	if(u8Units == 4)
	{
		u8Units = 0x34;
	}
	if(u8Units == 5)
	{
		u8Units = 0x35;
	}
	if(u8Units == 6)
	{
		u8Units = 0x36;
	}
	if(u8Units == 7)
	{
		u8Units = 0x37;
	}
	if(u8Units == 8)
	{
		u8Units = 0x38;
	}
	if(u8Units == 9)
	{
		u8Units = 0x39;
	}
}
