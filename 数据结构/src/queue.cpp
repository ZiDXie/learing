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
	尾指针 rear 和头指针 front:
		rear 指向下一个要插入元素的位置。
		front 指向队列中第一个元素的位置。
		如果 front == rear，则队列为空。
		如果 (rear + 1) % queue_size == front，则队列为满。
	长度计算:
		当 rear >= front：说明尾指针在头指针的后面，直接通过 rear - front 计算出队列中有效元素的数量。
		当 rear < front：说明队列发生了“循环”，队列的有效长度是队尾到队列末尾的长度加上队首到头指针的长度。
	取模操作:
		为了防止 rear - front 的结果超过队列大小，需要取模 queue_size，确保计算结果正确。
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