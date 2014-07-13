#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int32_t pals[1000001];
int32_t np;

int is_palindrome(int32_t x) {
	int32_t i, j, xx = x, rev = 0;
	int32_t a[10];
	for (i = 0; xx > 0; ++i) {
		a[i] = xx % 10;
		xx /= 10;
	}
	for (j = 0; j < i; ++j) {
		rev += pow(10, i-j-1) * a[j];
	}
	return rev == x;
}

int comp(const void* p1, const void* p2) {
	int32_t* x1 = (int32_t*)p1;
	int32_t* x2 = (int32_t*)p2;
	return *x1 - *x2;
}

int search(int32_t x) {
	int i;
	for (i = 1; i < np; ++i) {
		if (pals[i] >= x) return i-1;
	}
	return i;
}

int main() {
	int32_t i, j, T;
	for (i = 100; i <= 999; ++i) {
		for (j = 100; j <= 999; ++j) {
			int32_t x = i * j;
			if (x >= 101101 && is_palindrome(x)) {
				pals[np++] = x;
			}
		}
	}
	qsort(pals, np, sizeof(int32_t), comp);
	scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		printf("%d\n", pals[search(x)]);
	}
	return 0;
}
