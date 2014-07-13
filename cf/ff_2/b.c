#include <stdio.h>
#include <stdlib.h>

unsigned char s[3002];
int k;
int v[256];

#define MAX(a, b) (a>b?a:b)

int main() {
	int len, c, mx = 0, i, res = 0;
	scanf(" %s ", s);
	scanf(" %d ", &k);
	for (c = 'a'; c <= 'z'; ++c) {
		scanf(" %d ", &v[c]);
		mx = MAX(v[c], mx);
	}
	for (i = 0; s[i] != '\0'; ++i) {
		res += v[s[i]] * (i+1);
	}
	for (i += 1; k--; ++i) {
		res += mx * i;
	}
	printf("%d\n", res);
	return 0;
}
