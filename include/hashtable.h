/*
*******************
file: hashtable.h
*******************
*/
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

/*Node for storing an item in a linked list*/
typedef struct 
{
	int key;
	int value;
	struct node* next;
}node;

typedef struct 
{
	node *head;
	/*head pointing the first element of linked list at an index of Hash Table*/
}list;

typedef struct
{
	char lable;   
	node* plist; /*pointer to list*/
}HashTable, *Hashptr;

void init_data();
int insert();
void clear();
void print_HashTable();
#endif