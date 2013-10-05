#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll min(ll a, ll b) {
  return a < b ? a : b;
}

ll max(ll a, ll b) {
  return a > b ? a : b;
}

int main() {
  ll n; cin >> n;
  vector<ll> t;
  while (n--) {
    ll s; cin >> s;
    t.push_back(s);
  }
  sort(t.begin(), t.end());
  ll md = -1;
  for (size_t i = 0; i < t.size(); ++i) {
    ll d = t[t.size() - i - 1] + i + 1;
    md = max(d, md);
  }
  cout << md+1 << endl;
}

