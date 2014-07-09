#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  string s;

  ll n, m; cin >> n >> m; // n 0's, m 1's
  ll min_n = m-1;
  ll min_m = n-1;
  ll max_m = 2*n + 2;
  int st = 0;
  /* 0 - can be either
   * 1 - next has to be 0
   * 2 - next has to be 1
   * 3 - leading 1, one 1 possible
   */
  while (n > 0 or m > 0) {
    if (st == 0) {
      if (n > m) {
        s.push_back('0');
        n--;
        st = 2;
      } else {
        s.push_back('1');
        m--;
        st = 3;
      }
    } else if (st == 1) {
      if (n <= 0) goto err;
      --n;
      s.push_back('0');
      st = 2;
    } else if (st == 2) {
      if (m <= 0) goto err;
      --m;
      s.push_back('1');
      st = 3;
    } else if (st == 3) {
      if (m > 0 && m > n) {
        --m;
        s.push_back('1');
        st = 1;
      } else if (n <= 0) {
        goto err;
      } else {
        --n;
        s.push_back('0');
        st = 2;
      }
    }
  }
  cout << s << endl;
  return 0;
err: cout << "-1" << endl;
}
