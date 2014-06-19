#include <iostream>
#include <algorithm>

using namespace std;

int n, x;

struct candy {
  int f;
  int h;
  int m;
};

candy c[2][2002];
int nc[2];

bool comp(const candy& a, const candy& b) {
  return a.m > b.m;
}

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int t, h, m; cin >> t >> h >> m;
    c[t][nc[t]].f = 1;
    c[t][nc[t]].h = h;
    c[t][nc[t]].m = m;
    nc[t]++;
  }
  sort(c[0], &c[0][nc[0]], comp);
  sort(c[1], &c[1][nc[1]], comp);

  int turn = 0;
  int sum1 = 0;
  int x1 = x;
  while (true) {
    for (int i = 0; i < nc[turn]; ++i) {
      if (c[turn][i].f && c[turn][i].h <= x1) {
        c[turn][i].f = 0;
        x1 += c[turn][i].m;
        sum1++;
        goto next1;
      }
    }
    break;
next1:
    turn = !turn;
  }

  for (int i = 0; i < n; ++i) {
    c[0][i].f = 1;
    c[1][i].f = 1;
  }

  turn = 1;
  int sum2 = 0;
  x1 = x;
  while (true) {
    for (int i = 0; i < nc[turn]; ++i) {
      if (c[turn][i].f && c[turn][i].h <= x1) {
        c[turn][i].f = 0;
        x1 += c[turn][i].m;
        sum2++;
        goto next2;
      }
    }
    break;
next2:
    turn = !turn;
  }
  cout << max(sum1,sum2) << endl;
}
