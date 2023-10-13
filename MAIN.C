#include <reg51.h>
#include "buttons.h"
#include "output.h"
#include "timer.h"
#include "main.h"
#define msec 1000







int main()
{
	EX0=1;  // external interrupt 0
	
	EX1=1;  // external interrupt 1
	
	EA=1; 	// enable interrupt
	
	
	digit=1;  //inital points to first segment
	
	INC=0;    // increment button flag
	
	delay=0;  // delay flag to count 1 sec
	
	start=0;   // start flag to display
	
	while(1)
	{
		
		if(start == 1 )
		{
			if(set == 0)
			{
				delay++;
			}
			else
			{
				shift = shift_pressed();
				if(shift == 1 && digit<=6)
				{
					while(shift_pressed() == 1);  // for debouncing
					digit++;
				}
				else if(digit==7)
				{
					digit=1;
				}
				INC = inc_pressed();  
				
				if(INC==1)
				{
					while(inc_pressed() == 1); //for debouncing
					switch(digit)
					{
						case 1:
							sec1++;
						break;
						case 2:
							sec2++;
						break;
						case 3:
							min1++;
						break;
						case 4:
							min2++;
						break;
						case 5:
							hour1++;
						break;
						case 6:
							hour2++;
						break;
					}
				}
				INC=0; 
			}
			if(delay==6000)
			{
				delay=0;
				sec1++;
			}
			
		// first digit display "odd seconds "
			P2=0xFF;
			d1=1;
			d2=d3=d4=d5=d6=0;
			P2=segments[sec1];
			if(sec1==10)
			{
				sec1=0;
				sec2++;
			}
			// second digit display " tens seconds "
			P2=0xFF;
			d2=1;
			d1=d3=d4=d5=d6=0;
			P2=segments[sec2];
			if(sec2==6)
			{
				sec2=0;
				min1++;
			}
			// third digit display "odd minuts "
			P2=0xFF;
			d3=1;
			d1=d2=d4=d5=d6=0;
			P2=segments[min1];
			if(min1==10)
			{
				min1=0;
				min2++;
			}
			// fourth digit display "tens minuts "
			P2=0xFF;
			d4=1;
			d1=d2=d3=d5=d6=0;
			P2=segments[min2];
			if(min2==6)
			{
				min2=0;
				hour1++;
			}
			// fifth digit display "odd hours"
			P2=0xFF;
			d5=1;
			d1=d2=d3=d4=d6=0;
			P2=segments[hour1];
			if(hour1==10)
			{
				hour1=0;
				hour2++;
			}
			// sixth digit display "tens hours"
			
			P2=0xFF;
			d6=1;
			d1=d2=d3=d4=d5=0;
			P2=segments[hour2];
			if(1==hour2 && 3==hour1)
			{
				sec1=sec2=min1=min2=hour2=0; // 12 hours system 
				hour1=1;
			}
		}
		}
		return 0;
	}

void ISR_EX0(void) interrupt 0
{
	start = 1;
	set = 0;
}
void ISR_EX1(void) interrupt 2
{
	set = 1;
}