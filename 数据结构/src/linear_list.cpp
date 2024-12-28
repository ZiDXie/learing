#include "linear_list.h"

/*
	创建一个空的顺序表
*/
bool Init(SqList& L) {
	//分配内存
	L.elem = (int*)malloc(MAXSIZE * sizeof(int));
	if (!L.elem) {
		printf("malloc failed");
		exit(0);
	}
	L.length = 0;
	L.list_size = MAXSIZE;
	return true;
}

/*
	插入元素
*/
bool Insert(SqList& L,int i,int e) {
	if (i<1 || i>L.length+1) {
		return false;
	}
	if (L.length >= L.list_size) {
		int* newbase = (int*)realloc(L.elem,(INCRESE+L.list_size) * sizeof(int));
		if (!newbase) {
			printf("realloc failed");
			exit(0);
		}
		L.elem = newbase;
		L.list_size = INCRESE + L.list_size;
	}
	//插入元素
	int* q = &(L.elem[i-1]);
	for (int* p = &(L.elem[L.length - 1]);p>=q;p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return true;
}


/*
	删除元素
*/
bool Del(SqList& L,int i,int& e) {
	//判断位置是否正确
	if (i<1 || i>L.length) {
		printf("The location is wrong");
		return false;
	}
	int* p = &(L.elem[i - 1]);//删除元素的地址
	int* q = L.elem + L.length - 1;//末尾元素的地址
	e = *p;
	for (++p; p <= q;++p) {
		*(p - 1) = *p;
	}
	--L.length;
	return true;
}

/*
	查找元素的位置
*/
int find(SqList& L, int e) {
	int locate = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) {
			locate = i+1;
			return locate;
		}
	}
	return 0;
}