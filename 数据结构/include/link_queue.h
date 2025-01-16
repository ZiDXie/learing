#pragma once
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include "iostream"

typedef struct qnode{
	int data;
	qnode* next;
}qnode,*queueptr;

typedef struct {
	queueptr front;
	queueptr rear;
}linkqueue;
//��Ӻͳ���ʱ�临�Ӷ�ΪO��1��
bool queue_init(linkqueue& q);
bool enque(linkqueue& q, int e);
bool deque(linkqueue& q, int& e);
#endif
