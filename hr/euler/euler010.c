#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXN 1000002

int pr[MAXN];
int st[MAXN];
int64_t s[MAXN];

void sieve() {
	int i, j;
	for (i = 2; i < MAXN; ++i) {
		if (st[i]) {
			s[i] = s[i-1];
		} else {
			s[i] = s[i-1] + i;
		}
		for (j = i; j < MAXN; j += i) {
			st[j] = 1;
		}
	}
}

int main() {
	int T, N;

	sieve();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%" PRId64 "\n", s[N]);
	}

	return 0;
}
