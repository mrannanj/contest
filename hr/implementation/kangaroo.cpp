#include <iostream>
using namespace std;

#define MAXN (1e6)

int main() {
  long x1,x2,v1,v2;
  cin >> x1 >> v1 >> x2 >> v2;

  for (int i = 0; i < MAXN; ++i) {
    if (x1 == x2) {
      cout << "YES" << endl;
      return 0;
    }
    x1 += v1;
    x2 += v2;
  }
  cout << "NO" << endl;
}
