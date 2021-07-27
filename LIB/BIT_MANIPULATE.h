/*
 * math.h
 *
 * Created: 7/7/2021 5:19:33 AM
 *  Author: DELLL
 */ 


#ifndef MATH_H_
#define MATH_H_

#define F_CPU 8000000ul
#define SET_BIT(REG,BIT)	(REG|=(1<<BIT))
#define CLR_BIT(REG,BIT)	(REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT)	(REG^=(1<<BIT))
#define GET_BIT(REG,BIT)	(1&(REG>>BIT))

#define MAX_LEN 255

typedef enum {E_ERROR,E_OK}enuErrorStatus_t;

#endif /* MATH_H_ */
