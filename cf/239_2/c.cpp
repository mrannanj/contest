#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

int gcd(int a, int b) {
  return (b == 0) ? a : gcd(b, a % b);
}

int main() {
  cin >> a >> b;
  if (a > b) swap(a,b);

  for (int x = 0; x < a; ++x) {
    for (int y = 0; y < a; ++y) {
      if (x*x + y*y == a*a) {
        int div = gcd(x,y);
        int x2 = y/div;
        int y2 = -x/div;
        int bb = b*b;
        for (int c = 1;; ++c) {
          int xx2 = x2*c;
          int yy2 = y2*c;
          int l = xx2*xx2 + yy2*yy2;
          if (l == bb) {
            if (xx2 == x || yy2 == y) continue;
            cout << "YES" << endl;
            cout << 0 << " " <<  0 << endl;
            cout << x << " " <<  y << endl;
            cout << xx2 << " " <<  yy2 << endl;
            return 0;
          } else if (l > bb) {
            break;
          }
        }

      }
    }
  }
  cout << "NO" << endl;
}
