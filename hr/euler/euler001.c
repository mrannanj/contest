#include <stdio.h>

int T;
int N;

long long ssd(int d, long long m) {
	long long n = (m/d);
	long long ret = d * n * (n+1)/2;
	return ret;
}

long long getsum(long long n) {
	return (ssd(3,n) + ssd(5,n) - ssd(15,n));
}

int main() {
	scanf("%d", &T);
	while(T--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", getsum(n-1));
	}
	return 0;
}
