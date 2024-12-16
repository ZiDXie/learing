#pragma once
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "iostream"

typedef struct LNode{
	int date;
	struct LNode* next;
}LNode,*Linklist;

bool link_init(Linklist& L);
bool link_insert(Linklist& L, int i, int e);
bool link_del(Linklist& L, int i, int& e);
#endif
