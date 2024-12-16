#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#define MAXQSIZE 100

#include "iostream"

/*
	循环队列演示
*/
typedef struct {
	int* base;
	//头指针和尾指针
	int front;
	int rear;
}queue;

bool queue_init(queue& q);
int queue_len(queue& q);
bool enqueue(queue& q,int e);
bool dequeue(queue& q,int& e);
#endif
