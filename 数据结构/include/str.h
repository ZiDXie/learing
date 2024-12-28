#pragma once
#ifndef STR_H
#define STR_H
#define MAX_SIZE 255
#include "iostream"
/*
	���Ķѷ���
*/
typedef struct {
	char* ch;
	int length;
}Hstring;
/*
	��������
*/
typedef char Sstring[MAX_SIZE + 1];


bool str_assign(Hstring& t, char* chars);
int str_len(Hstring t);
int str_compare(Hstring s,Hstring t);
bool concat(Hstring& T, Hstring s1, Hstring s2);
bool substring(Hstring T, Hstring& sub, int pos, int len);

bool concat_s(Sstring& T, Sstring s1, Sstring s2);
bool substring_s(Sstring T, Sstring& sub, int pos, int len);

//kmp�㷨���ҵ��Ѿ�ƥ�䲿�ֵĹ���ǰ��׺��������ģʽ����ָ��ָ�򹫹�ǰ��׺����һ��
//next���鶨�壺ÿ��ʧ���jָ��ָ���λ�ã��㷨���Ӷ�O��m+n��
//next�����ֵΪ��ǰԪ��ǰ�沿�������ǰ��׺��1
int next[];
//��next����,ʱ�临�Ӷ�ΪO��n��
void get_next(Sstring T, int next[]);

int index_kmp(Sstring S, Sstring T, int pos);
#endif





