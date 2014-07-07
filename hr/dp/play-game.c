#include <stdio.h>
#include <string.h>

int T;
int S[(int)(1e5)+4];
long long A[(int)(1e5)+4];
long long B[(int)(1e5)+4];

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		int i, j, n;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(S, 0, sizeof(S));
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &S[i]);
		}
		for (i = n-1; i >= 0; --i) {
			long long a[] = {
				S[i] + B[i+1],
				S[i] + S[i+1] + B[i+2],
				S[i] + S[i+1] + S[i+2] + B[i+3]
			};
			if (a[0] > a[1] && a[0] > a[2]) {
				j = 0;
			} else if (a[1] > a[2]) {
				j = 1;
			} else {
				j = 2;
			}
			A[i] = a[j];
			B[i] = A[i+j+1];
		}
		printf("%lld\n", A[0]);
	}
}
