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

//kmp算法，找到已经匹配部分的公共前后缀，滑动后模式串的指针指向公共前后缀的下一个
//next数组定义：每次失配后j指针指向的位置，算法复杂度O（m+n）
//next数组的值为当前元素前面部分最长公共前后缀加1
int next[];
//求next数组,时间复杂度为O（n）
void get_next(Sstring T, int next[]);

int index_kmp(Sstring S, Sstring T, int pos);
#endif





