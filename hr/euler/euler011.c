#include <stdio.h>

#define MAX(a,b) (a>b?a:b)

int T[32][32];
int res;

int main() {
	int i, j;

	for (i = 0; i < 32; ++i) {
		for (j = 0; j < 32; ++j) {
			T[i][j] = 1;
		}
	}

	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			scanf("%d", &T[i][j]);
		}
	}

	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			int x = T[i][j] * T[i+1][j] * T[i+2][j] * T[i+3][j];
			res = MAX(res, x);
			x = T[i][j] * T[i][j+1] * T[i][j+2] * T[i][j+3];
			res = MAX(res, x);
			x = T[i][j] * T[i+1][j+1] * T[i+2][j+2] * T[i+3][j+3];
			res = MAX(res, x);
			if (i >= 3) {
				x = T[i][j] * T[i-1][j+1]
					* T[i-2][j+2] * T[i-3][j+3];
				res = MAX(res, x);
			}
		}
	}
	printf("%d\n", res);

	return 0;
}
