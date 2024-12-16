#include "queue.h"

bool queue_init(queue& q) {
	q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	if (!q.base) {
		printf("malloc failed");
		return false;
	}
	q.front = q.rear = 0;
	return true;
}

int queue_len(queue& q) {
	/*
	βָ�� rear ��ͷָ�� front:
		rear ָ����һ��Ҫ����Ԫ�ص�λ�á�
		front ָ������е�һ��Ԫ�ص�λ�á�
		��� front == rear�������Ϊ�ա�
		��� (rear + 1) % queue_size == front�������Ϊ����
	���ȼ���:
		�� rear >= front��˵��βָ����ͷָ��ĺ��棬ֱ��ͨ�� rear - front �������������ЧԪ�ص�������
		�� rear < front��˵�����з����ˡ�ѭ���������е���Ч�����Ƕ�β������ĩβ�ĳ��ȼ��϶��׵�ͷָ��ĳ��ȡ�
	ȡģ����:
		Ϊ�˷�ֹ rear - front �Ľ���������д�С����Ҫȡģ queue_size��ȷ����������ȷ��
	*/
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

bool enqueue(queue& q,int e) {
	if ((q.rear + 1) % MAXQSIZE == q.front) {
		printf("queue full");
		return false;
	}
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
	return true;
}

bool dequeue(queue& q,int& e) {
	if (q.front == q.rear) {
		return false;
	}
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
	return true;
}