#pragma once
#ifndef BITREE_H
#define BITREE_H

#include "iostream"
/*
	节点的度是分支的个数
	树的度是节点有的度的最大值
	树的层次从根节点开始，根节点为1
	树各节点
	叶子节点：度为0
	分支节点度大于0
	深度为树中叶子节点所在的最大层次
*/

/*
二叉树的性质：
第i层至多有2^(i-1)个节点
深度为k的树至多有2^k-1个节点
满二叉树：
深度为k且含有2k-1个结点的二叉树
完全二叉树：
树中所含的 n 个结点和满二叉树中编号为 1 至 n 的结点一一对应。
具有 n 个结点的完全二叉树的深度为 ? |log2 n|? +1
*/

/*
二叉树二叉链表
*/

typedef struct BiTnode {
	int data;
	struct BiTnode* lchild, * rchild;
}BiTnode, * BiTree;

/*
三叉链表
*/
typedef struct TriTnode {
	int data;
	struct TriTnode* lchild, * rchild;
	struct TriTnode* parent;
}Trinode, * TriTree;

/*
	遍历树的算法
*/
void printelem(int e);

//先序遍历
void preorder(BiTree T, void (*visit)(int e));
//中序遍历
void inorder(BiTree T,void (*visit)(int e));
//后序遍历
void afterorder(BiTree T, void (*visit)(int e));

//创建树
bool creat(BiTree& T);
//求树的高度
int depth(BiTree T);
//求树的节点数
int size(BiTree T);
#endif
