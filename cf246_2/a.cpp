#include <iostream>

using namespace std;

int n, k;
int v;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int y; cin >> y;
    v += (y + k <= 5);
  }
  cout << v/3 << '\n';
}
