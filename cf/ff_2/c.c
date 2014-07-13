#include <stdio.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int A[100002];
int L[100002];
int R[100002];

int main() {
	int i, n, mx = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	if (n <= 2) {
		printf("%d\n", n);
		return 0;
	}
	L[0] = 1;
	for (i = 1; i < n; ++i) {
		L[i] = A[i-1] < A[i] ? L[i-1] + 1 : 1;
		mx = MAX(mx, L[i] + 1);
	}

	R[n-1] = 1;
	for (i = n-2; i >= 0; --i) {
		R[i] = A[i] < A[i+1] ? R[i+1] + 1 : 1;
		mx = MAX(mx, R[i] + 1);
	}

	for (i = 1; i < n-1; ++i) {
		if (A[i-1] + 1 < A[i+1]) {
			mx = MAX(mx, L[i-1] + 1 + R[i+1]);
		}
	}
	printf("%d\n", MIN(mx, n));
	return 0;
}
