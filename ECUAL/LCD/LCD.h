/*
 * LCD.h
 *
 * Created: 7/22/2021 7:07:43 AM
 *  Author: DELLL
 */ 


#ifndef LCD_H_
#define LCD_H_

/* Includes */
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Cfg.h"
#include "../../LIB/BIT_MANIPULATE.h"
#include "../../LIB/Register_Cont.h"
#include "LCD_Cfg.h"
#include "util/delay.h"

/* Functions prototypes */
enuErrorStatus_t LCD_Init(void);
enuErrorStatus_t LCD_SendCMD(uint8_t cmd);
enuErrorStatus_t LCD_SendChar(uint8_t c);
enuErrorStatus_t LCD_SendString(uint8_t* pu8string);
enuErrorStatus_t LCD_SendString(uint8_t* ptr);
enuErrorStatus_t LCD_writeNum(uint32_t num);
enuErrorStatus_t LCD_GOTOXY(uint8_t X,uint8_t Y);

#endif /* LCD_H_ */
