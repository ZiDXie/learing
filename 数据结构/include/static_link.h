#pragma once
#ifndef STATIC_LINK_H
#define STATIC_LINK_H

#define MAX_SIZE 100
#include "iostream"

struct elem{
	int data;
	int next;
};

struct SLinklist {
	elem s[MAX_SIZE + 1];
	int head, avail;
};

bool stack_link_init(SLinklist& s);

//时间复杂度为O（n）
bool stack_link_insert(SLinklist& s, int i,int e);

bool stack_link_del(SLinklist& s, int i,int &e);

#endif