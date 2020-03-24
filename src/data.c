/*
*******************
file: data.c
*******************
*/

#include "../include/assembler.h"
#include "../include/data.h"

void init_data()
{
	IC = DC = 0;
	caught_error = FALSE;
}

