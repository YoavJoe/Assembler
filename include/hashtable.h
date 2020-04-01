/*
*******************
file: hashtable.h
*******************
*/
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define HASH_SIZE 64

/*Defines a node in each in a labl's occurrence list*/
typedef struct occurrence
{
	int addr;
	int type;  /*states in what kind of addressing method the lable was used*/
	struct occurrence* next;
}occ;

/*Defines a node in the labels' list
  each node holds general information about the label as described*/
typedef struct node
{
	int type;        /*notes if the lable points to data or code*/

	/*linking information type: 'E'xternal, 'A'bsolute or 'R'elocatable*/
	int defined_as;

	/*raw addressing value before addition of starting 
	address value and optional addition for data labels*/
	int addr_value;
	occ* pocc;         /*pointer to list of occurrence*/

	struct node* next; /*point to the next node in the list*/
}node;

typedef struct HashTable
{
	char label[LBL_MAX + 1];  /*the key of the value in the array*/

	node* value;              /*the value is a struct node*/
}HashTable;

/*Each cell of this array is a pointer to the first node of a linked list, 
because we want our HashTable to use a chaining collision handling*/

HashTable* hash_table[HASH_SIZE];    /*pointer to Symbol Table*/

void insert(char key[], node* value);
node* get(char key[]);
int contains(char key[]);
int hashCode(char key[]);
node* add_lable_occ(char* lable, int adrs_type);
node* define_lable(char lable[], int counter_type, int def_type);
void init_data();

#endif