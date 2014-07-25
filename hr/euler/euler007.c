#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

#define MAXN 1000000

char st[MAXN];
int64_t pr[MAXN];
int64_t np;

void sieve() {
	int64_t i, j;
	np = 1;
	for (i = 2; i < MAXN; ++i) {
		if (st[i]) continue;
		for (j = i; j < MAXN; j += i) {
			st[j] = 1;
		}
		pr[np++] = i;
	}
}

int main() {
	int T, N, i;

	sieve();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%" PRId64 "\n", pr[N]);
	}

	return 0;
}
