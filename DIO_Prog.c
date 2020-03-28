

/********************************************************************************************/
/*************************    AUTHOR: Mahmoud Fargallah       *******************************/
/*************************    VERSION: 01                     *******************************/
/*************************    DATE:26/3/2020                  *******************************/
/*************************    DISCRIPTION:   DIO_INTERFACES_H *******************************/
/********************************************************************************************/



#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_Reg.h"
#include "ErrorStatus.h"



/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set pin Direction       */
/*                                                       */
/*                 Inputs : port , pin , Direction       */
/*                 return : Enum                         */
/*********************************************************/



Error_enuStatus    DIO_enuSetPinDirection(u8 Copy_u8PORTID ,u8 Copy_u8PINID, u8 Copy_u8Direction)
{
	Error_enuStatus   error = ES_NOK;
	if( ( Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
	{
		if( Copy_u8Direction == OUTPUT )
		{
			switch(Copy_u8PORTID)
			{
				case PORTA: SET_BIT(DIO_PU8_DDRA, Copy_u8PINID); break;  /* <      *       *       *        > */
				case PORTB: SET_BIT(DIO_PU8_DDRB, Copy_u8PINID); break;  /*        Set Bin As Output          */
                case PORTC: SET_BIT(DIO_PU8_DDRC, Copy_u8PINID); break;  /*                                   */
                case PORTD: SET_BIT(DIO_PU8_DDRD, Copy_u8PINID); break;  /* <      *       *       *        > */
			}
			error = ES_OK ;
		}
		else if( Copy_u8Direction == INPUT )
		{
			switch(Copy_u8PORTID)
			{
			    case PORTA: CLEAR_BIT(DIO_PU8_DDRA, Copy_u8PINID); break;  /* <      *       *       *        > */
				case PORTB: CLEAR_BIT(DIO_PU8_DDRB, Copy_u8PINID); break;  /*        Set Bin As Intput          */
				case PORTC: CLEAR_BIT(DIO_PU8_DDRC, Copy_u8PINID); break;  /*                                   */
				case PORTD: CLEAR_BIT(DIO_PU8_DDRD, Copy_u8PINID); break;  /* <      *       *       *        > */
			}
			error = ES_OK ;
		}
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}

	return error;
}



/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   :  set pin Value                        */
/*                                                       */
/*                 Inputs : port , pin , Value           */
/*                 return : Enum                         */
/*********************************************************/


Error_enuStatus    DIO_enuSetPinValue(u8 Copy_u8PORTID, u8 Copy_u8PINID, u8 Copy_u8Value)
{
	Error_enuStatus   error =  ES_NOK;
	if( (Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
	{
		if( Copy_u8Value == HIGH )
		{
			switch(Copy_u8PORTID)
			{
				case PORTA: SET_BIT(DIO_PU8_PORTA, Copy_u8PINID); break;   /* <      *       *       *        > */
				case PORTB: SET_BIT(DIO_PU8_PORTB, Copy_u8PINID); break;   /*        Set Bin As HIGH            */
				case PORTC: SET_BIT(DIO_PU8_PORTC, Copy_u8PINID); break;   /*                                   */
				case PORTD: SET_BIT(DIO_PU8_PORTD, Copy_u8PINID); break;   /* <      *       *       *        > */
			}
			error = ES_OK ;
		}
		else if( Copy_u8Value == LOW )
		{
			switch(Copy_u8PORTID)
			{
				case PORTA: CLEAR_BIT(DIO_PU8_PORTA, Copy_u8PINID); break;  /* <      *       *       *        > */
				case PORTB: CLEAR_BIT(DIO_PU8_PORTB, Copy_u8PINID); break;  /*        Set Bin As LOW             */
				case PORTC: CLEAR_BIT(DIO_PU8_PORTC, Copy_u8PINID); break;  /*                                   */
				case PORTD: CLEAR_BIT(DIO_PU8_PORTD, Copy_u8PINID); break;  /* <      *       *       *        > */
			}
			error = ES_OK ;
		}
	}
    else
	{
		error = ES_OUT_OF_RANGE ;
	}
	return error;
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   :  get pin Value                        */
/*                                                       */
/*                 Inputs : port , pin                   */
/*                 return : u8                           */
/*********************************************************/


 u8          DIO_enuGetPinValue(u8 Copy_u8PORTID, u8 Copy_u8PINID)
{
	u8 Local_u8Value =0;
	if( ( Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
	{
		switch( Copy_u8PORTID)
		{
			case PORTA: Local_u8Value = GET_BIT( DIO_PU8_PORTA , Copy_u8PINID ); break;  /* <      *       *       *        > */
			case PORTB: Local_u8Value = GET_BIT( DIO_PU8_PORTB , Copy_u8PINID ); break;  /*        Get Bin Value              */
			case PORTC: Local_u8Value = GET_BIT( DIO_PU8_PORTC , Copy_u8PINID ); break;  /*                                   */
			case PORTD: Local_u8Value = GET_BIT( DIO_PU8_PORTD , Copy_u8PINID ); break;  /* <      *       *       *        > */
		}
	}


	return Local_u8Value ;
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This function set port direction      */
/*                                                       */
/*                 Inputs : port , Direction             */
/*                 return : Enum                         */
/*********************************************************/



Error_enuStatus    DIO_enuSetPortDirection(u8 Copy_u8PORTID, u8 Copy_u8Direction)
{
	Error_enuStatus  error = ES_NOK;
	if( Copy_u8PORTID < 4)
	{
		switch(Copy_u8PORTID)
		{
			case PORTA:  DIO_PU8_DDRA = Copy_u8Direction ; break;   /* <      *       *       *        > */
			case PORTB:  DIO_PU8_DDRB = Copy_u8Direction ; break;   /*        Set Port As input          */
			case PORTC:  DIO_PU8_DDRC = Copy_u8Direction ; break;   /*            OR OutPUT              */
			case PORTD:  DIO_PU8_DDRD = Copy_u8Direction ; break;   /* <      *       *       *        > */
		}
			error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE ;
	}

	return error ;
}


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   :  set port Value                       */
/*                                                       */
/*                 Inputs : port , Value                 */
/*                 return : Enum                         */
/*********************************************************/

Error_enuStatus    DIO_enuSetPortValue(u8 Copy_u8PORTID, u8 Copy_u8Value)

{
	Error_enuStatus error = ES_NOK ;
	if(Copy_u8PORTID <4)
	{
		switch(Copy_u8PORTID)
		{
			case PORTA:  DIO_PU8_PORTA = Copy_u8Value ; break;   /* <      *       *       *        > */
			case PORTB:  DIO_PU8_PORTB = Copy_u8Value ; break;   /*        SET Port Value             */
			case PORTC:  DIO_PU8_PORTC = Copy_u8Value ; break;   /*                                   */
			case PORTD:  DIO_PU8_PORTD = Copy_u8Value ; break;   /* <      *       *       *        > */
		}
		error = ES_OK ;
	}
	else
	{
		error = ES_OUT_OF_RANGE	;
	}
	return error;
}
