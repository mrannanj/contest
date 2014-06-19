#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
int res[2002];

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      if (c == 'U') {
        res[j] += !(i & 1);
      } else if (c == 'L') {
        int pos = j - i;
        if (pos >= 0) res[pos] += 1;
      } else if (c == 'R') {
        int pos = i + j;
        if (pos < 2002) res[pos] += 1;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
