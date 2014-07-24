#include <stdio.h>

int pr[50];

void sieve() {
	int i, j;
	for (i = 2; i < 50; ++i) {
		if (pr[i]) continue;
		for (j = i; j < 50; j += i) {
			pr[j] = i;
		}
	}
}

int main() {
	int i, T;
	sieve();
	scanf("%d", &T);
	while (T--) {
		int i, N, x = 1;
		scanf("%d", &N);
		for (i = 2; i <= N; ++i) {
			if (x%i != 0) {
				x *= pr[i];
			}
		}
		printf("%d\n", x);
	}
	return 0;
}

