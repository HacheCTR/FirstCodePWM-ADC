/*
 * lcd.c
 *
 *  Created on: Aug 26, 2020
 *      Author: HECTOR ZUÑIGA
 */

#include <lcd.h>
#include "stdio.h"
#include "leds.h"
#include "pwm.h"
#include "adc.h"

//This function is used to start the pins and LCD

void vLcd_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	//__HAL_RCC_GPIOH_CLK_ENABLE();

	GPIO_InitStruct.Pin 	 = RS_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(RS_GPIO_PORT, &GPIO_InitStruct);


	GPIO_InitStruct.Pin 	 = WR_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(WR_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = E_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(E_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D0_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D0_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D1_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D1_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D2_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D2_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D3_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D3_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D4_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D4_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin    	 = D5_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D5_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D6_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D6_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D7_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D7_GPIO_PORT, &GPIO_InitStruct);

	//Configurations about initialization according to the datasheet

	E_OFF; WR_OFF; RS_OFF; D7_OFF; D6_OFF; D5_OFF; D4_OFF; D3_OFF; D2_OFF; D1_OFF; D0_OFF;

	HAL_Delay(20);

	//---------one------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	HAL_Delay(20);
	E_OFF;
	HAL_Delay(20);

	//-----------two-----------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	HAL_Delay(200);
	E_OFF;
	HAL_Delay(200);

	//-------three-------------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	HAL_Delay(200);
	E_OFF;
	HAL_Delay(200);

	//-----FUNCTION 8--------
	vLcd_command(LCD_FUNCTIONSET);
	//-----DISPLAY ON--------
	vLcd_command(DISPLAYON);
	//-----Clear display
	vLcd_command(CLEAR_DISPLAY);
}



void vLcd_puts(unsigned char *data, unsigned char nBytes){    //Outputs string to LCD
	unsigned char i=0;
	for(i=0; i<nBytes; i++){    // print data
		vLcd_putc(data[i]);
	}
}

void vLcd_putc(unsigned char ch){		//Sends Char to LCD

	RS_ON;
	if ( (ch) & (BIT_ZERO) ) {
		D0_ON;
	} else {
		D0_OFF;
	}
	if ( (ch) & (BIT_ONE) ) {
		D1_ON;
	} else {
		D1_OFF;
	}
	if ( (ch) & (BIT_TWO) ) {
		D2_ON;
	} else {
		D2_OFF;
	}
	if ( (ch) & (BIT_THREE) ) {
		D3_ON;
	} else {
		D3_OFF;
	}
	if ( (ch) & (BIT_FOUR) ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( (ch) & (BIT_FIVE) ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( (ch) & (BIT_SIX) ) {
		D6_ON;
	} else {
		D6_OFF;
	}
	if ( (ch) & (BIT_SEVEN) ) {
		D7_ON;
	} else {
		D7_OFF;
	}
	E_ON;
	HAL_Delay(10);//__delay_us(300);
	E_OFF;
	//HAL_Delay(5);//__delay_us(300);
}
void vLcd_command(unsigned char cmd){	//Sends Command to LCD

	RS_OFF;
	if ( (cmd) & (BIT_ZERO) ) {
		D0_ON;
	} else {
		D0_OFF;
	}
	if ( (cmd) & (BIT_ONE) ) {
		D1_ON;
	} else {
		D1_OFF;
	}
	if ( (cmd) & (BIT_TWO) ) {
		D2_ON;
	} else {
		D2_OFF;
	}
	if ( (cmd) & (BIT_THREE) ) {
		D3_ON;
	} else {
		D3_OFF;
	}
	if ( (cmd) & (BIT_FOUR) ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( (cmd) & (BIT_FIVE) ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( (cmd) & (BIT_SIX) ) {
		D6_ON;
	} else {
		D6_OFF;
	}
	if ( (cmd) & (BIT_SEVEN) ) {
		D7_ON;
	} else {
		D7_OFF;
	}

	E_ON;
	HAL_Delay(10);//__delay_us(300);
	E_OFF;
	//HAL_Delay(1);//__delay_us(300);
}

//This Functions print on the second line on the LCD

void vLcd_gotoxy(unsigned char x, unsigned char y){		//Cursor to X Y position
	register unsigned char DDRAMAddr;

	switch(y){		// remap lines into proper order
	case 1: DDRAMAddr = LCD_LINE0_DDRAMADDR+x-1; break;
	case 2: DDRAMAddr = LCD_LINE1_DDRAMADDR+x-1; break;
	case 3: DDRAMAddr = LCD_LINE2_DDRAMADDR+x-1; break;
	case 4: DDRAMAddr = LCD_LINE3_DDRAMADDR+x-1; break;
	default: DDRAMAddr =LCD_LINE0_DDRAMADDR+x-1;break;
	}
	vLcd_command(1<<LCD_DDRAM|DDRAMAddr);	// set data address
}

void vLcd_definechar(unsigned char *car,unsigned char CGRAM_dir){
	unsigned char i=0,a=0;
	a=(CGRAM_dir<<3)|1<<LCD_CGRAM;
	for(i=0;i<8;i++){
		vLcd_command(a++);
		vLcd_putc(car[i]);
	}
}
