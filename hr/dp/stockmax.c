#include <stdio.h>
#include <limits.h>

int T;
int S[(int)(1e5)+1];

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	int i;
	scanf("%d", &T);
	while(T--) {
		int sp = INT_MIN;
		long long sum = 0;
		int n;
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &S[i]);
		}
		for (i = n-1; i >= 0; --i) {
			if (S[i] > sp) {
				sp = S[i];
			} else if (S[i] < sp) {
				sum += sp - S[i];
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
