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

int jono[100000];
int jonob[100000];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n,m; cin >> n >> m;
    int max = 0;
    int min = 0;
    memset(jono, 0, sizeof(jono));
    memset(jonob, 0, sizeof(jono));

    for (int i = 1; i <= m; ++i) {
      int a, b; cin >> a >> b;
      int f = 0;
      for (int j = a; j <= b; ++j) {
        if (jono[j] == 0) {
          jono[j] = 1;
          if (f == 0) {
            f = 1;
            max++;
          }
        }
      }
      for (int j = a; j <= b; ++j) {
        if (jonob[j] == 1) {
          goto skip;
        }
      }
      min++;
      for (int j = a; j <= b; ++j) {
        jonob[j] = 1;
      }
skip:;
    }
    for (int i = 1; i <= n; ++i) {
      if (jono[i] == 0) {
        max++;
      }
    }
    for (int i = 1; i <= m; ++i) {
      int a, b; cin >> a >> b;
    }
    cout << min << " " << max << endl;
  }
}

