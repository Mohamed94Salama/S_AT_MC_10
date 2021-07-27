/*
 * LCE_Cfg.h
 *
 * Created: 7/22/2021 7:07:58 AM
 *  Author: DELLL
 */ 


#ifndef LCE_CFG_H_
#define LCE_CFG_H_

#include "../../LIB/Register.h"

#define DATA_PORT	PORTA_R
#define CTRL_PORT	PORTC_R

#define DATA_PORT_DIRECTION	DDRA_R
#define CTRL_PORT_DIRECTION DDRC_R

#define RS_LCD	0
#define RW_LCD	1
#define E_LCD	2

#define Mode 4

#define LCD_OneLine_NonBold 0b00110000
#define LCD_TwoLine_NonBold 0b00111000
#define LCD_OneLine_Bold 0b00110100
#define LCD_TwoLine_Bold 0b00111100

#define LCD_Cursor_ON_Blinky 0b00001111
#define LCD_Cursor_ON_NotBlinky 0b00001110
#define LCD_Cursor_OFF 0b00001100

#define LCD_CLR 0b00000001

#define LCD_FirstLine 0b10000000
#define LCD_SecondLine 0b11000000


#endif /* LCE_CFG_H_ */
