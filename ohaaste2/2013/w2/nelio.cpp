#include <iostream>
#include <cstring>

using namespace std;

#define ROWS 250
#define COLS 250
#define MAXNUM 1000000

int nelio[ROWS][COLS];
char nums[MAXNUM];

int min(int a, int b) {
  return a < b ? a : b;
}

int ok(int x, int y, int size) {
  memset(nums, 0, MAXNUM);
  for (int i = x; i < x + size; ++i) {
    for (int j = y; j < y + size; ++j) {
      int k = nelio[j][i];
      if (nums[k] == 1) {
        return 0;
      }
      nums[k] = 1;
    }
  }
  return 1;
}

int main(void) {
  int n;
  int m;
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> nelio[i][j];
    }
  }

  int max_size = min(n,m);

  for (int s = max_size; s >= 1; --s) {
    for (int i = 0; i <= n-s; ++i) {
      for (int j = 0; j <= m-s; ++j) {
        if (ok(j,i,s)) {
          cout << s << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}

