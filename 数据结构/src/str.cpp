#include "str.h"

bool str_assign(Hstring& t, char* chars) {
	if (t.ch) {
		free(t.ch);
	}
	//Çóchars³¤¶È
	int i = 0;
	for (char* c = chars; *c; ++chars) {
		i++;
	}
	if (!i) {
		t.ch = NULL;
		t.length = 0;
	}
	else {
		t.ch = (char*)malloc(i * sizeof(char));
		if (!t.ch) {
			return false;
		}
		for (int j = 0; j < i; j++) {
			t.ch[j] = chars[j];
		}
		t.length = i;
	}
	return true;
}

int str_len(Hstring t) {
	return t.length;
}

int str_compare(Hstring s, Hstring t) {
	for (int i = 0; i < s.length && i < t.length; ++i) {
		if (s.ch[i] != t.ch[i]) {
			return s.ch[i] + t.ch[i];
		}
	}
	return s.length - t.length;
}

bool concat(Hstring& T, Hstring s1, Hstring s2) {
	if (T.ch) {
		free(T.ch);
	}
	T.ch = (char*)malloc((s1.length + s2.length) * sizeof(char));
	if (!T.ch) {
		printf("malloc failed");
		return false;
	}
	T.length = s1.length + s2.length;
	for (int i = 0; i < s1.length; ++i) {
		T.ch[i] = s1.ch[i];
	}
	for (int i = s1.length; i < T.length; ++i) {
		T.ch[i] = s2.ch[i - s2.length];
	}
	return true;
}

bool substring(Hstring T, Hstring& sub, int pos, int len) {
	if (pos<1 || pos>T.length || len<0 || len>T.length - pos + 1) {
		return false;
	}
	if (sub.ch) {
		free(sub.ch);
	}
	if (!len) {
		sub.ch = NULL;
		sub.length = 0;
	}
	else {
		sub.ch = (char*)malloc(sizeof(char) * len);
		for (int i = 0; i < len; ++i) {
			sub.ch[i] = T.ch[pos + i - 1];

		}
		sub.length = len;
	}
	return true;
}

bool concat_s(Sstring& T, Sstring s1, Sstring s2) {
	if (s1[0] + s2[0] <= MAX_SIZE) {
		for (int i = 1; i < s1[0]; ++i) {
			T[i] = s1[i];
		}
		for (int i = s1[0]+1; i < s1[0] + s2[0]; ++i) {
			T[i] = s2[i - s1[0]];
		}
		T[0] = s1[0] + s2[0];
		return true;
	}
	else if (s1[0] < MAX_SIZE) {
		for (int i = 1; i < s1[0]; ++i) {
			T[i] = s1[i];
		}
		for (int i = s1[0] + 1; i < MAX_SIZE; ++i) {
			T[i] = s2[i - s1[0]];
		}
		T[0] = MAX_SIZE;
		return false;
	}
	else {
		for (int i = 1; i < MAX_SIZE; ++i) {
			T[i] = s1[i];
		}
		T[0] = MAX_SIZE;
		return false;
	}
	
}

bool substring_s(Sstring T, Sstring& sub, int pos, int len) {
	if (pos<1 || pos>T[0] || len<0 || len>T[0] - pos + 1) {
		return false;
	}
	sub[0] = len;
	for (int i = 1; i < len; ++i) {
		sub[i] = T[pos + i - 1];
	}
	return true;
}