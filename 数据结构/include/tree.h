#pragma once
#ifndef TREE_H
#define TREE_H

#define MAX_SIZE 100
/*
˫�ױ�ʾ��
*/
typedef struct {
	int data;
	int parent;
}ptnode;
typedef struct {
	ptnode nodes[MAX_SIZE];
	int r, n;//����λ�úͽڵ���
};

/*
���ӽڵ��ʾ��
*/
typedef struct  ctnode{
	int child;
	ctnode* next;
}*childptr;

typedef struct {
	int data;
	childptr child;
}ctbox;

typedef struct {
	ctbox node[MAX_SIZE];
	int r, n;
}ctree;

/*
* ���Ķ������� (����-�ֵܣ��洢��ʾ��
�Զ���������Ϊ���Ĵ洢�ṹ��
��������ֱ�ָ��ý��ĵ�һ���������н����ӽ�����һ���ֵܽ�㣬�ֱ�����Ϊfirstchild���nextsibling��
*/
//���������������ת��
typedef struct csnode{
	int data;
	csnode* firstchild, * nextsibling;
}csnode,*cstree;
#endif