#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll row[6002];
ll rowt[6002];

ll col[6002];
ll colt[6002];

ll n, p;

int main() {
  cin >> n >> p;
  for (ll i = 1; i <= p; ++i) {
    ll num, clr;
    char s[4]; cin >> s >> num >> clr;
    if (s[0] == 'C') {
      col[num] = clr;
      colt[num] = i;
    } else {
      row[num] = clr;
      rowt[num] = i;
    }
  }
  ll sum = 0;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      sum += colt[i] > rowt[j] ? col[i] : row[j];
    }
  }
  cout << sum << endl;
}
