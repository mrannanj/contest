#include <iostream>

using namespace std;

int main() {
  string line;
  string delim = "+=";
  getline(cin, line);
  string a, b, c;
  for (size_t i = 0; i < line.length(); ++i) {
    if (line[i] == '+') {
      line[i] = '\0';
      a = line.substr(0, i);
    }
    if (line[i] == '=') {
      line[i] = '\0';
      b = line.substr(a.length()+1, i-(a.length()+1));
      c = line.substr(b.length()+1 + a.length()+1, i-(b.length()+1+a.length()+1));
    }
  }

  size_t ab_len = a.length() + b.length();
  if (ab_len + 2 == c.length()) { // move one from c to ab
    c.pop_back();
    a.push_back('|');
  } else if (ab_len - 2 == c.length()) { // move one from ab to c
    if (a.length() >= 2) {
      a.pop_back();
    } else {
      b.pop_back();
    }
    c.push_back('|');
  } else if (ab_len == c.length()) {
  } else {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << a << "+" << b << "=" << c << endl;
}
