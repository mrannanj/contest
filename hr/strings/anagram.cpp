#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
      cout << "-1" << endl;
      continue;
    }
    int count[256];
    memset(count, 0, sizeof(count));
    for (size_t i = 0; i < s.size()/2; ++i) {
      count[(unsigned char)s[i]] += 1;
    }
    for (size_t i = s.size()/2; i < s.size(); ++i) {
      count[(unsigned char)s[i]] -= 1;
    }
    int n = 0;
    for (unsigned char c = 'a'; c <= 'z'; ++c) {
      n += count[c] > 0 ? count[c] : 0;
    }
    cout << n << endl;
  }
}
