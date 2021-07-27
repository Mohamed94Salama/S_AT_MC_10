/*
 * LCD.c
 *
 * Created: 7/22/2021 7:08:31 AM
 *  Author: DELLL
 */ 

#include "LCD.h"
#include "LCD_Cfg.h"

/************************************************************
* Parameters (in) : font , cursor
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : LCD initialization
*************************************************************/
enuErrorStatus_t LCD_Init(void)
{

	DDRC_R=0x07;
	
	if(Mode == 8)
	{
		DATA_PORT_DIRECTION=0xFF;
		_delay_ms(30);
		LCD_SendCMD(LCD_TwoLine_NonBold);
	}else if(Mode == 4)
	{
		DATA_PORT_DIRECTION=0xF0;
		_delay_ms(30);
		LCD_SendCMD(0x02);
		_delay_ms(2);
		LCD_SendCMD(0x28);

	}

	_delay_ms(2);
	LCD_SendCMD(LCD_Cursor_OFF);
	_delay_ms(2);
	LCD_SendCMD(0b00000001);
	_delay_ms(30);
	return E_OK;
	
}

/************************************************************
* Parameters (in) : cmd
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Sending a command to the LCD
*************************************************************/
enuErrorStatus_t LCD_SendCMD(uint8_t cmd)
{
	DIO_Init();
	/* Reset the RS and R/W pins*/
	CLR_BIT(CTRL_PORT,RS_LCD);
	CLR_BIT(CTRL_PORT,RW_LCD);
	
	/* Sending the command throuth the data port */
	if(Mode == 8)
	{
		DATA_PORT = cmd;
	}else if(Mode == 4)
	{
		DATA_PORT =(DATA_PORT&0x0F)|(cmd&0xF0);

		SET_BIT(CTRL_PORT,E_LCD);
		_delay_ms(2);
		CLR_BIT(CTRL_PORT,E_LCD);
		DATA_PORT=(DATA_PORT&0x0F)|(cmd<<4);

	}
	
	/* Latch the E pin */
	SET_BIT(CTRL_PORT,E_LCD);
	_delay_ms(2);
	CLR_BIT(CTRL_PORT,E_LCD);
	
	return E_OK;
}

/************************************************************
* Parameters (in) : c
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Sending data to the LCD
*************************************************************/
enuErrorStatus_t LCD_SendChar(uint8_t c)
{
	DIO_Init();
	
	/* Set the RS , reset the R/W */
	SET_BIT(CTRL_PORT,RS_LCD);
	CLR_BIT(CTRL_PORT,RW_LCD);
	
	/* Sending the data */
	if(Mode == 8)
	{
		DATA_PORT = c;
	}else if(Mode == 4)
	{
		DATA_PORT =(DATA_PORT&0x0F)|(c&0xF0);

		SET_BIT(CTRL_PORT,E_LCD);
		_delay_ms(2);
		CLR_BIT(CTRL_PORT,E_LCD);
		DATA_PORT=(DATA_PORT&0x0F)|(c<<4);

	}
	/* Latch the E pin */
	SET_BIT(CTRL_PORT,E_LCD);
	_delay_ms(2);
	CLR_BIT(CTRL_PORT,E_LCD);
	
	return E_OK;
}

/************************************************************
* Parameters (in) : ptr
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Sending a string to the LCD
*************************************************************/
enuErrorStatus_t LCD_SendString(uint8_t* ptr)
{
	uint8_t i=0;
	while(ptr[i] != '\0')
	{
		LCD_SendChar(ptr[i]);
		i++;
		_delay_us(80);
	}
	return E_OK;
}

/************************************************************
* Parameters (in) : num
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Writing a number on the LCD
*************************************************************/
enuErrorStatus_t LCD_writeNum(uint32_t num)
{
	int8_t counter = 1;
	uint32_t temp = num;
	uint32_t char_num;
	int8_t i;
	if(num == 0)
	{
		LCD_SendChar('0');
	}
	else
	{
		while(temp >= 10)
		{
			temp = temp/10;
			counter ++;
		}
		uint8_t arr_num[counter];
		for(i=0;i<counter;i++)
		{
			char_num = num % 10;
			arr_num[i]=char_num + '0';
			num = num/10;
		}
		for(i=counter-1;i>=0;i--)
		{
			LCD_SendChar(arr_num[i]);
		}
	}
	return E_OK;
}

/************************************************************
* Parameters (in) : X , Y
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Change the coordinate of the cursor
*************************************************************/
enuErrorStatus_t LCD_GOTOXY(uint8_t X,uint8_t Y)
{
	if(Y == 1)
	{
		LCD_SendCMD(0b10000000 + X);
	}
	else if(Y == 2)
	{
		LCD_SendCMD(0b11000000 + X);
	}
	return E_OK;
}
