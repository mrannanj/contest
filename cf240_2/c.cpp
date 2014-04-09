#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  return (b == 0) ? a : gcd(b, a%b);
}

int main() {
  ll n, k; cin >> n >> k;
  ll cur = 0;

  if (n/2 > k) {
    cout << "-1" << endl;
    return 0;
  }

  if (n == 1) {
    if (k == 0) {
      cout << "1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }

  ll a = k - (n - 2)/2;
  cout << a << " " << a*2 << " ";

  cur += a;

  ll i = 1;
  for (; cur < k; i += 2) {
    if (i == a || i == 2*a) continue;
    if (i+1 == a || i+1 == 2*a) continue;
    cout << i << " " << i+1 << " ";
    cur += 1;
  }

  if (n%2) {
    cout << i+2;
  }
  cout << endl;
}
