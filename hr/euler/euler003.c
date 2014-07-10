#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

#define PRIMES 1000001

char sieve[PRIMES];
uint64_t np;
uint64_t ps[PRIMES];

void era_sieve() {
	uint64_t i, j;
	for (i = 2; i < PRIMES; ++i) {
		if (sieve[i]) continue;
		ps[np++] = i;
		for (j = i; j < PRIMES; j += i) {
			sieve[j] = 1;
		}
	}
}

uint64_t largest_prime_factor(uint64_t x) {
	uint64_t i, sq = sqrt(x);
	for (i = 0; ps[i] <= sq; ++i) {
		if (x%ps[i] == 0) {
			return largest_prime_factor(x/ps[i]);
		}
	}
	return x;
}

int main() {
	int T;
	era_sieve();
	scanf("%d", &T);
	while (T--) {
		uint64_t N;
		scanf("%" PRIu64, &N);
		printf("%" PRIu64 "\n", largest_prime_factor(N));
	}
	return 0;
}
