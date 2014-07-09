#include <iostream>

using namespace std;

int a[100][100];
int b[100][100];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (int j = 0; j < x; ++j) {
      a[i][j] = 1;
    }
  }

  for (int i = 0; i < 100; ++i) {
    int x = 0;
    for (int j = 0; j < n; ++j) x += a[j][i];
    for (int j = 0; j < x; ++j) b[i][j] = 1;
  }

  for (int i = n-1; i >= 0; --i) {
    int x = 0;
    for (int j = 0; j < 100; ++j)
      x += b[j][i];
    cout << x << " ";
  }
}
