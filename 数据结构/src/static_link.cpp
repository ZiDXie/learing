#include "static_link.h"

bool stack_link_init(SLinklist& s) {
	for (int i = 0; i < MAX_SIZE; i++) {
		s.s[i].next = i + 1;
	}
	s.s[MAX_SIZE].next =  0;
	return true;
}

bool stack_link_insert(SLinklist& s, int i, int e) {
	int q;
	if (s.avail == 0) {
		return false;
	}
	q = s.avail;
	s.avail = s.s[q].next;
	s.s[q].data = e;
	s.s[q].next=s.s[i].next;
	s.s[i].next = q;
	return true;
}

bool stack_link_del(SLinklist& s, int i, int& e) {
	int q;
	q = s.s[i].next;
	s.s[i].next = s.s[q].next;
	s.s[q].next = s.avail;
	s.avail = q;
	return true;
}