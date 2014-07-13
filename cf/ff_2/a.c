#include <stdio.h>

int p, n;
int t[300];

int main() {
	int i = 0;
	scanf("%d %d", &p, &n);
	for (i = 1; i <= n; ++i) {
		int x, h;
		scanf("%d", &x);
		h = x % p;
		if (!t[h]) {
			t[h] = 1;
		} else {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
	return 0;
}
