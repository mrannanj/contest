#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll min(ll a, ll b) {
  return a < b ? a : b;
}

ll max(ll a, ll b) {
  return a > b ? a : b;
}

char s[1024];
char s2[1024];

int main() {
  ll n; cin >> n;
  cin >> s >> s2;
  if (n%2 == 0) {
    if (strcmp(s, s2) == 0) {
      cout << "Deletion succeeded" << endl;
    } else {
      cout << "Deletion failed" << endl;
    }
  } else {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; ++i) {
      if (s[i] == s2[i]) {
        cout << "Deletion failed" << endl;
        goto out;
      }
    }
    cout << "Deletion succeeded" << endl;
out: ;
  }
}

