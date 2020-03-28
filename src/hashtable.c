/*
*******************
file: hashtable.c
*******************
*/

#include "../include/assembler.h"
#include "../include/hashtable.h"

Hashptr hase_table;

void init_data()
{
	hase_table = (Hashptr)malloc(sizeof(HashTable));
	strcpy(&hase_table->lable, DEF_LABLE);
	hase_table->plist = NULL;
}
int insert()
{
	return 0;
}
void clear()
{

}
void print_HashTable()
{

}