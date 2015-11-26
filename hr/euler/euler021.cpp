#include <cstdio>

#define NMAX 10002
#define NSIZ 100000000

typedef long long ll;

int ds[NSIZ];

int div(int N) {
  int res = 0;
  for (int i = 1; i < N; ++i) {
    res += i * (N%i == 0);
  }
  return res;
}

void dp() {
  for (int i = 1; i <= NMAX; ++i) {
    int x = div(i);
    ds[i] = x;
    /*
    if (x < NSIZ) {
      ds[i] = x;
    } else {
      //printf("%d, %d over NMAX\n", x, i);
    }
    */
  }
}

int main() {
  int T;
  dp();
  scanf("%d", &T);
  while (T--) {
    ll x = 0;
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
      int di = ds[i];
      if (ds[di] == i && di != i) {
        x += di;
      }
    }
    printf("%lld\n", x);
  }
}
