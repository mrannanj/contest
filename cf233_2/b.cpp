#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  ll b = 0;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    if (c == 'B') b += 1llu << i;
  }
  cout << b << endl;
}
