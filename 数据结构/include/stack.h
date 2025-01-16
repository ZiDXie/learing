#pragma once
#ifndef STACK_H
#define STACK_H
#define stack_max 100

#include "iostream"

/*
	ջ��һ�ֺ���ȳ������ݽṹ
	����ջ��˳��洢
*/
typedef struct {
	int* base;
	int* top;//ջ��ָ��Ϊջ��Ԫ�ص���һ��λ��
	int stcak_size;
}stack;

/*
	ջ����ʽ�洢
*/
typedef struct node {
	int data;
	node* next;
}node,*linklist;
linklist top;

bool init_stack(stack& s);
bool get_top(stack& s, int& e);
bool push(stack& s, int e);
bool pop(stack& s, int& e);
//��ջ�ͳ�ջʱ�临�Ӷ�ΪO��1��
bool init_link_stack(linklist& s);
bool push_link(linklist& s, int e);
bool pop_link(linklist& s, int& e);
#endif
