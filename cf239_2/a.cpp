#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int k[128];

typedef long long ll;

ll min_t;

int main() {
  min_t = INT_MAX;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }

  for (int i = 0; i < n; ++i) {
    ll t = k[i] * 15;
    for (int j = 0; j < k[i]; ++j) {
      int it; cin >> it;
      t += it * 5;
    }
    min_t = min(min_t, t);
  }
  cout << min_t << endl;
}
