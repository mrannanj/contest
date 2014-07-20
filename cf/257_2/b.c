#include <stdio.h>

int F[10];

int main() {
	int i, x, y, n, res;
	scanf("%d %d", &x, &y);
	scanf("%d", &n);
	F[0] = x;
	F[1] = y;
	for (i = 1; i <= 6; ++i) {
		F[i+1] = (F[i] - F[i-1]) % 1000000007;
	}
	res = (F[(n+5)%6] + 1000000007) % 1000000007;

	printf("%d\n", res);

	return 0;
}
