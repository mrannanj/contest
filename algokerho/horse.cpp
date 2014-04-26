#include <iostream>

using namespace std;

const int n = 5;

int A[n][n];

int horse(int, int, int);

int visit(int d, int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < n && A[x][y] == 0) {
    A[x][y] = 1;
    int ret = horse(d, x, y);
    A[x][y] = 0;
    return ret;
  }
  return 0;
}

int horse(int d, int x, int y) {
  if (d == 1) return 1;
  int ret = 0;
  ret += visit(d-1, x+2, y-1);
  ret += visit(d-1, x+2, y+1);

  ret += visit(d-1, x-2, y-1);
  ret += visit(d-1, x-2, y+1);

  ret += visit(d-1, x-1, y-2);
  ret += visit(d-1, x+1, y-2);

  ret += visit(d-1, x-1, y+2);
  ret += visit(d-1, x+1, y+2);
  return ret;
}

int main() {
  cout << visit(n*n, 0, 0) << endl;
}
