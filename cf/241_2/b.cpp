#include <iostream>

using namespace std;

int m, n;

typedef long long ll;

ll dp[50002][8];

int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      ll t; cin >> t;
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + t;
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << dp[i][n] << " ";
  }
  cout << endl;
}
