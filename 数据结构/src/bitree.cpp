#include "bitree.h"

void printelem(int e) {
	printf("e");
}

void preorder(BiTree T, void (*visit)(int e)) {
	if (T) {
		(*visit)(T->data);
		preorder(T->lchild,visit);
		preorder(T->rchild,visit);
	}
}

void inorder(BiTree T, void (*visit)(int e)) {
	if (T) {
		inorder(T->lchild, visit);
		(*visit)(T->data);
		inorder(T->rchild, visit);
	}
}

void afterorder(BiTree T, void (*visit)(int e)) {
	if (T) {
		afterorder(T->lchild, visit);
		afterorder(T->rchild, visit);
		(*visit)(T->data);
	}
}

bool creat(BiTree& T) {
	int i;
	scanf("%d", &i);
	if (i == ' ') {
		T == NULL;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTnode));
		if (!T) {
			printf("malloc failed");
			return false;
		}
		T->data = i;
		//构造左右子树
		creat(T->lchild);
		creat(T->rchild);
	}
	return true;
}

//弄清高度是什么意思
int depth(BiTree T) {
	int l;
	int r;
	if (!T) {
		return 0;
	}
	l = depth(T->lchild);
	r = depth(T->rchild);
	return (l > r) ? (l + 1) : (r + 1);
}

int size(BiTree T) {
	int l;
	int r;
	if (!T) {
		return 0;
	}
	l = size(T->lchild);
	r = size(T->rchild);
	return (l + r + 1);
}