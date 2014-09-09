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

int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, m; cin >> n >> m;
    cout << (((n*m) % 6 == 0) ? "YES" : "NO") << endl;
  }
}

