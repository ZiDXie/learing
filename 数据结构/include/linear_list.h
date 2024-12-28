#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H


#include "iostream"
#include "stdio.h"

#define MAXSIZE 100
#define INCRESE 10

/*
	线性表的顺序实现，顺序表
	数据结构类似于数组
*/

typedef struct {
	int* elem;//头指针
	int length;//当前长度
	int list_size;//线性表的内存长度
}SqList;

/*
	函数声明
*/
bool Init(SqList& L);
bool Insert(SqList& L,int i,int e);
bool Del(SqList& L, int i,int& e);
int find(SqList& L, int e);
//插入和删除时间复杂度为O（n）

#endif