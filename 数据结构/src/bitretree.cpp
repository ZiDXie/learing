#include "bitretree.h"
bool inoder(bithetree T, bool (*visit)(int e)) {
	//T为头节点
	bithetree p = T->lchild;
	while (p != T)//遍历结束的条件
	{
		while (p->ltag == link)
		{
			p = p->lchild;//访问某个根节点最左下角的节点
		}
		if (!visit(p->data)) {
			return false;
		}
		//访问左下角后访问后继节点
		while (p->rtag == thread && p->rchild != T) {
			p = p->rchild;
			visit(p->data);
		}
		//右边为右子树的情况
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
		//处理最后的节点
		pre->rchild = third;
		pre->rtag = thread;
		third->rchild = pre;
	}
	return true;
}