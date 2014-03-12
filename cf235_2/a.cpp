#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int n, x; cin >> n >> x;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    int c; cin >> c;
    sum += c;
  }
  if (sum < 0) sum = -sum;
  ll res = sum/x + (sum % x != 0);
  cout << res << endl;
}
