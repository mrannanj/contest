#include <iostream>

using namespace std;

char c;
int run;

int main() {
  int n = 0;
  string s; cin >> s;

  c = s[0];
  run = 1;
  for (size_t i = 1; i < s.length(); ++i) {
    if (c == s[i]) {
      ++run;
    } else {
      n += (run%2 == 0);
      c = s[i];
      run = 1;
    }
  }
  n += (run%2 == 0);
  cout << n << endl;
}
