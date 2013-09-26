#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define fori(i,x) for (int (i)=0; (i)<(x); ++(i))
using namespace std;
typedef const int ci;
typedef const unsigned cu;

char nimet[12][12];
int n;

int in_order() {
  for (int i = 0; i < n-1; ++i) {
    if (strncmp(nimet[i], nimet[i+1], 12) > 0) {
      return 0;
    }
  }
  return 1;
}

void swap(int i, int j) {
  char temp[12];
  memcpy(temp, nimet[i], 12);
  memcpy(nimet[i], nimet[j], 12);
  memcpy(nimet[j], temp, 12);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int swaps = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> nimet[i];
    }
    if (in_order()) {
      cout << "NO" << endl;
      goto next;
    }
    for (int k = 0; k < n; ++k) {
      for (int j = k+1; j < n; ++j) {
        swap(k,j);
        if (in_order()) {
          cout << "YES" << endl;
          goto next;
        }
        swap(k,j);
      }
    }
    cout << "NO" << endl;
next:;
  }
}

