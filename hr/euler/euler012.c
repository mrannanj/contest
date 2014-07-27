#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAXN 100000

int64_t tri[MAXN+2];
int ddd[MAXN+2];
int64_t val[MAXN+2];
int nm_divs;
int max_div;

char st[MAXN];
int pr[MAXN];
int np;

int div[10002];
int dxp[10002];

void sieve() {
	int i, j;
	for (i = 2; i <= MAXN; ++i) {
		if (st[i]) continue;
		for (j = i; j <= MAXN; j += i) {
			st[j] = i;
		}
		pr[np++] = i;
	}
}

int main() {
	int i, T, N;

	sieve();

	for (i = 1; i < MAXN; ++i) {
		tri[i] = tri[i-1] + i;
	}

	for (i = 1; i < MAXN; ++i) {
		int j, ndiv = 1;
		int x = tri[i];
		int tmp, k;
		div[0] = 1;
		dxp[0] = 1;
		for (j = 0; x > 1 && j < np; ++j) {
			int prr = pr[j];
			if (x % prr) continue;
			div[ndiv] = prr;
			dxp[ndiv] = 0;
			while (x % prr == 0) {
				x /= prr;
				++dxp[ndiv];
			}
			++ndiv;
		}

		tmp = 1;
		for (x = 1; x < ndiv; ++x) {
			tmp *= (dxp[x] + 1);
		}
		ndiv = tmp;

		if (ndiv > max_div) {
			max_div = ndiv;
			val[nm_divs] = tri[i];
			ddd[nm_divs] = ndiv;
			nm_divs++;
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; ddd[i] <= N; ++i);
		printf("%ld\n", val[i]);
	}

	return 0;
}
