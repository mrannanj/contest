#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

#define MAXN 40000000000000001
#define MAXF 100

uint64_t fbn[MAXF];
uint64_t fbs[MAXF];
int n;

int search(uint64_t x) {
	int i;
	for (i = 1; i < n; ++i) {
		if (fbn[i] > x) {
			return i-1;
		} else if (fbn[i] == x) {
			return i;
		}
	}
	return 0;
}

int main() {
	int t;
	fbn[1] = 1;
	fbn[2] = 1;
	for (n = 3; fbn[n-1] <= MAXN; ++n) {
		fbn[n] = fbn[n-1] + fbn[n-2];
		fbs[n] = fbs[n-1] + !(fbn[n]&1) * fbn[n];
	}

	scanf("%d", &t);

	while (t--) {
		uint64_t N;
		scanf("%" PRIu64, &N);
		printf("%" PRIu64 "\n", fbs[search(N)]);
	}
	return 0;
}
