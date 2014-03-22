#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct taika {
  int a[16];
  int u[17];
};

int search(taika& t, int p) {
  const int x = 34;

  switch (p) {
    case 4:
      if (t.a[0] + t.a[1] + t.a[2] + t.a[3] != x) return 0;
      break;
    case 8:
      if (t.a[4] + t.a[5] + t.a[6] + t.a[7] != x) return 0;
      break;
    case 12:
      if (t.a[8] + t.a[9] + t.a[10] + t.a[11] != x) return 0;
      break;
    case 13:
      if (t.a[0] + t.a[4] + t.a[8] + t.a[12] != x) return 0;
      if (t.a[3] + t.a[6] + t.a[9] + t.a[12] != x) return 0;
      break;
    case 14:
      if (t.a[1] + t.a[5] + t.a[9] + t.a[13] != x) return 0;
      break;
    case 15:
      if (t.a[2] + t.a[6] + t.a[10] + t.a[14] != x) return 0;
      break;
    case 16:
      if (t.a[3] + t.a[7] + t.a[11] + t.a[15] != x) return 0;
      if (t.a[0] + t.a[5] + t.a[10] + t.a[15] != x) return 0;
      return t.a[12] + t.a[13] + t.a[14] + t.a[15] == x;
  }

  int n = 0;
  for (int i = 1; i <= 16; ++i) {
    if (t.u[i]) {
      t.a[p] = i;
      t.u[i] = 0;
      n += search(t, p+1);
      t.a[p] = 0;
      t.u[i] = 1;
    }
  }
  return n;
}

int main() {
  taika tk = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  };

  cout << search(tk, 0) << endl;
}
