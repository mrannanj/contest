#include <stdio.h>

int main() {
	int a1, a2, a3, a;
	int b1, b2, b3, b;
	int n;
	scanf("%d %d %d", &a1, &a2, &a3);
	scanf("%d %d %d", &b1, &b2, &b3);
	scanf("%d", &n);

	a = a1 + a2 + a3;
	a = a/5 + (a%5!=0);
	b = b1 + b2 + b3;
	b = b/10 + (b%10!=0);
	if (n - a - b >= 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
