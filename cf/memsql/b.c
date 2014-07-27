#include <stdio.h>
#include <math.h>

int n, m;

int px[4];
int py[4];

int maxpath[4];
double maxlen;

double dd[4][4];

int main() {
	int i, j, k, l;

	scanf("%d %d", &n, &m);

	if (n == 0) {
		printf("%d %d\n", 0, 1);
		printf("%d %d\n", 0, m);
		printf("%d %d\n", 0, 0);
		printf("%d %d\n", 0, m-1);
		return 0;
	} else if (m == 0) {
		printf("%d %d\n", 1, 0);
		printf("%d %d\n", n, 0);
		printf("%d %d\n", 0, 0);
		printf("%d %d\n", n-1, 0);
		return 0;
	}

	px[0] = py[0] = 0;
	px[1] = n; py[1] = 0;
	px[2] = 0; py[2] = m;
	px[3] = n; py[3] = m;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			int xd = px[i] - px[j];
			int yd = py[i] - py[j];
			dd[i][j] = sqrt(xd * xd + yd * yd);
		}
	}

	for (i = 0; i < 4; ++i) {
	for (j = 0; j < 4; ++j) {
		if (j == i) continue;
	for (k = 0; k < 4; ++k) {
		if (k == i || k == j) continue;
	for (l = 0; l < 4; ++l) {
		double len;
		if (l == i || l == j || l == k) continue;
		len = dd[i][j] + dd[j][k] + dd[k][l] + dd[l][i];
		if (len > maxlen) {
			maxlen = len;
			maxpath[0] = i;
			maxpath[1] = j;
			maxpath[2] = k;
			maxpath[3] = l;
		}
	}
	}
	}
	}

	for (i = 0; i < 4; ++i) {
		printf("%d %d\n", px[maxpath[i]], py[maxpath[i]]);
	}

	return 0;
}
