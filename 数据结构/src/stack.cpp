#include "stack.h"

bool init_stack(stack& s) {
	s.base = (int*)malloc(stack_max * sizeof(int));
	if (!s.base) {
		printf("malloc failed");
		exit(0);
	}
	s.top = s.base;
	s.stcak_size = stack_max;
	return true;
}

bool get_top(stack& s, int& e) {
	if (s.base==s.top) {
		printf("stack empty");
		return false;
	}
	e = *(s.top - 1);
	return true;
}

bool push(stack& s, int e) {
	//判断栈是否满
	if (s.top - s.base >= s.stcak_size) {
		s.base = (int*)realloc(s.base, (stack_max + 10) * sizeof(int));
		if (!s.base) {
			printf("realloc failed");
			return false;
		}
		s.top = s.base + s.stcak_size;//重新定位top指针
		s.stcak_size = s.stcak_size + 10;
	}
	*s.top++ = e;//先调用，后加加
	return true;
}

bool pop(stack& s, int& e) {
	if (s.base == s.top) {
		printf("stack empty");
		return false;
	}
	e = *--s.top;
	return true;
}

bool init_link_stack(linklist& s) {
	s = (linklist)malloc(sizeof(node));
	if (!s) {
		return false;
	}
	s->next = NULL;
	top = s;
	return true;
}

bool push_link(linklist& s, int e) {
	linklist newnode;
	if (top == NULL) {
		return false;
	}
	newnode = (linklist)malloc(sizeof(node));
	newnode->data = e;
	newnode->next = top;
	top = newnode;
	return true;
}

bool pop_link(linklist& s, int& e) {
	if (top == NULL) {
		return false;
	}
	linklist p = top;
	e = p->data;
	top = p->next;
	free(p);
	return true;
}