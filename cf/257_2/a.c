#include <stdio.h>

int n, m;
int A[102];

int main() {
	int i, last = -1;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}
	while (1) {
		int none = 1;
		for (i = 1; i <= n; ++i) {
			if (A[i] > 0) {
				A[i] -= m;
				last = i;
				none = 0;
			}
		}
		if (none) {
			printf("%d\n", last);
			return 0;
		}

	}
	return 0;
}
