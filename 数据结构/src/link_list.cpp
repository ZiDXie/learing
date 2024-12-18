#include "link_list.h"

bool link_init(Linklist& L) {
	/*
		L��ͷ�ڵ�ָ��
	*/
	L = (Linklist)malloc(sizeof(LNode));
	if (!L) {
		printf("malloc failed");
		return false;
	}
	L->next = NULL;
	return true;
}

bool link_insert(Linklist& L, int i, int e) {
	int j = 0;
	Linklist p, p0;//�����Ľڵ�Ͳ���Ľڵ�
	p = L;
	//��i��Ԫ��֮ǰ����
	while (p && j<i-1) {
		p = p->next;
		j++;
	}
	if (p == NULL || j > i) {
		return false;
	}
	p0 = (Linklist)malloc(sizeof(LNode));
	p0->date = e;
	p0->next = p->next;
	p->next = p0;
	return true;
}

bool link_del(Linklist& L, int i, int& e)
{
	int j = 0;
	Linklist p, p0;//�����ڵ��ɾ���Ľڵ�
	p = L;//�ǵø�p��ֵ
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || j > i) {
		return false;
	}
	p0 = p->next;
	p->next = p0->next;
	free(p0);
	return true;
}

void creat(Linklist& L, int n) {
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--) {
		Linklist p = (Linklist)malloc(sizeof(LNode));
		int e;
		scanf("%d", &e);
		p->date = e;
		p->next = L->next;
		L->next = p;
	}
}