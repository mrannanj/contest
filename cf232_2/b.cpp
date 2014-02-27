#include <iostream>

using namespace std;

typedef long long ll;

ll t;

int main() {
  cin >> t;
  while (t--) {
    ll n, l, r; cin >> n >> l >> r;
    while (l <= r) {
      n -= (n/r)*r;
      --r;
    }
    if (n == 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
