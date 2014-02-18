#include <iostream>
#include <map>

using namespace std;

int main() {
  string s; cin >> s;
  string m = "nineteen";
  map<char, int> o;

  for (auto it = s.begin(); it != s.end(); ++it) {
    o[*it] += 1;
  }
  size_t n = 0;

  while (true) {
    if (n == 0) {
      o['n'] -= 3;
    } else {
      o['n'] -= 2;
    }
    o['i'] -= 1;
    o['e'] -= 3;
    o['t'] -= 1;
    if (o['n'] < 0) break;
    if (o['i'] < 0) break;
    if (o['e'] < 0) break;
    if (o['t'] < 0) break;
    ++n;
  }
  cout << n << endl;
}
