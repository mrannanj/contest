#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;

char sok[100][100];
int dist[100][100];
int n, m, k;

struct Point {
  int x, y;
};

Point neighbour[4];

int ok(const Point& p) {
  return p.x >= 0 && p.x < k && p.y >= 0 && p.y < m && sok[p.y][p.x] != '#';
}

void neighbours(const Point& v) {
  neighbour[0] = { v.x-1, v.y };
  neighbour[1] = { v.x+1, v.y };
  neighbour[2] = { v.x, v.y-1 };
  neighbour[3] = { v.x, v.y+1 };
}

void bfs() {
  deque<Point> Q;
  for (int y = 0; y < m; ++y)
    for (int x = 0; x < k; ++x)
      if (sok[y][x] == 'A') {
        Q.push_back({x,y});
        dist[y][x] = 0;
        break;
      }
  while (!Q.empty()) {
    Point p = Q.front();
    Q.pop_front();
    neighbours(p);
    int d = dist[p.y][p.x];
    sok[p.y][p.x] = '#';
    for (int i = 0; i < 4; ++i) {
      Point u = neighbour[i];
      if (ok(u)) {
        dist[u.y][u.x] = d + 1;
        Q.push_back({u.x, u.y});
        if (sok[u.y][u.x] == 'B') {
          if (d % 2 == 0)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
          goto out;
        }
      }
    }
  }
  cout << "NO" << endl;
out:;
}

int main() {
  cin >> n;
  while (n--) {
    cin >> m >> k;
    for (int i = 0; i < m; ++i)
      cin >> sok[i];
    bfs();
  }
}

