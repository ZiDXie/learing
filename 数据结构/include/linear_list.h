#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H


#include "iostream"
#include "stdio.h"

#define MAXSIZE 100
#define INCRESE 10

/*
	���Ա��˳��ʵ�֣�˳���
	���ݽṹ����������
*/

typedef struct {
	int* elem;//ͷָ��
	int length;//��ǰ����
	int list_size;//���Ա���ڴ泤��
}SqList;

/*
	��������
*/
bool Init(SqList& L);
bool Insert(SqList& L,int i,int e);
bool Del(SqList& L, int i,int& e);
int find(SqList& L, int e);
//�����ɾ��ʱ�临�Ӷ�ΪO��n��

#endif