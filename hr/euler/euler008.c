#include <stdio.h>
#include <string.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

char s[1002];

int cton(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}
}

int main() {
	int T;
	
	scanf("%d", &T);
	while (T--) {
		int K, N, i, len, prod, res = 0;
		scanf("%d %d", &N, &K);
		scanf(" %s ", s);
		len = strlen(s);
		for (i = 0; i < len-K; ++i) {
			prod = 1;
			switch (K) {
				default: prod = 0;
				case 7: prod *= cton(s[i+6]);
				case 6: prod *= cton(s[i+5]);
				case 5: prod *= cton(s[i+4]);
				case 4: prod *= cton(s[i+3]);
				case 3: prod *= cton(s[i+2]);
				case 2: prod *= cton(s[i+1]);
				case 1: prod *= cton(s[i]);
			}
			res = MAX(res, prod);
		}
		printf("%d\n", res);
	}

	return 0;
}
