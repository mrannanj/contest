#include <iostream>

using namespace std;

int L[128];
int B[128];

int main() {
  string s;
  cin >> s;
  for (unsigned char c : s) {
    L[c] += 1;
    B[c] = 1;
  }
  int n = 0;
  cin >> s;
  for (unsigned char c : s) {
    if (!B[c]) goto err;
    if (L[c] > 0) {
      L[c] -= 1;
      ++n;
    }
  }
  cout << n << endl;
  return 0;
err:
  cout << -1 << endl;
}
