/*
*******************
file: data.c
*******************
*/

#include "../include/assembler.h"
#include "../include/data.h"
#include "../include/hashtable.h"

/*
void init_data() 
initialize variables and the Hash_Table
called in the beginning of processing a new file.
*/

void init_data()
{
	hash_table = (HashTable*)malloc(sizeof(HashTable));
	if(hash_table == NULL)
	{
		printf("Error: memory not allocated to Hash Table");
		return;
	}

	strcpy(hash_table->lable, NULL_LBL);
    hash_table->plist = NULL;
    IC = DC = 0;
	caught_error = FALSE;
}

void add_lable(char* lable, int adrs_type)
{
	insert(lable, adrs_type);
	if(strcmp(hash_table->lable, lable)) /*if no record of the lable was found*/
	{
		define_lable(lable, DEF_CODE, DEF_NDS);
	}
}

void define_lable(char lable[], int counter_type, int def_type)
{
	
}

