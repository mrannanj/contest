#include <stdio.h>

int N, M;
int EX[10002];
int EY[10002];
int drop[10002];

int dsu[102];
int dsu_size[102];

void dsu_init() {
	int i;
	for (i = 0; i < N; ++i) {
		dsu[i] = i;
		dsu_size[i] = 1;
	}
}

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

void dsu_mk() {
	int i;
	dsu_init();
	for (i = 0; i < M; ++i) {
		if (drop[i]) continue;
		int x = EX[i];
		int y = EY[i];
		if (dsu_find(x) != dsu_find(y)) {
			dsu_union(x, y);
		}
	}
}

int main() {
	int i, j, sum;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		EX[i] = x;
		EY[i] = y;
	}

	for (j = 0; j < M; ++j) {
		drop[j] = 1;
		dsu_mk();
		for (i = 0; i < M; ++i) {
			if (dsu[i] == i && (dsu_size[i] % 2 != 0)) {
				drop[j] = 0;
				break;
			}
		}
	}

	dsu_mk();
	sum = 0;
	for (i = 1; i <= N; ++i) {
		sum += dsu[i] == i;
	}
	printf("%d\n", sum);
}
