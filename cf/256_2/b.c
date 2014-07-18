#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s1[102];
char s2[102];

int s1len;
int s2len;

int f1[260];
int f2[260];

int m1[128];

int main() {
	int i, j, last = 0;
	int aut = 0;
	int arr = 0;

	scanf("%s", s1);
	scanf("%s", s2);
	s1len = strlen(s1);
	s2len = strlen(s2);

	for (i = 0; i < s2len; ++i) {
		int gah = i > 0 ? m1[i-1] : 0;
		for (j = gah; j < s1len; ++j) {
			if (s2[i] == s1[j]) {
				m1[i] = j;
				s1[j] = '\0';
				goto next;
			}
		}
		for (j = 0; j < gah; ++j) {
			if (s2[i] == s1[j]) {
				m1[i] = j;
				s1[j] = '\0';
				goto next;
			}
		}
		printf("need tree\n");
		return 0;
next:;
	}

	aut = s2len != s1len;
	last = m1[0];
	for (i = 1; i < s2len; ++i) {
		if (last >= m1[i]) {
			arr = 1;
			break;
		}
		last = m1[i];
	}

	if (aut && arr) {
		printf("both\n");
	} else if (aut) {
		printf("automaton\n");
	} else if (arr) {
		printf("array\n");
	}

	return 0;
}
