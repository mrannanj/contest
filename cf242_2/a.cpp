#include <iostream>

using namespace std;

int n;
char h[202];

int main() {
  cin >> n;
  cin >> h;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += h[i] == 'X';
  }
  int t = n/2;
  if (s == t) {
    cout << "0\n";
  } else if (s < t) {
    cout << t-s << "\n";
    for (int i = 0; i < n; ++i) {
      if (h[i] == 'x') {
        h[i] = 'X';
        if (++s == t) break;
      }
    }
  } else {
    cout << s-t << "\n";
    for (int i = 0; i < n; ++i) {
      if (h[i] == 'X') {
        h[i] = 'x';
        if (--s == t) break;
      }
    }
  }
  cout << h << '\n';
}
