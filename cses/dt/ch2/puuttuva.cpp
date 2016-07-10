#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
int main() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int x; cin >> x; A.push_back(x);
  }
  sort(A.begin(), A.end());
  for (int i = 1; i < n; ++i) {
    if (A[i-1] != i) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
}
