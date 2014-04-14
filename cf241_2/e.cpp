#include <cstring>
#include <set>
#include <utility>
#include <cstdio>

using namespace std;

int n, m;
int g[512][512];
int xs[125002];
int ys[125002];
int ls[125002];
int ds[512][512];
int rs[512][512];

constexpr int INF = 1e9+1;

void print_ds() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", ds[i][j]);
    }
    printf("\n");
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 512; ++i) {
    for (int j = 0; j < 512; ++j) {
      g[i][j] = INF;
    }
  }

  for (int i = 0; i < 512; ++i) {
    g[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int x, y, l;
    scanf("%d %d %d", &x, &y, &l);
    xs[i] = x;
    ys[i] = y;
    ls[i] = l;
    g[x][y] = g[y][x] = l;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  for (int e = 0; e < m; ++e) {
    for (int v = 1; v <= n; ++v) {
      ds[xs[e]][v] += ls[e] + g[ys[e]][v] == g[xs[e]][v];
      ds[ys[e]][v] += ls[e] + g[xs[e]][v] == g[ys[e]][v];
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        rs[i][j] += (g[i][j] == g[i][k] + g[k][j]) * ds[k][j];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      printf("%d ", rs[i][j]);
    }
  }
}
