#pragma once
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "iostream"

typedef struct LNode{
	int date;
	struct LNode* next;
}LNode,*Linklist;

bool link_init(Linklist& L);
//时间复杂度为O（n）
bool link_insert(Linklist& L, int i, int e);
bool link_del(Linklist& L, int i, int& e);
void creat(Linklist& L,int n);
/*
结点中只有自身的信息域，没有关联的信息域。存储密度大，空间利用率高。
可以通过计算直接访问任何数据元素，可以随机存取。
插入、删除操作会引起大量元素的移动。
链式存储结构的主要特点：
结点中除自身信息域外，还有表示关联信息的指针域。存储密度小，利用率低。
逻辑上相邻的结点在物理上不必相邻。
插入、删除操作方便、灵活，不必移动结点，只需修改结点中的指针即可。
*/
#endif
