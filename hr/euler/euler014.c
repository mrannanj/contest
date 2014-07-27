#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXN 10000001

int64_t C[MAXN];
int M[MAXN];

int64_t coll(int64_t n) {
	int64_t ret;

	if (n < MAXN && C[n]) return C[n];
	if (n % 2) {
		ret = coll(3*n + 1) + 1;
	} else {
		ret = coll(n/2) + 1;
	}
	if (n < MAXN) C[n] = ret;
	return ret;
}

int main() {
	int i, T;
	int64_t mx_len, mx_val;

	mx_len = mx_val = 0;
	C[1] = 1;
	for (i = 1; i <= 5000000; ++i) {
		if (coll(i) >= mx_len) {
			mx_len = coll(i);
			mx_val = i;
		}
		M[i] = mx_val;
	}

	scanf("%d", &T);
	while (T--) {
		int N, i;

		scanf("%d", &N);
		printf("%d\n", M[N]);
	}

	return 0;
}
