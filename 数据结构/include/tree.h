#pragma once
#ifndef TREE_H
#define TREE_H

#define MAX_SIZE 100
/*
双亲表示法
*/
typedef struct {
	int data;
	int parent;
}ptnode;
typedef struct {
	ptnode nodes[MAX_SIZE];
	int r, n;//跟的位置和节点数
};

/*
孩子节点表示法
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
* 树的二叉链表 (孩子-兄弟）存储表示法
以二叉链表作为树的存储结构。
两个链域分别指向该结点的第一个孩链表中结点的子结点和下一个兄弟结点，分别命名为firstchild域和nextsibling域
*/
//这是树与二叉树的转换
typedef struct csnode{
	int data;
	csnode* firstchild, * nextsibling;
}csnode,*cstree;
#endif