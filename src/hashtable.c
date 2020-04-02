/*
*******************
file: hashtable.c
*******************
*/

#include "../include/assembler.h"
#include "../include/hashtable.h"
#include "../include/util.h"

extern HashTable* hash_table[HASH_SIZE];

/*
void init_data() 
initialize variables and the Hash_Table
called in the beginning of processing a new file.
*/
void init_data()
{
	int i;

	for(i = 0; i < HASH_SIZE; i++)
		hash_table[i]->value = NULL;

	strcpy(hash_table[0]->label, NULL_LBL);
    IC = DC = 0;
	caught_error = FALSE;
}

int hashCode(char key[])
{
	int hash = 0, index = 0, i = 0;

	while(key[i])
		hash+=key[i];
	index = hash % HASH_SIZE;

	return index;
}

/*
void insert(int key, node value)
input: key - the key of the value in the array
       value - the value is a struct node
*/
void insert(char key[], node* value)
{
	int i;
	if(contains(key))
	{
		printf("Error: %s already exists!\n", key);
		return;
	}

	i = hashCode(key);
	strcpy(hash_table[i]->label, key);
	hash_table[i]->value = value;
}

int contains(char key[])
{
	int i;
	char* curlabel = NULL;
	strcpy(curlabel, hash_table[hashCode(key)]->label);

	for(i = 0; i < HASH_SIZE; i++)
	{
		if(strcmp(hash_table[i]->label, curlabel))
			return TRUE;
	}
	printf("Error: %s not found!\n", curlabel);
	return -1;
}

node* get(char key[])
{
	int i;
	char* curlabel = NULL;
	strcpy(curlabel, hash_table[hashCode(key)]->label);

	for(i = 0; i < HASH_SIZE; i++)
	{
		if(strcmp(hash_table[i]->label, curlabel))
			return hash_table[i]->value;
	}

		printf("Error: %s not found!\n", curlabel);
		return NULL;
}

node* define_lable(char lable[], int type, int def_type)
{
	node* newnode = NULL;

	trim_str(lable);

	if(contains(lable))
	{
		caught_error = TRUE;
		fprintf(stderr, "Error: in line %d!\n%shas multiple definitions.\n", line_num, lable);
		return NULL;
	}
	/*no record was found for the label*/

	newnode = (node*)malloc(sizeof(node));
	newnode->type = type;
	newnode->defined_as = def_type;
	if(type == CODE_DEF)
		newnode->addr_value = IC;
	if(type == DATA_DEF)
		newnode->addr_value = DC;

	newnode->pocc = NULL;
	newnode->next = NULL;

	return newnode;
}

node* add_lable_occ(char* lable, int adrs_type)
{
	node* newnode = NULL;
	occ* newocc;

	if(contains(lable)) /*if no record of the label was found*/
		newnode = define_lable(lable, CODE_DEF, DEF_OCC);

	/*symbol is already defined, create an occurrence*/
	newocc = (occ*)malloc(sizeof(occ));
	newocc->addr = IC;
	newocc->type = adrs_type;
	IC++;
	newocc->next = NULL;

	newnode->pocc = newocc;
	newnode->next = NULL;

	return newnode;
}


