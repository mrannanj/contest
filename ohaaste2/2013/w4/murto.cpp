#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Murto {
  ll a;
  ll b;
};

Murto ms[1000];

ostream& operator<<(ostream& os, const Murto& m) {
  return os << m.a << "/" << m.b;
}

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

Murto operator-(const Murto& m1, const Murto& m2) {
  Murto r;
  r.a = m1.a*m2.b - m2.a*m1.b;
  r.b = m1.b * m2.b;
  ll d = gcd(abs(r.a), abs(r.b));
  r.a /= d;
  r.b /= d;
  return r;
}

ll abs(ll a) {
  return a < 0 ? -a : a;
}

Murto abs(Murto m) {
  if (m.a < 0) {
    m.a = -m.a;
  }
  if (m.b < 0) {
    m.b = -m.b;
  }
  return m;
}

bool operator<(const Murto& m1, const Murto& m2) {
  return (m1 - m2).a < 0;
}

int main() {
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    for (int i = 0; i < n; ++i) {
      char c;
      ll a, b;
      cin >> a >> c >> b;
      ms[i] = {a,b};
    }

    sort(ms, &ms[n]);
    Murto min_diff = abs(ms[0] - ms[1]);
    for (int i = 1; i < n-1; ++i) {
      Murto d = abs(ms[i] - ms[i+1]);
      if (d < min_diff) {
        min_diff = d;
      }
    }
    cout << min_diff << endl;
  }
}
