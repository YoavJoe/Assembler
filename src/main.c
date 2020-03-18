/*
*******************
file: main.c
*******************
*/
#include "../include/input.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
    if (argc == 1)
		printf("Error: there is no files to process!!\n");
	for(i = 1; i < argc; i++)
	{
		printf("%s.as is being processed..\n",argv[i]);
		process_file(argv[i]);
	}
    return EXIT_SUCCESS;
}