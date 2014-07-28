#include <stdio.h>
#include <string.h>

int a1[2600];
int a2[2600];
int a3[2600];
int sums[1002];

void add()
{
	int i, carry = 0;

	for (i = 0; i < 2600; ++i) {
		int res = a2[i] + a3[i] + carry;
		a2[i] = res % 10;
		carry = res / 10;
	}
}

void mult(int n)
{
	int i, adj = 0;

	memset(a2, 0, sizeof(int)*2600);

	while (n)
	{
		int x = n % 10;
		memset(a3, 0, sizeof(int)*2600);
		for (i = 0; i < 2599; ++i)
		{
			int res = a1[i] * x;
			a3[adj+i] += res % 10;
			a3[adj+i+1] += res / 10;
		}
		add();
		n /= 10;
		++adj;
	}
	memcpy(a1, a2, sizeof(int)*2600);
}

int digitsum()
{
	int i, res = 0;

	for (i = 0; i < 2600; ++i) {
		res += a1[i];
	}

	return res;
}

int main()
{
	int i, T;

	a1[0] = 1;
	sums[0] = digitsum();

	for (i = 1; i <= 1000; ++i) {
		mult(i);
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
