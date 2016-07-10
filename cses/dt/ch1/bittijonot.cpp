#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
  int n; cin >> n;
  ll res = 1;
  while (n--) {
    res <<= 1;
    res = res % MOD;
  }
  cout << res << endl;
}