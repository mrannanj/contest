#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int n, m;

int ex[3000];
int ey[3000];
int dsu[52];
int dsu_size[52];

int dsu_find(int i) {
	if (dsu[i] != i) {
		dsu[i] = dsu_find(dsu[i]);
	}
	return dsu[i];
}

void dsu_union(int i, int j) {
	int iroot = dsu_find(i);
	int jroot = dsu_find(j);
	dsu[jroot] = iroot;
	dsu_size[iroot] += dsu_size[jroot];
}

int main() {
	uint64_t danger = 1;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		int x,y;
		scanf("%d %d", &x, &y);
		ex[i] = x;
		ey[i] = y;
	}

	for (i = 0; i <= n; ++i) {
		dsu[i] = i;
		dsu_size[i] = 1;
	}

	for (i = 0; i < m; ++i) {
		int x = ex[i];
		int y = ey[i];
		if (dsu_find(x) != dsu_find(y)) {
			dsu_union(x, y);
		}
	}
	
	for (i = 1; i <= n; ++i) {
		if (dsu[i] == i) {
			danger <<= dsu_size[i] - 1;
		}
	}
	printf("%" PRIu64 "\n", danger);
	return 0;
}
