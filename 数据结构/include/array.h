#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include "iostream"
/*
	ϡ�������Ԫ��
*/
#define MAX_SIZE 100
typedef struct {
	int i, j;
	int e;
}triple;

typedef struct {
	triple data[MAX_SIZE + 1];
	int mu, nu, tu;//���������������������Ԫ����
}tsmaritx;

/*
	ʮ�������ʾ
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

//ʱ�临�Ӷ�O��mu*nu��
bool transpose(tsmaritx m,tsmaritx& t);
#endif