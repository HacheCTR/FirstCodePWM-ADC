/*
 * LCD.h
 *
 *  Created on: 26 ago. 2020
 *      Author: HECTOR ZUÑIGA
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

//MACROS for pins connected on the microcontroller to LCD

#define RS_PIN           GPIO_PIN_2
#define RS_GPIO_PORT     GPIOC

#define WR_PIN           GPIO_PIN_13
#define WR_GPIO_PORT     GPIOC

#define E_PIN            GPIO_PIN_15
#define E_GPIO_PORT      GPIOA

#define D0_PIN           GPIO_PIN_14
#define D0_GPIO_PORT     GPIOA

#define D1_PIN           GPIO_PIN_13
#define D1_GPIO_PORT     GPIOA

#define D2_PIN           GPIO_PIN_12
#define D2_GPIO_PORT     GPIOC

#define D3_PIN           GPIO_PIN_10
#define D3_GPIO_PORT     GPIOC

#define D4_PIN           GPIO_PIN_11
#define D4_GPIO_PORT     GPIOC

#define D5_PIN           GPIO_PIN_0
#define D5_GPIO_PORT     GPIOC

#define D6_PIN           GPIO_PIN_1
#define D6_GPIO_PORT     GPIOC

#define D7_PIN           GPIO_PIN_0
#define D7_GPIO_PORT     GPIOB

//MACRO TO PINS STATE OFF

#define  RS_OFF			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_RESET)
#define  WR_OFF			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_RESET)
#define  E_OFF           HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_RESET)
#define  D0_OFF      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_RESET)
#define  D1_OFF      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_RESET)
#define  D2_OFF     	 HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_RESET)
#define  D3_OFF      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_RESET)
#define  D4_OFF      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_RESET)
#define  D5_OFF      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_RESET)
#define  D6_OFF     	 HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_RESET)
#define  D7_OFF      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_RESET)

//MACRO TO PINS STATE ON

#define  RS_ON			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_SET)
#define  WR_ON			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_SET)
#define  E_ON            HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_SET)
#define  D0_ON      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_SET)
#define  D1_ON      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_SET)
#define  D2_ON     	     HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_SET)
#define  D3_ON      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_SET)
#define  D4_ON      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_SET)
#define  D5_ON      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_SET)
#define  D6_ON     	     HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_SET)
#define  D7_ON      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_SET)

//DEFINE INSTRUCTIONS CODES OF THE LCD

#define LCD_FUNCTIONSET  0b00111000
#define	CLEAR_DISPLAY    0b00000001
#define RETURN_HOME      0b00000010

//ENTRY MODE SET DIFFERENTS CODES

#define MOVESRIGHT       0b00000110
#define MOVESLEFT        0b00000100
#define SHIFTRIGHT       0b00000101
#define SHIFTLEFT        0b00000111

//LCD ON OR OFF  DIFFERENTS CODES

#define DISPLAYON        0b00001111
#define DISPLAYOFF       0b00001000

//LCD CURSOR OR DISPLAY SHIFT CODES

#define CURSORLEFT       0b00010000
#define CURSORRIFHT      0b00010100
#define DISPLAYRIGHT     0b00011100
#define DISPLAYLEFT      0b00011000

//LCD FUNCTION SET

#define EIGHTBITS        0b00110000
#define FOURBITS         0b00100000
#define TWOLINES         0b00010100
#define ONELINE          0b00010000
#define FXEDOTS          0b00010010
#define FXENDOTS         0b00010000

//Bits masks

#define BIT_ZERO		0X01
#define BIT_ONE 		0X02
#define BIT_TWO 		0X04
#define BIT_THREE 		0X08
#define BIT_FOUR 		0X10
#define BIT_FIVE 		0X20
#define BIT_SIX			0X40
#define BIT_SEVEN 		0X80

//DDRAM

#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54

//SET ADDRESS

#define LCD_CGRAM           6	//DB6: set CG RAM address
#define LCD_DDRAM           7	//DB7: set DD RAM address

//FUNCTIONS
void vLcd_Init(void);
void vLcd_putc(unsigned char);
void vLcd_gotoxy(unsigned char x, unsigned char y);
void vLcd_command(unsigned char cmd);
void vLcd_definechar(unsigned char *car,unsigned char CGRAM_dir);
void vPrintInt(int number);
void vLcd_puts(unsigned char *data, unsigned char nBytes);
void vLedsLcd(void);

#endif /* LCD_H_ */
