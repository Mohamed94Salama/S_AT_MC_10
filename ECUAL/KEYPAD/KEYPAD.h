/*
 * KEYPAD.h
 *
 * Created: 7/22/2021 1:17:22 AM
 *  Author: DELLL
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/* Includes */
#include "../../LIB/BIT_MANIPULATE.h"
//#include "STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Cfg.h"
#include "../../LIB/Register.h"
#include "../../LIB/Register_Cont.h"
#include <util/delay.h>

/* Functions prototypes */
enuErrorStatus_t KEYPAD_Init(void);
enuErrorStatus_t KEYPAD_Read(uint8_t* ptr);

#endif /* KEYPAD_H_ */
