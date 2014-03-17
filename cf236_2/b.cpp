#include <iostream>

using namespace std;

int A[1024];

int main() {
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  int min_delta = 10000;
  int min_start = -1;

  for (int i = 1; i <= 1024; ++i) {
    int delta = 0;
    for (int j = 0; j < n; ++j) {
      if (A[j] != i + j*k) ++delta;
    }
    if (delta < min_delta) {
      min_delta = delta;
      min_start = i;
    }
  }
  cout << min_delta << endl;

  int target = min_start;
  for (int i = 0; i < n; ++i, target += k) {
    if (A[i] != target) {
      int d = target - A[i];
      if (d > 0) {
        cout << "+ " << i+1 << " " << d << endl;
      } else {
        cout << "- " << i+1 << " " << -d << endl;
      }
    }
  }
}
