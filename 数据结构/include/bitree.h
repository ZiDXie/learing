#pragma once
#ifndef BITREE_H
#define BITREE_H

#include "iostream"
/*
	�ڵ�Ķ��Ƿ�֧�ĸ���
	���Ķ��ǽڵ��еĶȵ����ֵ
	���Ĳ�δӸ��ڵ㿪ʼ�����ڵ�Ϊ1
	�����ڵ�
	Ҷ�ӽڵ㣺��Ϊ0
	��֧�ڵ�ȴ���0
	���Ϊ����Ҷ�ӽڵ����ڵ������
*/

/*
�����������ʣ�
��i��������2^(i-1)���ڵ�
���Ϊk����������2^k-1���ڵ�
����������
���Ϊk�Һ���2k-1�����Ķ�����
��ȫ��������
���������� n ���������������б��Ϊ 1 �� n �Ľ��һһ��Ӧ��
���� n ��������ȫ�����������Ϊ ? |log2 n|? +1
*/

/*
��������������
*/

typedef struct BiTnode {
	int data;
	struct BiTnode* lchild, * rchild;
}BiTnode, * BiTree;

/*
��������
*/
typedef struct TriTnode {
	int data;
	struct TriTnode* lchild, * rchild;
	struct TriTnode* parent;
}Trinode, * TriTree;

/*
	���������㷨
*/
void printelem(int e);

//�������
void preorder(BiTree T, void (*visit)(int e));
//�������
void inorder(BiTree T,void (*visit)(int e));
//�������
void afterorder(BiTree T, void (*visit)(int e));

//������
bool creat(BiTree& T);
//�����ĸ߶�
int depth(BiTree T);
//�����Ľڵ���
int size(BiTree T);
#endif
