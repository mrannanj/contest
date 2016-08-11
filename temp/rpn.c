#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int S[100];
int sp;

int pop() {
	if (sp < 0) {
		fprintf(stderr, "sp < 0\n");
		exit(1);
	}
	return S[--sp];
}

void push(int x) {
	if (sp >= 100) {
		fprintf(stderr, "sp >= 0\n");
		exit(1);
	}
	S[sp++] = x;
}

static
int calculate(const char* s, const char **error_r)
{
	for (int i = 0; s[i] != '\0'; ++i) {
		if (isdigit(s[i])) {
			int x = atoi(&s[i]);
			push(x);
			while(isdigit(s[i])) ++i;
			--i;
		} else if (s[i] == '-') {
			int a = pop();
			int b = pop();
			push(a-b);
		} else if (s[i] == '+') {
			int a = pop();
			int b = pop();
			push(a+b);
		} else if (s[i] == '*') {
			int a = pop();
			int b = pop();
			push(a*b);
		} else if (s[i] == '/') {
			int a = pop();
			int b = pop();
			if (a == 0) {
				*error_r = "divide by zero";
				return -1;
			}
			push(a/b);
		} else if (s[i] == '%') {
			int a = pop();
			int b = pop();
			if (a == 0) {
				*error_r = "mod by zero";
				return -1;
			}
			push(b%a);
		} else if (!isspace(s[i])) {
			*error_r = "invalid character in input";
			return -1;
		}
	}
	if (sp != 1) {
		*error_r = "sp != 1";
		return -1;
	}

	return S[0];
}

char buf[100];
int main(void) {
	while (1) {
		sp = 0;
		const char *err = NULL;
		scanf("%[^\n]", buf);
		char c; scanf("%c", &c);
		if (buf[0] == 'q')
			return 0;
		int x = calculate(buf, &err);
		if (err != NULL) {
			fprintf(stderr, "error: %s\n", err);
		} else {
			printf("%d\n", x);
		}
	}
	return 0;
}
