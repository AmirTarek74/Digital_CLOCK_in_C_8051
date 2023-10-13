#include <reg51.h>
#include "buttons.h"
#include "timer.h"\
#define delay_period 20

char isShiftted,isINC;


sbit Shift_bit = P3^0;
sbit INC_bit = P3^1;
char shift_pressed()
{
	P3 = 0xFF;
	isShiftted= 0;
	if(Shift_bit == 0)
	{
		delay_ms(delay_period);
		if(Shift_bit == 0)
		{
			isShiftted = 1;
		}
	}
	return isShiftted;
}
char inc_pressed()
{
	P3 = 0xFF;
	isINC= 0;
	if(INC_bit == 0)
	{
		delay_ms(delay_period);
		if(INC_bit == 0)
		{
			isINC = 1;
		}
	}
	return isINC;
	
}
