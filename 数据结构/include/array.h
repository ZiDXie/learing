#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include "iostream"
/*
	稀疏矩阵三元组
*/
#define MAX_SIZE 100
typedef struct {
	int i, j;
	int e;
}triple;

typedef struct {
	triple data[MAX_SIZE + 1];
	int mu, nu, tu;//矩阵的行数，列数，非零元个数
}tsmaritx;

/*
	十字链表表示
*/
typedef struct Onode {
	int i, j, e;
	Onode* right;
	Onode* down;
}Onode,*Olink;
typedef struct {
	Olink* rhead, * chead;
	int mu, nu, tu;
}crosslist;

//时间复杂度O（mu*nu）
bool transpose(tsmaritx m,tsmaritx& t);
#endif