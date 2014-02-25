#include <iostream>

using namespace std;

int main() {
  string s; cin >> s;

  size_t max_count = 0;

  for (char c = 'A'; c <= 'Z'; ++c) {
    size_t count = 0;
    int last = -1;
    for (size_t i = 0; i < s.length(); i += 2) {
      if (s[i] == c) {
        count = 1;
        last = i;
        break;
      }
    }
    if (last != -1) {
      for (size_t i = last+1; i < s.size(); ++i) {
        if (s[i] == c and (last - i) % 2) {
          ++count;
          last = i;
        }
      }
    }

    max_count = max(count, max_count);
    count = 0;
    last = -1;

    for (size_t i = 1; i < s.length(); i += 2) {
      if (s[i] == c) {
        count = 1;
        last = i;
        break;
      }
    }
    if (last != -1) {
      for (size_t i = last+1; i < s.size(); ++i) {
        if (s[i] == c and (last - i) % 2) {
          ++count;
          last = i;
        }
      }
    }
    max_count = max(count, max_count);
  }
  cout << max_count << endl;
}
