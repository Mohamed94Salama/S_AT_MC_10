/*
 * ADC_Cfg.h
 *
 * Created: 7/24/2021 11:56:02 PM
 *  Author: DELLL
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define Vref_vcc 0
#define Vref_internal 1
#define Vref_external 2

#define Left_Adjusted 0
#define Right_Adjusted 1

#define Single_Ended_ADC0 0
#define Single_Ended_ADC1 1
#define Single_Ended_ADC2 2
#define Single_Ended_ADC3 3
#define Single_Ended_ADC4 4
#define Single_Ended_ADC5 5
#define Single_Ended_ADC6 6
#define Single_Ended_ADC7 7
#define Differential_Input_ADC1_ADC0_Gain_10X 8
#define Differential_Input_ADC1_ADC0_Gain_200X 9
#define Differential_Input_ADC3_ADC2_Gain_10X 10
#define Differential_Input_ADC3_ADC2_Gain_200X 11
#define Differential_Input_ADC0_ADC1_Gain_1X 12
#define Differential_Input_ADC2_ADC1_Gain_1X 13
#define Differential_Input_ADC3_ADC1_Gain_1X 14
#define Differential_Input_ADC4_ADC1_Gain_1X 15
#define Differential_Input_ADC5_ADC1_Gain_1X 16
#define Differential_Input_ADC6_ADC1_Gain_1X 17
#define Differential_Input_ADC7_ADC1_Gain_1X 18
#define Differential_Input_ADC0_ADC2_Gain_1X 19
#define Differential_Input_ADC1_ADC2_Gain_1X 20
#define Differential_Input_ADC3_ADC2_Gain_1X 21
#define Differential_Input_ADC4_ADC2_Gain_1X 22
#define Differential_Input_ADC5_ADC2_Gain_1X 23

#define Disable_AutoTrigger 0
#define Enable_AutoTrigger 1

#define Disable_Interrupt 0
#define Enable_Interrupt 1

#define CLK_BY_2   0
#define CLK_BY_4   1
#define CLK_BY_8   2
#define CLK_BY_16  3
#define CLK_BY_32  4
#define CLK_BY_64  5
#define CLK_BY_128 6



#endif /* ADC_CFG_H_ */