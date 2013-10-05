#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;
typedef long long ll;

ll rotate(ll x) {
  ll r = x;
  ll n = 1;
  while (x >= 10) {
    x /= 10;
    n *= 10;
  }
  return ((r - n*x)) + x;
}

ll expand(ll x) {
  ll r = x;
  ll n = 1;
  while (r >= 10) {
    r /= 10;
    n *= 10;
  }
  return x + 10 * n * x;
}

ll ncat(ll l, ll r) {
  ll tmp = r;
  ll n = 1;
  while (tmp > 0) {
    tmp /= 10;
    n *= 10;
  }
  return l * n + r;
}

set<ll> found;
double x;

ll mul(ll n) {
  double res = x*n;
  double fres = floor(res);
  if ((abs(res - fres)) >= 0.0001) {
    return -1.0f;
  }
  return (ll)fres;
}

int test(ll n) {
  if (n >= 100000000) return 0;
  ll rot = rotate(n);
  ll ml = mul(n);
  cout << n << ", " << rot << ", " << ml << endl;
  return mul(n) == rot;
}

int main() {
  cin >> x;
  for (ll i = 1; i < 100; ++i) {
    if (test(i)) {
      found.insert(i);
    }
  }

  for (auto it = found.begin(); it != found.end(); ++it) {
    ll k = *it;
    //cout << k << ", " << rotate(k) << ", " << mul(k) << endl;
    cout << k << endl;
  }

  if (found.size() == 0) {
    cout << "No solution" << endl;
  }
}
