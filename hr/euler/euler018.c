#include <stdio.h>
#include <string.h>

#define MAX(a,b) (a>b?a:b)

int P[16][16];

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		int i, j, N;

		memset(P, 0, 16*16*sizeof(int));
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			for (j = 0; j <= i; ++j) {
				scanf("%d", &P[i][j]);
			}
		}

		for (i = N-1; i > 0; --i) {
			for (j = 0; j < i; ++j) {
				P[i-1][j] += MAX(P[i][j], P[i][j+1]);
			}
		}

		printf("%d\n", P[0][0]);
	}

	return 0;
}
