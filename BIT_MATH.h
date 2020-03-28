


/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                                   GUARD                                                  */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


#define SET_BIT(Reg,bit)        (Reg =   ((1<<bit)|Reg))
#define CLEAR_BIT(Reg,bit)      (Reg =   ((1<<bit)&Reg))
#define TOG_BIT(Reg,bit)        (Reg =   ((1<<bit)^Reg))
#define GET_BIT(Reg, bit_num)         ((Reg>>bit_num)&0x01)
#define ASSIGN_BIT(Reg,bit)     (Reg =   (~(1<<bit)&Reg)|(Reg<<bit))    

#endif



