#include <stdio.h>
#include <string.h>

const char *p[] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char s[100];

int main() {
	int i, j, l;
	scanf("%d", &l);
	scanf("%s", s);

	for (i = 0; i < 8; ++i) {
		int len = strlen(p[i]);
		if (len != l) continue;
		for (j = 0; j < l; ++j) {
			if (s[j] == '.') continue;
			if (s[j] == p[i][j]) continue;
			goto no;
		}
		printf("%s\n", p[i]);
		return 0;
no: ;
	}

	return 0;
}
