/*
 * ADC_DRIVER.c
 *
 * Created: 7/24/2021 11:38:14 PM
 * Author : DELLL
 */ 

#include "../MCAL/ADC/ADC.h"
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/KEYPAD/KEYPAD.h"
/*void ADC_init(void)
{
	//ADCSRA_R=(1<<ADEN_B);
	ADCSRA_R=0b10000111;
	ADMUX_R=0b01000000;
}*/

int main(void)
{

	/* LCD , KEYPAD , ADC initialization */
	LCD_Init();
	ADC_Init1(Vref_vcc,Right_Adjusted,Disable_AutoTrigger,Disable_Interrupt);
	ADC_Init2(Single_Ended_ADC0,CLK_BY_2);
	KEYPAD_Init();

	/* Variables initialization */
	uint16_t x;
	uint32_t mv_value;
	uint32_t temperature;
	uint8_t NUM[2];
	uint8_t counter =0;
	uint8_t base=1;
	uint8_t res=0;
	uint8_t var=250;
	uint8_t check=0;

	/* The fan port */
	SET_BIT(DDRC_R,7);

	/* Strings to appear on the LCD */
	uint8_t* str1="Temp :";
	uint8_t* str2="Allowed temp :";
	LCD_SendString(str2);
    while (1) 
    {
    	/* Keep checking if a temperature value is entered */
    	/* Assuming the user to set a temperature value of at least 2 integers */
    	while((check==0))
    	{
    		/* Read the value from the keypad */
    	KEYPAD_Read(&var);
    	uint8_t temp2=var;
    	if(var==250)
    	{

    	}else{
    	if(temp2=='E')
    	{
    		for(uint8_t i=counter-1;i>=0;i--)
    		{
    			res=res+(NUM[i]*base);
    			base=base*10;
    			check++;
    			if(i==0)
    			{
    				break;
    			}
    		}
    		LCD_GOTOXY(0,2);
    	}else
    	{
    		if(counter==0)
    		{
    			if(temp2=='0')
    			{
    				NUM[0]=0;
    				LCD_writeNum(NUM[0]);
    			}else
    			{
    				NUM[0]=temp2-'0';
    				LCD_writeNum(NUM[0]);
    			}
    		}else if(counter==1)
    		{
    			if(temp2=='0')
    			{
    				NUM[1]=0;
    				LCD_writeNum(NUM[1]);
    			}else
    			{
    				NUM[1]=temp2-'0';
    				LCD_writeNum(NUM[1]);
    			}
    		}
    		counter++;
    	}

    	}
    	}
    	/*When the user set the temperature , it compares it to the surrounding temperature */
    	if(check==2)
    	{
    		while(temperature<res)
    		{
    			/* Turn off the fan */
    			CLR_BIT(PORTC_R,7);
    			LCD_GOTOXY(0,2);
            	LCD_SendString(str1);
            	ADC_read_value(&x);
            	uint32_t temp = x;
            	mv_value=(temp*5000)/1024;
            	temperature=(mv_value/10);
            	LCD_writeNum(temperature);
    		}
    		if(temperature>=res)
    		{
    			while(temperature>=res)
    			{
    				/* Turn on the fan */
    				SET_BIT(PORTC_R,7);
        			LCD_GOTOXY(0,2);
                	LCD_SendString(str1);
                	ADC_read_value(&x);
                	uint32_t temp = x;
                	mv_value=(temp*5000)/1024;
                	temperature=(mv_value/10);
                	LCD_writeNum(temperature);
    			}

    		}
    	}
    	}

}
