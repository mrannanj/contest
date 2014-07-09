#include <iostream>

using namespace std;

int A[4096];

int main() {
  int x, k; cin >> x >> k;
  A[x] = 2;
  for (int i = 0; i < k; ++i) {
    int div, n2, n1;
    cin >> div >> n2;
    if (div == 1) {
      cin >> n1;
      A[n1] = 1;
    }
    A[n2] = 2;
  }

  int max2 = 0;
  int min2 = 0;
  for (int i = 1; i < x; ++i) {
    if (A[i] == 0) {
      max2 += 1;
      min2 += 1;
      A[i] = 2;
      if (A[i+1] == 0) {
        max2 += 1;
        A[i+1] = 1;
      }
    }
  }
  cout << min2 << " " << max2 << endl;
}
