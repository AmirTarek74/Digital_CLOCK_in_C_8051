#include <reg51.h>
#include "output.h"

#define OUTPUT_PORT P2

void output_to_port(char switches_value)
{
	OUTPUT_PORT= switches_value;
}