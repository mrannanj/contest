#include <stdio.h>

int l, r;

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	int a, b;
	int m = 0;
	scanf("%d %d", &l, &r);
	for (a = l; a < r; ++a) {
		for (b = r; a < b; --b) {
			m = max(m, a^b);
		}
	}
	printf("%d\n", m);
	return 0;
}
