#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

struct edge {
  int from;
  int to;
  int cost;
};

bool ecomp(const edge& a, const edge& b) {
  return a.cost < b.cost;
}

int n, m, k, w;
char data[1001][11][11];
int th;

int g[1001][1001];
int gn[1001];

int pr[1001];
int dsu[1001];
edge es[501501];
int ne;

void dfs(int x, int source) {
  if (pr[x]) return;
  pr[x] = 1;
  cout << x << ' ' << source << '\n';
  for (int i = 0; i < gn[x]; ++i) {
    dfs(g[x][i], x);
  }
}

int dsu_find(int x) {
  if (dsu[x] != x) {
    return dsu_find(dsu[x]);
  }
  return x;
}

void dsu_union(int x, int y) {
  int xroot = dsu_find(x);
  int yroot = dsu_find(y);
  dsu[yroot] = xroot;
}

int main() {
  cin >> n >> m >> k >> w;
  th = n*m;
  for (int i = 1; i <= k; ++i) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        cin >> data[i][y][x];
      }
    }
  }

  for (int i = 1; i <= k; ++i) {
    for (int j = i+1; j <= k; ++j) {
      int c = 0;
      for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
          c += data[i][y][x] != data[j][y][x];
        }
      }
      ++ne;
      es[ne].to = j;
      es[ne].from = i;
      es[ne].cost = c*w;
    }
  }

  sort(&es[1], &es[ne+1], ecomp);

  for (int i = 1; i <= k; ++i) {
    dsu[i] = i;
  }

  ll total_cost = 0;
  for (int i = 1; i <= ne; ++i) {
    const edge& e = es[i];
    if (e.cost > th) break;
    if (dsu_find(e.from) == dsu_find(e.to)) continue;

    total_cost += e.cost;
    dsu_union(e.from, e.to);

    g[e.from][gn[e.from]] = e.to;
    g[e.to][gn[e.to]] = e.from;
    gn[e.to]++;
    gn[e.from]++;
  }

  int whole = 0;
  for (int i = 1; i <= k; ++i) {
    whole += dsu[i] == i;
  }
  total_cost += whole * th;

  cout << total_cost << '\n';
  for (int i = 1; i <= k; ++i) {
    dfs(i, 0);
  }
}
