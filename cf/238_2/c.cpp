#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int a[1000][1000];
int n;

void flip_row(int r) {
  r=r-1;
  for (int i = 0; i < n; ++i) {
    a[r][i] ^= 1;
  }
}

void flip_col(int c) {
  c=c-1;
  for (int i = 0; i < n; ++i) {
    a[i][c] ^= 1;
  }
}

void um() {
  int r = 0;
  for (int i = 0; i < n; ++i) {
    int t = 0;
    for (int j = 0; j < n; ++j) {
      t += (a[i][j] | a[j][i]) & 1;
    }
    r += t & 1;
  }
  r = r & 1;
  cout << r;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  ll q; cin >> q;
  while (q--) {
    int x; scanf("%d", &x);
    int p;
    switch (x) {
      case 1:
        cin >> p;
        flip_row(p);
        break;
      case 2:
        cin >> p;
        flip_col(p);
        break;
      case 3:
        um();
        break;
    }
  }
}
