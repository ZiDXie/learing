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
	| ���� | data |
	 -------------
	|   1  | data | 0
	 -------------
	|   2  | data | 1
	 -------------
	|   0  | data | 2
	 -------------
	|  ��  | data |
	 -------------
	|   0  | data | 3
	 -------------
*/
bool stack_link_init(SLinklist& s);
/*
������������ռ�
*/
int malloc_s(SLinklist& s);
/*
�ͷſռ�ر�������
*/
void free_s(SLinklist& s,int i);
int link_length(SLinklist s);
bool stack_link_insert(SLinklist& s, int i,int e);
#endif