/*
	This file use to test the code.
*/

/*
	file include
*/
#include "linear_list.h"
#include "link_list.h"
#include "stack.h"
#include "queue.h"
#include "str.h"

/*
	user function declare 
*/
void linear_show();

/*
	user main function
*/
int main() {
	printf("-------------------------------------------\n");
	printf("|   选择数字以查看不同的数据结构使用示范  |\n");
	printf("-------------------------------------------\n");
	printf("|            1:线性表的顺序实现           |\n");
	printf("|            2:线性表的链式实现           |\n");
	printf("|            3:栈实现                     |\n");
	printf("|            4:循环队列实现               |\n");
	printf("-------------------------------------------\n");
	int num = 0;
	printf("请选择你的数字：");
	scanf_s("%d", &num);
	switch (num)
	{
		case 1:
			linear_show();
		
	}
	return 0;
}

/*
	user function define
*/
void linear_show() {
	SqList list; 
	Init(list);
	for (int i = 0; i < 5; i++)
	{
		Insert(list, i + 1, i + 1);
	}
	
	printf("插入结果:"); for (int i = 0; i < list.length; i++)
	printf("%d", list.elem[i]);
	printf("\n");
	int e = 0;
	Del(list,2,e);
	printf("删除结果:");
	for (int i = 0; i < list.length; i++) {
		printf("%d", list.elem[i]);
	}
	printf("\n");
	int num=0;
	num=find(list,3);
	printf("%d",num);
}