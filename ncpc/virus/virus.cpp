#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

char s1[100010];
char s2[100010];

ll min(ll a, ll b) {
  return a < b ? a : b;
}

int main() {
  cin >> s1 >> s2;
  size_t l1 = strlen(s1);
  size_t l2 = strlen(s2);
  char *p = s1;
  char *q = s2;
  ll b = 0;

  for (b = 0; *p == *q and *q and *p; ++b, ++p, ++q);

  p = &s1[l1-1];
  q = &s2[l2-1];

  ll e = 0;
  ll lmin = min(l1-b, l2-b);
  for (e = 0; e < lmin and *p == *q; ++e, --p, --q);

  //cout << "len " << l2 << endl;
  //cout << "begin " << b << endl;
  //cout << "end " << e << endl;
  cout << (l2 - (b + e)) << endl;
}

