/*
 * ADC.c
 *
 * Created: 7/24/2021 11:55:26 PM
 *  Author: DELLL
 */ 

#include "ADC.h"

uint8_t gAdjust;
/************************************************************
* Parameters (in) : u8VrefCpy , u8L_R_Adjustcpy , u8AutoTriggercpy
* 					u8InterruptCpy
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : ADC initialization part 1
*************************************************************/
enuErrorStatus_t ADC_Init1(uint8_t u8VrefCpy,uint8_t u8L_R_Adjustcpy,uint8_t u8AutoTriggercpy,uint8_t u8InterruptCpy)
{

	SET_BIT(ADCSRA_R,ADEN_B); //enable ADC
	SET_BIT(ADCSRA_R,ADIF_B); //clear the flag

	/* Select Vref*/
	if(u8VrefCpy == Vref_external)
	{
		CLR_BIT(ADMUX_R,REFS1_B);
		CLR_BIT(ADMUX_R,REFS0_B);
	}else if(u8VrefCpy == Vref_vcc)
	{
		CLR_BIT(ADMUX_R,REFS1_B);
		SET_BIT(ADMUX_R,REFS0_B);
//		ADMUX_R |= (1<<REFS0_B);
	}else if(u8VrefCpy == Vref_internal)
	{
		SET_BIT(ADMUX_R,REFS1_B);
		SET_BIT(ADMUX_R,REFS0_B);
//		ADMUX_R |= (1<<REFS1_B);
//		ADMUX_R |= (1<<REFS0_B);
	}

	/* Right or left adjusted digital value */
	if(u8L_R_Adjustcpy == Left_Adjusted)
	{
		SET_BIT(ADMUX_R,ADLAR_B);
		gAdjust = Left_Adjusted;
	}else if(u8L_R_Adjustcpy == Right_Adjusted)
	{
		CLR_BIT(ADMUX_R,ADLAR_B);
		gAdjust = Right_Adjusted;
	}

	/* Enable or disable autotrigger */
	if(u8AutoTriggercpy == Disable_AutoTrigger)
	{
		CLR_BIT(ADCSRA_R,ADATE_B);
	}else if(u8AutoTriggercpy == Enable_AutoTrigger)
	{
		SET_BIT(ADCSRA_R,ADATE_B);
//		ADCSRA_R |= (1<<ADATE_B);
	}

	/* Enable or disable the interrupt for the ADC */
	if(u8InterruptCpy == Disable_Interrupt)
	{
		CLR_BIT(ADCSRA_R,ADIE_B);
	}else if(u8InterruptCpy == Enable_Interrupt)
	{
		SET_BIT(ADCSRA_R,ADIE_B);
//		ADCSRA_R |= (1<<ADIE_B);
	}

	return E_OK;
}

/************************************************************
* Parameters (in) :	u8InputTerminlasCpy , u8prescalercpy
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : ADC initialization part 2
*************************************************************/
enuErrorStatus_t ADC_Init2(uint8_t u8InputTerminlasCpy,uint8_t u8prescalercpy)
{
	/* Select the channel */
	if(u8InputTerminlasCpy == Single_Ended_ADC0)
	{

	 	CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC1)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if (u8InputTerminlasCpy == Single_Ended_ADC2)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC3)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC4)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC5)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC6)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Single_Ended_ADC7)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC1_ADC0_Gain_10X)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC1_ADC0_Gain_200X)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC3_ADC2_Gain_10X)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC3_ADC2_Gain_200X)
	{
		CLR_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC0_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC2_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC3_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC4_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC5_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC6_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC7_ADC1_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		CLR_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC0_ADC2_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC1_ADC2_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC3_ADC2_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		CLR_BIT(ADMUX_R,MUX2_B);
		SET_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC4_ADC2_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		CLR_BIT(ADMUX_R,MUX0_B);
	}else if(u8InputTerminlasCpy == Differential_Input_ADC5_ADC2_Gain_1X)
	{
		SET_BIT(ADMUX_R,MUX4_B);
		SET_BIT(ADMUX_R,MUX3_B);
		SET_BIT(ADMUX_R,MUX2_B);
		CLR_BIT(ADMUX_R,MUX1_B);
		SET_BIT(ADMUX_R,MUX0_B);
	}
	
	
	

	/* Select the clock */
	if(u8prescalercpy == CLK_BY_2)
	{
		CLR_BIT(ADCSRA_R,ADPS2_B);
		CLR_BIT(ADCSRA_R,ADPS1_B);
		SET_BIT(ADCSRA_R,ADPS0_B);
//		ADCSRA_R|=(1<<ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_4)
	{
		CLR_BIT(ADCSRA_R,ADPS2_B);
		SET_BIT(ADCSRA_R,ADPS1_B);
		CLR_BIT(ADCSRA_R,ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_8)
	{
		CLR_BIT(ADCSRA_R,ADPS2_B);
		SET_BIT(ADCSRA_R,ADPS1_B);
		SET_BIT(ADCSRA_R,ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_16)
	{
		SET_BIT(ADCSRA_R,ADPS2_B);
		CLR_BIT(ADCSRA_R,ADPS1_B);
		CLR_BIT(ADCSRA_R,ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_32)
	{
		SET_BIT(ADCSRA_R,ADPS2_B);
		CLR_BIT(ADCSRA_R,ADPS1_B);
		SET_BIT(ADCSRA_R,ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_64)
	{
		SET_BIT(ADCSRA_R,ADPS2_B);
		SET_BIT(ADCSRA_R,ADPS1_B);
		CLR_BIT(ADCSRA_R,ADPS0_B);
	}else if(u8prescalercpy == CLK_BY_128)
	{
		SET_BIT(ADCSRA_R,ADPS2_B);
		SET_BIT(ADCSRA_R,ADPS1_B);
		SET_BIT(ADCSRA_R,ADPS0_B);
	}
	
	return E_OK;
}

/************************************************************
* Parameters (in) :	pu16data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Get the ADC reading
*************************************************************/
enuErrorStatus_t ADC_read_value(uint16_t* pu16data)
{

	/* Starting the conversion */
	SET_BIT(ADCSRA_R,ADSC_B);

	while(!GET_BIT(ADCSRA_R,ADIF_B)); //polling

	/* Clear the flag */
	SET_BIT(ADCSRA_R,ADIF_B);

	/* Returning the data */
	if(gAdjust = Right_Adjusted)
	{
		*pu16data=(ADCL_R) | ((ADCH_R)<<8);
	}else if(gAdjust = Left_Adjusted)
	{
		*pu16data = (uint16_t)ADCH_R;
	}

	return E_OK;
}
