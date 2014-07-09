#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int x = 0;
  enum state {
    INIT, R
  };
  state st = INIT;
  for (size_t i = 0; i < s.size(); ++i) {
    char c = s[i];
    switch (st) {
      case INIT:
        if (c == '.') {
          ++x;
        } else if (c == 'L') {
          --n;
          n -= x;
          x = 0;
        } else if (c == 'R') {
          --n;
          st = R;
          x = 0;
        }
        break;
      case R:
        if (c == '.') {
          ++x;
        } else if (c == 'L') {
          --n;
          n += (x%2) - x;
          x = 0;
          st = INIT;
        }
        break;
    }
  }
  if (st == R) {
    n -= x;
  }
  cout << n << endl;
}
