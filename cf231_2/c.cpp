#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int d[3];
size_t sum[1000];

int main() {
  size_t n, m; cin >> n >> m;
  size_t total = n*m;
  for (size_t i = 0; i < total; ++i) {
    string s; cin >> s;
    if (s == "11") d[2]++;
    else if (s == "01" or s == "10") d[1]++;
    else d[0]++;
  }

  for (size_t i = 0; i < n; ++i) {
    size_t min_sum = INT_MAX;
    for (size_t j = 0; j < m; ++j) {
      min_sum = min(min_sum, sum[j]);
    }

    for (size_t j = 0; j < m; ++j) {
      if (d[2] > 0) {
        cout << "11 ";
        sum[j] += 2;
        d[2]--;
      } else if (d[1] > 0 and sum[j] == min_sum) {
        cout << (i%2 == 0 ? "01 " : "10 ");
        sum[j] += 1;
        d[1]--;
      } else if (d[0] > 0) {
        cout << "00 ";
        d[0]--;
      } else if (d[1] > 0) {
        cout << (i%2 == 0 ? "01 " : "10 ");
        sum[j] += 1;
        d[1]--;
      }
    }
    cout << endl;
  }
}
