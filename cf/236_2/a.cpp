#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll k, a, b, v; cin >> k >> a >> b >> v;

  ll i = 0;
  ll cap = 0;
  for (; cap < a; ++i) {
    if (k <= b) { cap += k*v; b -= (k-1); }
    else if (b > 0) { cap += (b+1)*v; b = 0; }
    else { cap += v; }
  }
  cout << i << endl;
}
