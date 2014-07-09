#include <iostream>

using namespace std;

int n, m;
int b[128];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i >= b[j]) { cout << b[j] << " "; break; }
    }
  }
}
