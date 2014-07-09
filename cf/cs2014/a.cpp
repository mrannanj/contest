#include <iostream>
#include <ctype.h>

using namespace std;

int crit[8];

int main() {
  string s; cin >> s;
  crit[3] = s.size() >= 5;
  for (char c : s) {
    crit[0] |= isupper(c);
    crit[1] |= islower(c);
    crit[2] |= isdigit(c);
  }
  for (int i = 0; i < 4; ++i) {
    if (!crit[i]) {
      cout << "Too weak" << endl;
      return 0;
    }
  }
  cout << "Correct" << endl;
}
