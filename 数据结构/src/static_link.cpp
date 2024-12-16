#include "static_link.h"

bool stack_link_init(SLinklist& s) {
	for (int i = 0; i < MAX_SIZE - 2; i++) {
		s[i].cur = i + 1;
	}
	s[MAX_SIZE - 2].cur = s[MAX_SIZE - 1].cur = 0;
	return true;
}

int malloc_s(SLinklist& s) {
	int index = s[0].cur;
	s[0].cur = s[index].cur;
	return index;
}

void free_s(SLinklist& s,int i) {
	s[i].cur = s[0].cur;
	s[0].cur = i;
}

int link_length(SLinklist s) {
	int len = 0;
	int index = MAX_SIZE - 1;
	while (s[index].cur) {
		index++;
		len++;
	}
	return len;
}

bool stack_link_insert(SLinklist& s, int i, int e) {

}