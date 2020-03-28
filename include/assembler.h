/*
*******************
file: assembler.h
*******************
Main header file for the program
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
#define DEF_LABLE "MAIN:" /*Dedault lable*/
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

/*Uesd to hold and organize the machine code words create by the progrem */
struct
{
	int value; 
	char type; 
}memory[MAX_MEM_SIZE+1];

/*Global Varibales*/

extern int DC, IC, line_num;  /*data counter, instruction counter and line counter*/
extern int caught_error;      /*used to flag erros existence*/
extern char* commends[];      /*a list of valid command names*/

#endif