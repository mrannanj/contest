#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

char S[10001];
char R[10001];

void reverse() {
    int i = 0;
    int len = strlen(S);
    for (i = 0; i < len; ++i) {
        R[i] = S[len-i-1];
    }
    R[len] = '\0';
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int k = 0;
        scanf("%s", S);

        int len = strlen(S);

        reverse();
        for (k = 1; k < len; ++k) {
            if (abs(S[k-1] - S[k]) != abs(R[k-1] - R[k])) {
                printf("Not Funny\n");
                goto next;
            }
        }
        printf("Funny\n");
next:;
    }

    return 0;
}
