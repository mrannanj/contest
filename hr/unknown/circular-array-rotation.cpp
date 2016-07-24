#include <iostream>
using namespace std;

int A[100002];

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    cin >> A[(i + k) % n];
  }
  for (int i = 0; i < q; ++i) {
    int m; cin >> m;
    cout << A[m] << endl;
  }
}
