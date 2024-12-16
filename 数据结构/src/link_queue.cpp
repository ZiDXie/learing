#include "link_queue.h"

bool queue_init(linkqueue& q) {
	q.front = q.rear = (queueptr)malloc(sizeof(qnode));
	if (!q.front) {
		printf("malloc failed.");
		return false;
	}
	q.front->next = NULL;
	return true;
}

bool enque(linkqueue& q, int e) {
	queueptr p = (queueptr)malloc(sizeof(qnode));
	if (!p) {
		printf("malloc failed");
		return false;
	}
	p->data = e;
	q.rear->next = p;
	q.rear = p;
	return true;
}

bool deque(linkqueue& q, int& e) {
	if (q.front == q.rear) {
		printf("empty queue");
		return false;
	}
	queueptr p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	//·ÀÖ¹Î²Ö¸Õë¶ªÊ§
	if (q.rear == p) {
		q.rear = q.front;
	}
	free(p);
	return true;
}