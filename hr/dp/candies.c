#include <stdio.h>
#include <limits.h>

int N;
int R[(int)(1e5) + 1];
int l[(int)(1e5) + 1];
int r[(int)(1e5) + 1];

int min(int a, int b) {
	return a<b?a:b;
}

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	int i;
	long long sum = 0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &R[i]);
	}
	for (i = 1; i < N; ++i) {
		if (R[i-1] < R[i]) {
			r[i] = r[i-1] + 1;
		}
	}
	for (i = N-1; i > 0; --i) {
		if (R[i-1] > R[i]) {
			l[i-1] = l[i] + 1;
		}
	}

	for (i = 0; i < N; ++i) {
		sum += max(l[i], r[i]) + 1;
	}
	printf("%lld\n", sum);
	return 0;
}
