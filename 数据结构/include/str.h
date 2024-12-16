#pragma once
#ifndef STR_H
#define STR_H
#define MAX_SIZE 255
#include "iostream"
/*
	串的堆分配
*/
typedef struct {
	char* ch;
	int length;
}Hstring;
/*
	定长分配
*/
typedef char Sstring[MAX_SIZE + 1];


bool str_assign(Hstring& t, char* chars);
int str_len(Hstring t);
int str_compare(Hstring s,Hstring t);
bool concat(Hstring& T, Hstring s1, Hstring s2);
bool substring(Hstring T, Hstring& sub, int pos, int len);

bool concat_s(Sstring& T, Sstring s1, Sstring s2);
bool substring_s(Sstring T, Sstring& sub, int pos, int len);
#endif





