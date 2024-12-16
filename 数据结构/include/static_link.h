#pragma once
#ifndef STATIC_LINK_H
#define STATIC_LINK_H

#define MAX_SIZE 100
#include "iostream"

typedef struct {
	int data;
	int cur;
}SLinklist[MAX_SIZE],component;

/*
	 -------------
	| 备用 | data |
	 -------------
	|   1  | data | 0
	 -------------
	|   2  | data | 1
	 -------------
	|   0  | data | 2
	 -------------
	|  主  | data |
	 -------------
	|   0  | data | 3
	 -------------
*/
bool stack_link_init(SLinklist& s);
/*
备用链表申请空间
*/
int malloc_s(SLinklist& s);
/*
释放空间回备用链表
*/
void free_s(SLinklist& s,int i);
int link_length(SLinklist s);
bool stack_link_insert(SLinklist& s, int i,int e);
#endif