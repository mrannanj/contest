#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll ds[10000];

ll min(ll a, ll b) {
  return a < b ? a : b;
}

int main() {
  for (int i = 1; i < 10000; ++i) {
    ds[i] = ds[i-1] + 1;
    if (i >= 7)
      ds[i] = min(ds[i], ds[i-7] + 1);
    if (i >= 5)
      ds[i] = min(ds[i], ds[i-5] + 1);
  }
  for (int i = 0; i < 100; ++i) {
    cout << i << ", " << ds[i] << endl;
  }
  /*
  ll n; cin >> n;
  while (n--) {
    ll x; cin >> x;
    ll d = x/10000;
    x %= 70;
    d += ds[x];
    cout << d << endl;
  }
  */
}

