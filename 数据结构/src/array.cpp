#include "array.h"

bool transpose(tsmaritx m, tsmaritx& t){
	t.mu = m.nu;
	t.nu = m.nu;
	t.tu = m.tu;
	if (t.tu) {
		int q = 1;
		for (int i = 0; i < m.nu; ++i) {
			for (int j = 0; j < m.mu; ++j) {
				if (m.data[j].j == i) {
					t.data[q].i = m.data[j].j;
					t.data[q].j = m.data[j].i;
					t.data[q].e = m.data[j].e;
					++q;
				}
			}
		}
	}
	return true;
}