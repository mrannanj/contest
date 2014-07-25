#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int64_t sq(uint64_t x) {
	return x*x;
}

int64_t cb(uint64_t x) {
	return x*x*x;
}

int64_t sum_to(uint64_t x) {
	return (x*(x+1))/2;
}

int64_t sum_of_squares(uint64_t x) {
	return (2*cb(x) + 3*sq(x) + x)/6;
}

int main() {
	int64_t T, N, i;

	scanf("%" PRId64, &T);
	while (T--) {
		scanf("%" PRId64, &N);
		printf("%" PRId64 "\n", sq(sum_to(N)) - sum_of_squares(N));
	}
	return 0;
}
