#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
set<ll> xc;
set<ll> yc;

int main(void) {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    xc.insert(x);
    yc.insert(y);
  }

  cout << min(xc.size(), yc.size()) << endl;
}
