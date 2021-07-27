/*
 * KEYPAD.c
 *
 * Created: 7/22/2021 1:17:06 AM
 *  Author: DELLL
 */ 

#include "KEYPAD.h"
#include "KEYPAD_Cfg.h"

uint8_t KEYPAD_ARRAY[4][3]={{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'C','0','E'}};

/************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Keypad initialization
*************************************************************/
enuErrorStatus_t KEYPAD_Init(void)
{
	DIO_Init();
	volatile uint8_t i;
	for(i=4;i<7;i++)
	{
		/* Put high on the output pins */
		DIO_Write(i,HIGH);	
	}

	return E_OK;
}

/************************************************************
* Parameters (in) : ptr
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Reading the Keypad buttons
*************************************************************/
enuErrorStatus_t KEYPAD_Read(uint8_t* ptr)
{
	*ptr=250;
	uint8_t x;
	uint8_t row,column;
	for(column=0;column<3;column++)
	{
		/* Put low on an output pin and scan for the input pins */
		DIO_Write(column+4,LOW);
		for(row=0;row<4;row++)
		{
			DIO_Read(row,&x);
			if(x==0)
			{
				/* Returning a character from the keypad array */
				*ptr=KEYPAD_ARRAY[row][column];
				_delay_ms(300);
			}
		}
		DIO_Write(column+4,HIGH);
	}
	return E_OK;
}
