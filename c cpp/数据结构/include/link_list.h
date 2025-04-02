#pragma once
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "iostream"

typedef struct LNode{
	int date;
	struct LNode* next;
}LNode,*Linklist;

bool link_init(Linklist& L);
//ʱ�临�Ӷ�ΪO��n��
bool link_insert(Linklist& L, int i, int e);
bool link_del(Linklist& L, int i, int& e);
void creat(Linklist& L,int n);
/*
�����ֻ���������Ϣ��û�й�������Ϣ�򡣴洢�ܶȴ󣬿ռ������ʸߡ�
����ͨ������ֱ�ӷ����κ�����Ԫ�أ����������ȡ��
���롢ɾ���������������Ԫ�ص��ƶ���
��ʽ�洢�ṹ����Ҫ�ص㣺
����г�������Ϣ���⣬���б�ʾ������Ϣ��ָ���򡣴洢�ܶ�С�������ʵ͡�
�߼������ڵĽ���������ϲ������ڡ�
���롢ɾ���������㡢�������ƶ���㣬ֻ���޸Ľ���е�ָ�뼴�ɡ�
*/
#endif
