/*
*******************
file: hashtable.h
*******************
*/
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define HASH_SIZE 128

/*Node for storing an item in a linked list*/
typedef struct node
{
	int addr;
	int type;  /*states in what kind of addressing method the lable was used*/
	struct node* next;
}node;

typedef struct HashTable
{
	char lable[32];  /*lable name*/
	int type;        /*notes if the lable points to data or code*/

	/*linking information type: 'E'xternal, 'A'bsolute or 'R'elocatable*/
	int defined_as;

	/*raw addressing value before addition of starting 
	address value and optional addition for data labels*/
	int addr_value;
	node* plist;     /*pointer to list*/
	struct HashTable* next; /*point to the struct in the HashTable*/
}HashTable;


HashTable* hash_table;    /*pointer to Symbol Table*/

void insert(char* lable, int adrs_type);
int hashCode(char key[]);


#endif