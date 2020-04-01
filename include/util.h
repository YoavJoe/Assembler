/*
*******************
file: util.h
*******************
*/
#ifndef _UTIL_H
#define _UTIL_H

int is_comment(char line[]);
int valid_cmd(char cmd[]);
int is_reg(char* reg);
int valid_label(char label[]);
void trim_str(char* str);

#endif