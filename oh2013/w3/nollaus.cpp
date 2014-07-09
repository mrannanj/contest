#include <iostream>
#include <cstring>
using namespace std;
typedef const int ci;
typedef const unsigned cu;

ci N = 1000000;
int memo[N];

int max(int a, int b) {
  return a > b ? a : b;
}

int max_digit(int d) {
  int m = 0;
  while (d > 0) {
    m = max(m, d%10);
    d = d/10;
  }
  return m;
}

void build_memo() {
  memo[0] = 0;
  for (int i = 1; i < N; ++i) {
    memo[i] = 1 + memo[i - max_digit(i)];
  }
}

int main() {
  build_memo();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << memo[n] << endl;
  }
}

