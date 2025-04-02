#pragma once
#ifndef BITRETREE_H
#define BITRETREE_H
#include "iostream"

//若该结点的左子树不空，则Lchild域的指针指向其左子树，且左标志域的值为“指针 Link”；否则，Lchild域的指针指向其“前驱”，且左标志的值为“线索 Thread” 
//若该结点的右子树不空，则rchild域的指针指向其右子树，且右标志域的值为 “指针 Link”；否则，rchild域的指针指向其“后继”，且右
// 标志的值为“线索 Thread”
typedef enum {link,thread} pointtag;
typedef struct bithrnode{
	int data;
	bithrnode* lchild, * rchild;
	pointtag ltag, rtag;
}bithrnode,*bithetree;
bithetree pre;
//线索二叉树的中序遍历使用非递归的遍历算法
bool inoder(bithetree T, bool (*visit)(int e));
//生成线索二叉树
void inthread(bithetree T);
bool inorderthread(bithetree& b, bithetree T);
#endif