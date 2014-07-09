#include <iostream>

using namespace std;

typedef unsigned long long ul;

int main() {
  ul n, a, b;
  cin >> n >> a >> b;
  for (ul i = 1; i <= n; ++i) {
    ul x; cin >> x;
    cout << ((x*a) % b)/a << " ";
  }
}
