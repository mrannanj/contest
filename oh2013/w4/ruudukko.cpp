#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef const int ci;
typedef const unsigned cu;

long t;
long n;
long m;

int main() {
  char s[128];
  cin >> t;
  while (t--) {
    memset(s, 0, 128);
    long x, y;
    cin >> n >> m;
    cin >> s;
    cin >> x >> y;
    long l = strlen(s);
    long r = (m*(x-1) + y) % strlen(s) - 1;
    if (r == -1) {
      cout << s[l-1] << endl;
    } else {
      cout << s[r] << endl;
    }
  }
}

