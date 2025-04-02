#pragma once
#ifndef STACK_H
#define STACK_H
#define stack_max 100

#include "iostream"

/*
	栈是一种后进先出的数据结构
	这是栈的顺序存储
*/
typedef struct {
	int* base;
	int* top;//栈顶指针为栈顶元素的下一个位置
	int stcak_size;
}stack;

/*
	栈的链式存储
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
//入栈和出栈时间复杂度为O（1）
bool init_link_stack(linklist& s);
bool push_link(linklist& s, int e);
bool pop_link(linklist& s, int& e);
#endif
