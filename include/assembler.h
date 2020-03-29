/*
*******************
file: assembler.h
*******************
Main header file for the program
Defineds macros and declares global variables and Hash Table
*/
#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*General Symbols*/
#define TRUE 1
#define FALSE 0
#define ERROR 2           /*Used as return value from functions*/
#define NULL_LBL "0LABEL" /*An invalid lable used to recognaize an empty lable*/
#define CMD_COUNT 16      /*Total number of commands*/
#define MAX_LEN  30       /*Max line length*/
#define FILE_MAX 200      /*Arbitray limit for file name length*/
#define LBL_MAX 31        /*Maximum length for a lable*/
#define START_ADRES 100   /*The address for the first word in memory*/
#define MAX_MEM_SIZE 5000 /*Max memory size*/

/*Addresing types symbols*/
#define IMD_ADRS 0        /*Immediate addressing*/
#define DIR_ADRS 1		  /*Direct addresing*/
#define VAR_INDEX_ADRS 2  /*Varied indx addresing*/
#define REG_ADRS 3		  /*Register addresing*/

/*Defines the characters that should be added to instructions machine code words*/
#define TYPE_A 'A'        /*Absolute*/
#define TYPE_R 'R'        /*Relocatable*/
#define TYPE_E 'E'        /*External*/

/*symbols types*/
#define DEF_CODE 1        /*Code symbol*/
#define DEF_DATA -1       /*Data symbol*/
#define DEF_EXT 2         /*Extern symbol*/
#define DEF_ENT 3         /*Entery symbol*/

/*Uesd to hold and organize the machine code words create by the progrem */
typedef struct
{
	int value; 
	char type; 
}memory[MAX_MEM_SIZE];


/*Global Varibales*/

extern int DC, IC, line_num;  /*data counter, instruction counter and line counter*/
extern int caught_error;      /*used to flag erros existence*/
extern char* commends[];      /*a list of valid command names*/
extern HashTable* hase_table;    /*pointer to Symbol Table*/

#endif