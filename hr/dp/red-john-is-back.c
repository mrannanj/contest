#include <stdio.h>
#include <math.h>

int T;
int N[50];
int primes[500000];
int primes_acc[500000];

void pri() {
	int i, j;
	for (i = 2; i < 500000; ++i) {
		primes_acc[i] = primes_acc[i-1];
		if (primes[i] == 1) continue;
		for (j = i; j < 500000; j += i) {
			primes[j] = 1;
		}
		primes_acc[i] += 1;
	}
}

void dp() {
	int i;
	N[0] = 1;
	for (i = 0; i <= 40; ++i) {
		N[i + 1] += N[i];
		N[i + 4] += N[i];
	}
}

int main() {
	int i;
	pri();
	dp();
	scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		printf("%d\n", primes_acc[N[x]]);
	}
	return 0;
}
