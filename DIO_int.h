
/********************************************************************************************/
/*************************    AUTHOR: Mahmoud Fargallah       *******************************/
/*************************    VERSION: 01                     *******************************/
/*************************    DATE:26/3/2020                   *******************************/
/*************************    DISCRIPTION:   DIO_INTERFACES_H *******************************/
/********************************************************************************************/

#ifndef     _DIO_INT_H_
#define     _DIO_INT_H_

#include "STD_types.h"
#include "ErrorStatus.h"



#define     PORTA     0
#define     PORTB     1
#define     PORTC     2
#define     PORTD     3


#define     PIN0      0
#define     PIN1      1
#define     PIN2      2
#define     PIN3      3
#define     PIN4      4
#define     PIN5      5
#define     PIN6      6
#define     PIN7      7

#define   OUTPUT      1
#define   INPUT       0

#define   HIGH        1
#define   LOW         0


Error_enuStatus    DIO_enuSetPinDirection(u8 Copy_u8PORTID ,u8 Copy_u8PINID, u8 Copy_u8Value);

Error_enuStatus    DIO_enuSetPinValue(u8 Copy_u8PORTID, u8 Copy_u8PINID, u8 Copy_u8Value);

Error_enuStatus    DIO_enuSetPortDirection(u8 Copy_u8PORTID, u8 Copy_u8Direction);

Error_enuStatus    DIO_enuSetPortValue(u8 Copy_u8PORTID, u8 Copy_u8Value);

u8                 DIO_enuGetPinValue(u8 Copy_u8PORTID, u8 Copy_u8Value);


#endif
