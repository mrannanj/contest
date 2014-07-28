#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const char *tens[] = {
	"Hundred",
	"Wrong",
	"Twenty",
	"Thirty",
	"Forty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety"
};

const char *words[] = {
	"Zero",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Nineteen",
	"Twenty"
};

int stack[6];

int print_hundred(int x) {
	if (x == 0) {
		return 0;
	}

	int h = x/100;
	if (h > 0) {
		printf("%s Hundred ", words[h]);
		x = x % 100;
	}
	if (x <= 20) {
		printf("%s ", words[x]);
	} else {
		h = x/10;
		if (h > 0) {
			printf("%s ", tens[h]);
		}
		h = x % 10;
		if (h > 0) {
			printf("%s ", words[h]);
		}
	}
	return 1;
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		int64_t N;
		int p, sp = 0;
		
		scanf("%" PRId64, &N);
		if (N == 0) {
			printf("Zero");
		}
		do {
			stack[sp++] = N%1000;
			N /= 1000;
		} while (N);

		for (; sp; --sp) {
			p = print_hundred(stack[sp-1]);
			if (!p) continue;
			switch (sp) {
				case 5:
					printf("Trillion ");
					break;
				case 4:
					printf("Billion ");
					break;
				case 3:
					printf("Million ");
					break;
				case 2:
					printf("Thousand ");
					break;
				default:
					break;
			}
		}
		printf("\n");
	}

	return 0;
}
