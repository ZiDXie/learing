#pragma once
#ifndef GLIST_H
#define GLIST_H

typedef enum {ATON,LIST} elemtag;//ԭ�Ӻ��ӱ�

/*
ͷβ����洢��ʽ
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
��չ����洢
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
