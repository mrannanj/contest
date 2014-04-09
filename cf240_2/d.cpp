#include <iostream>

using namespace std;

typedef long long ll;

int n, k;
int dp[2048][2048];

int main() {
  cin >> n >> k;
  // dp[x][y] is the number of length y and which end in x
  for (int i = 1; i < 2048; ++i) {
    dp[1][i] = 1;
  }

  for (int y = 1; y < 2047; ++y) {
    for (int x = 1; x < 2048; ++x) {
      for (int z = x; z < 2048; z += x) {
        dp[y+1][z] = (dp[y+1][z] + dp[y][x]) % 1000000007;
      }
    }
  }

  ll res = 0;
  for (int x = 1; x <= n; ++x) {
    res = (dp[k][x] + res) % 1000000007;
  }

  cout << res << endl;
}
