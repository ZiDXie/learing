#include "bitretree.h"
bool inoder(bithetree T, bool (*visit)(int e)) {
	//TΪͷ�ڵ�
	bithetree p = T->lchild;
	while (p != T)//��������������
	{
		while (p->ltag == link)
		{
			p = p->lchild;//����ĳ�����ڵ������½ǵĽڵ�
		}
		if (!visit(p->data)) {
			return false;
		}
		//�������½Ǻ���ʺ�̽ڵ�
		while (p->rtag == thread && p->rchild != T) {
			p = p->rchild;
			visit(p->data);
		}
		//�ұ�Ϊ�����������
		p = p->rchild;

	}
	return true;
}

void inthread(bithetree T) {
	if (T) {
		inthread(T->lchild);
		if (!T->lchild) {
			T->ltag = thread;
			T->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = thread;
			pre->rchild = T;
		}
		pre = T;
		inthread(T->rchild);
	}
}

bool inorderthread(bithetree& b, bithetree T) {
	bithetree third;
	if (!(third = (bithetree)malloc(sizeof(bithrnode)))) {
		return false;
	}
	third->ltag = link;
	third->rtag = thread;
	third->rchild = third;
	if (!T) {
		third->lchild = third;
	}
	else {
		third->lchild = T;
		pre = third;
		inthread(T);
		//�������Ľڵ�
		pre->rchild = third;
		pre->rtag = thread;
		third->rchild = pre;
	}
	return true;
}