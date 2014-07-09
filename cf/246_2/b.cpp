#include <iostream>

using namespace std;

int n;
int x[100002];
int y[100002];

int xn[100002];
int yn[100002];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    xn[x[i]] += 1;
    yn[y[i]] += 1;
  }

  for (int i = 0; i < n; ++i) {
    int inv = xn[y[i]];
    int h = n - 1 + inv;
    int a = n - 1 - inv;
    cout << h << ' ' << a << '\n';
  }
}

