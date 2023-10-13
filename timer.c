#include "timer.h"
#include <reg51.h>
void delay_ms(unsigned int number)
{
	unsigned int i = 0;
	for (i = 0; i < number; i++){
		TMOD = 0x01; 
		TH0 = 0xFC;
		TL0 = 0x18;
		TR0 = 1;
		while (TF0 == 0);
		TR0 = 0;
		TF0 = 0;
	}
}