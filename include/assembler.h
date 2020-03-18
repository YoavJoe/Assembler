/*
*******************
file: assembler.h
*******************
*/
#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

/*General Symbols*/
#define TRUE = 1
#define FALSE = 0
#define CMD_COUNT 16      /*Total number of commands*/
#define MAX_LEN  30       /*Max line length*/
#define MAX_LEN 200       /*Arbitray limit for file name length*/
#define LBL_MAX 30        /*Maximum length for a lable*/
#define START_ADRES 100   /*The address for the first word in memory*/

/*Addresing types symbols*/
#define IMD_ADRS 0        /*Immediate addressing*/
#define DIR_ADRS 1		  /*Direct addresing*/
#define VAR_INDEX_ADRS 2  /*Varied indx addresing*/
#define REG_ADRS 3		  /*Register addresing*/

/*Defines the characters that should be added to instructions machine code words*/
#define TYPE_A 'A'        /*Absolute*/
#define TYPE_R 'R'        /*Relocatable*/
#define TYPE_E 'E'        /*External*/

#endif