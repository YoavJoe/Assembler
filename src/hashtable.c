/*
*******************
file: hashtable.c
*******************
*/

#include "../include/assembler.h"
#include "../include/hashtable.h"

extern HashTable* hash_table;

/*
int insert(char* lable, int adrs_type)
input: lable - pointer to lable
adrs_type - the addressing type in the node
*/
void insert(char* lable, int adrs_type)
{
	/*HashTable* phash = hash_table;*/
	node* newNode = NULL;

	/*go throgh the hash table and chech if there is al*/
	while(strcmp(hash_table->lable, lable) != 0 && (hash_table->next != NULL))
		hash_table = hash_table->next;

	newNode = (node*)malloc(sizeof(node));

	if(newNode == NULL)
	{
		printf("Error: memory not allocated to newNode");
		return;
	}

	newNode->addr = IC;
	newNode->type = adrs_type;
	IC++;
	newNode->next = hash_table->plist;
	hash_table->plist = newNode;
}

int hashCode(char key[])
{
	int hash = 0;
	int index = 0;
	int i = 0;

	while(key[i])
		hash+=key[i];
	index = hash % HASH_SIZE;

	return index;
}
