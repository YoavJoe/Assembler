/*
*******************
file: util.c
*******************
*/

#include "../include/assembler.h"
#include "../include/util.h"

/*
int is_comment(char line[])
input: line from an input file
check if the line is a comment or an empty line
return TRUE if so, otherwise FALSE
*/
int is_comment(char line[])
{
	int i;
	for (i = 0; isspace(line[i]); i++) /*skip whitespace*/

	/*return ((line[i] == ';') || (line[i] == '\0'))? TRUE : FALSE;*/
	if((line[i] == ';') || (line[i] == '\0'))
		return TRUE;

	return FALSE;
}

int valid_cmd(char cmd[])
{
	return 0;
}

int is_reg(char* reg)
{
	return 0;
}

int valid_label(char label[])
{
	return 0;
}

void trim_str(char* str)
{
	int i, check;
	i = check = strlen(str) - 1;

	while(isspace(str[i])) /*check if there is a space*/
		i--;

	if(i < check)
		str[i + 1] = '\0'; /*delete leading blanks*/
}