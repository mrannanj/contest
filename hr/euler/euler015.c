#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define MOD 1000000007

int p[1002][1002];

void pascal() {
	int i,j;
	p[0][0] = 1;
	for (i = 0; i <= 1000; ++i) {
		for (j = 0; j <= i; ++j) {
			p[i+1][j] = (p[i+1][j] + p[i][j]) % MOD;
			p[i+1][j+1] = (p[i+1][j+1] + p[i][j]) % MOD;
		}
	}
}

int main() {
	int T;
	int i, j;

	pascal();
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d\n", p[N+M][M]);
	}

	return 0;
}
