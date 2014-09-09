#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
using namespace std;
typedef const int ci;
typedef const unsigned cu;

int n;
int m;

char lab[1000][1000];
int c[1000][1000];
int v[1000][1000];
struct Point {
  int x;
  int y;
};

#define INF 100000

int ok(Point p) {
  if (p.x < 0) return 0;
  if (p.x >= m) return 0;
  if (p.y < 0) return 0;
  if (p.y >= n) return 0;
  return (lab[p.y][p.x] == '.' && v[p.y][p.x] == 0);
}

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int bfs() {
  deque<Point> q;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c[i][j] = INF;
    }
  }
  int y = 0;
  for (int x = 0; x < m; ++x) {
    if (lab[y][x] == '.') {
      c[y][x] = 0;
      q.push_back({x,y});
      v[y][x] = 1;
    }
  }
  y = n-1;
  for (int x = 0; x < m; ++x) {
    if (lab[y][x] == '.') {
      c[y][x] = 0;
      q.push_back({x,y});
      v[y][x] = 1;
    }
  }
  int x = 0;
  for (int y = 0; y < n; ++y) {
    if (lab[y][x] == '.') {
      c[y][x] = 0;
      q.push_back({x,y});
      v[y][x] = 1;
    }
  }
  x = m-1;
  for (int y = 0; y < n; ++y) {
    if (lab[y][x] == '.') {
      c[y][x] = 0;
      q.push_back({x,y});
      v[y][x] = 1;
    }
  }

  int mx = 0;
  while (!q.empty()) {
    Point p = q.front();
    q.pop_front();
    int d = c[p.y][p.x];
    Point u = { p.x-1, p.y };
    if (ok(u)) {
      q.push_back(u);
      c[u.y][u.x] = d + 1;
      v[u.y][u.x] = 1;
    }
    u = { p.x+1, p.y };
    if (ok(u)) {
      q.push_back(u);
      c[u.y][u.x] = d + 1;
      v[u.y][u.x] = 1;
    }
    u = { p.x, p.y-1 };
    if (ok(u)) {
      q.push_back(u);
      c[u.y][u.x] = d + 1;
      v[u.y][u.x] = 1;
    }
    u = { p.x, p.y+1 };
    if (ok(u)) {
      q.push_back(u);
      c[u.y][u.x] = d + 1;
      v[u.y][u.x] = 1;
    }
    c[p.y][p.x] = d;
    mx = max(d+1, mx);
  }
  return mx;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> lab[i][j];
    }
  }
  cout << bfs()-1 << endl;
}

