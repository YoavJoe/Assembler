/*
*******************
file: input.c
*******************
*/

#include "../include/assembler.h"
#include "../include/input.h"
#include "../include/data.h"
#include "../include/util.h"
#include "../include/output.h"

/*Global Var*/
/*List of commands with there opcode ordered*/
int DC, IC, line_num;     /*data, instruction and line counters*/
int caught_error = FALSE; /*flag used globally to track the existence*/
char* commands[] = {"mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", 
	"dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};

void process_file(char* file)
{
	FILE* inputFile;
	char file_path[FILE_MAX] = ""; /*holds the full file path*/
	char input_line[MAX_LEN + 1];  /*hold one line at a time*/

	strcpy(file_path, file);
	strcat(file_path, ".as");

	inputFile = fopen(file_path, "r");

	line_num = 1; /*initialize lines counting*/
	init_data();  /*initialize new symbols table*/

	if(inputFile == NULL)
	{
		fprintf(stderr,"ERROR: Unable to open file: \t%s\n", file_path);
		return;
	}

	while(fgets(input_line, MAX_LEN + 1, inputFile)!= NULL)
	{
		if(!is_comment(input_line)) /*skip blank lines and comments*/
			process_line(input_line);
		line_num += 1;
	}

	if(fclose(inputFile)) /*close the file*/
		fprintf(stderr, "ERROR: Unable to close file: \t%s\n", file_path);

	if(!caught_error) /*no errors found while processing*/
	{
		if(create_ob_file(file))
			fprintf(stderr, "ERROR: Failed making object file./n/n");
		if(create_ent_file(file))
			fprintf(stderr, "ERROR: Failed making entries file./n/n");
		if(create_ext_file(file))
			fprintf(stderr, "ERROR: Failed making externals file./n/n");

		fprintf(stdout,"%s was succsessfully processed!!\n\n", file);
			
	}
}

void process_line(char line[])
{
	
}