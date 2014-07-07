#include <stdio.h>

int n, m;
char b[103][103];

int BNEAR = 1;
int WNEAR = 2;

int nr(char c) {
	switch (c) {
		case 'B': return BNEAR;
		case 'W': return WNEAR;
		default: return 0;
	}
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf(" %[.-]", &b[i][1]);
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			int near, wok, bok;
			if (b[i][j] != '.') continue;
			near = nr(b[i-1][j]) | nr(b[i+1][j]) |
				nr(b[i][j-1]) | nr(b[i][j+1]);
			bok = !(near & BNEAR);
			wok = !(near & WNEAR);
			if (bok & wok) {
				b[i][j] = (i&1)&(j&1) || !(i&1)&!(j&1) ?
					'B' : 'W';
			} else if (bok) {
				b[i][j] = 'B';
			} else if (wok) {
				b[i][j] = 'W';
			}
		}
	}

	for (i = 1; i <= n; ++i) {
		printf("%s\n", &b[i][1]);
	}
	return 0;
}
