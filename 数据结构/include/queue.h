#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#define MAXQSIZE 100

#include "iostream"

/*
	ѭ��������ʾ
*/
typedef struct {
	int* base;
	//ͷָ���βָ��
	int front;
	int rear;
}queue;
//��Ӻͳ���ʱ�临�Ӷ�ΪO��1��
bool queue_init(queue& q);
int queue_len(queue& q);
bool enqueue(queue& q,int e);
bool dequeue(queue& q,int& e);
#endif
