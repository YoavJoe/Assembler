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
chack if the line is a comment or an empty line
return TRUE if so, otherwish FALSE
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