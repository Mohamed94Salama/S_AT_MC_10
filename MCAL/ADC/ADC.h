/*
 * ADC.h
 *
 * Created: 7/24/2021 11:55:42 PM
 *  Author: DELLL
 */ 


#ifndef ADC_H_
#define ADC_H_

/* Includes */
#include "../../LIB/Register.h"
#include "../../LIB/BIT_MANIPULATE.h"
//#include "../../LIB/STD_TYPES.h"
#include "ADC_Cfg.h"
#include <util/delay.h>

/* Functions prototypes */
enuErrorStatus_t ADC_Init1(uint8_t u8VrefCpy,uint8_t u8L_R_Adjustcpy,uint8_t u8AutoTriggercpy,uint8_t u8InterruptCpy);
enuErrorStatus_t ADC_Init2(uint8_t u8InputTerminlasCpy,uint8_t u8prescalercpy);
enuErrorStatus_t ADC_read_value(uint16_t* pu16data);

#endif /* ADC_H_ */
