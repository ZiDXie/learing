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
	printf("|   ѡ�������Բ鿴��ͬ�����ݽṹʹ��ʾ��  |\n");
	printf("-------------------------------------------\n");
	printf("|            1:���Ա��˳��ʵ��           |\n");
	printf("|            2:���Ա����ʽʵ��           |\n");
	printf("|            3:ջʵ��                     |\n");
	printf("|            4:ѭ������ʵ��               |\n");
	printf("-------------------------------------------\n");
	int num = 0;
	printf("��ѡ��������֣�");
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
	
	printf("������:"); for (int i = 0; i < list.length; i++)
	printf("%d", list.elem[i]);
	printf("\n");
	int e = 0;
	Del(list,2,e);
	printf("ɾ�����:");
	for (int i = 0; i < list.length; i++) {
		printf("%d", list.elem[i]);
	}
	printf("\n");
	int num=0;
	num=find(list,3);
	printf("%d",num);
}