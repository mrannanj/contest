#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int n, s;

struct P {
  double d;
  int s;
};

vector<P> ps(1002);

bool comp(P a, P b) {
  return a.d < b.d;
}

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    int x, y, k; cin >> x >> y >> k;
    ps[i].s = k;
    ps[i].d = sqrt(x*x + y*y);
  }
  sort(ps.begin(), ps.begin()+n, comp);
  for (int i = 0; i < n; ++i) {
    s += ps[i].s;
    if (s >= 1000000) {
      cout.precision(10);
      cout << ps[i].d << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
