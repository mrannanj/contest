#include <stdio.h>
#include <string.h>

int a1[10002];

int sums[10002];

void nextpow()
{
	int i, carry = 0;

	for (i = 0; i < 10002; ++i) {
		int res = 2 * a1[i] + carry;
		carry = res / 10;
		a1[i] = res % 10;
	}
}

int digitsum()
{
	int i, res = 0;

	for (i = 0; i < 10002; ++i) {
		res += a1[i];
	}

	return res;
}

int main()
{
	int i, T;

	a1[0] = 1;
	sums[0] = digitsum();
	for (i = 1; i < 10002; ++i) {
		nextpow();
		sums[i] = digitsum();
	}

	scanf("%d", &T);
	while (T--) {
		int N;

		scanf("%d", &N);
		printf("%d\n", sums[N]);
	}

	return 0;
}
