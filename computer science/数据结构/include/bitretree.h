#pragma once
#ifndef BITRETREE_H
#define BITRETREE_H
#include "iostream"

//���ý������������գ���Lchild���ָ��ָ�����������������־���ֵΪ��ָ�� Link��������Lchild���ָ��ָ���䡰ǰ�����������־��ֵΪ������ Thread�� 
//���ý������������գ���rchild���ָ��ָ���������������ұ�־���ֵΪ ��ָ�� Link��������rchild���ָ��ָ���䡰��̡�������
// ��־��ֵΪ������ Thread��
typedef enum {link,thread} pointtag;
typedef struct bithrnode{
	int data;
	bithrnode* lchild, * rchild;
	pointtag ltag, rtag;
}bithrnode,*bithetree;
bithetree pre;
//�������������������ʹ�÷ǵݹ�ı����㷨
bool inoder(bithetree T, bool (*visit)(int e));
//��������������
void inthread(bithetree T);
bool inorderthread(bithetree& b, bithetree T);
#endif