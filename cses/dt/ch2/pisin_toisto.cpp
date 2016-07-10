#include <iostream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
int main() {
  string s; cin >> s;
  int max, cur; max = cur = 1;
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) {
      ++cur;
    } else {
      cur = 1;
    }
    max = MAX(max, cur);
  }
  cout << max << endl;
}
