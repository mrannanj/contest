#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define RANGE 3000
#define MAXN 12000

#define MAX(a,b) (a>b?a:b)

int64_t N[MAXN];

int main() {
	int i, T;
	int64_t a, b;

	for (i = 0; i < MAXN; ++i) {
		N[i] = -1;
	}

	for (a = 1; a <= RANGE; ++a) {
		for (b = a+1; b <= RANGE; ++b) {
			int64_t prod, sum;
			int64_t ic;
			double fc = sqrt(a*a + b*b);

			if (fc != ceilf(fc)) continue;
			ic = fc;
			prod = ic * a * b;
			sum = ic + a + b;
			N[sum] = MAX(prod, N[sum]);
		}
	}

	scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		printf("%" PRId64 "\n", N[x]);
	}

	return 0;
}
