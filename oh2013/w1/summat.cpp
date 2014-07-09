#include <iostream>

using namespace std;

void summa() {
  int x;
  cin >> x;
  int n = 0;
  for (int a = 0; a <= 32; ++a) {
    for (int b = 0; b <= 32; ++b) {
      for (int c = 0; c <= 32; ++c) {
        for (int d = 0; d <= 32; ++d) {
          n += (a*a + b*b + c*c + d*d == x);
        }
      }
    }
  }
  cout << n << endl;
}

int main() {
  int n; cin >> n;
  while (n--) summa();
}

