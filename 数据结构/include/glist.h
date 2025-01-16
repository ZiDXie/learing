#pragma once
#ifndef GLIST_H
#define GLIST_H

typedef enum {ATON,LIST} elemtag;//原子和子表

/*
头尾链表存储形式
*/
typedef struct glist
{
	elemtag tag;
	union {
		char data;
		struct {
			struct glist* hp, * tp;
		}ptr;
	};
}*glist;

/*
扩展链表存储
*/
typedef struct gnode {
	elemtag tag;
	union {
		char data;
		struct gnode* next;

	};
	struct gnode* next;
}*gnode;

#endif
