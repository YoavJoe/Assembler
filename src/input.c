/*
*******************
file: input.c
*******************
*/

#include "../include/input.h"

/*Global Var*/
/*List of commands with there opcode ordered*/
char* commands[] = {"mov","cmp", "add", "sub", "lea","clr", "not", "inc",
	 				   "dec","jmp", "bne", "red","prn", "jsr","rts", "stop"};

void process_file(char* file)
{
	printf("%s\n", file);
}