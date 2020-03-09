#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 1)
		printf("Error: there no files\n");
	else
	{
		int i;
		for(i=1; i<argc ;i++)
		{
			process_file(argv[i]);
		}
	}
    return EXIT_SUCCESS;
}