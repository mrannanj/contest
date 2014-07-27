#include <stdio.h>
#include <string.h>

char n1[100];
char n2[100];

int N;

void sum()
{
	int i, carry = 0;
	for (i = 0; i < 100; ++i) {
		int res = n1[i] + n2[i] + carry;
		n2[i] = res % 10;
		carry = res / 10;
	}
}

int main()
{
	int i, j;

	scanf("%d ", &N);

	while (N--) {
		for (i = 0; i < 50; ++i) {
			scanf(" %c ", &n1[49-i]);
			n1[49-i] = n1[49-i] - '0';
		}
		sum();
	}

	for (j = 0, i = 99; i >= 0; --i) {
		if (j == 0 && n2[i] == 0) continue;
		++j;
		printf("%d", n2[i]);
		if (j == 10) break;

	}
	printf("\n");

	return 0;
}
