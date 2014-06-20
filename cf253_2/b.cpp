#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s[512];
int k;

int main() {
  cin >> s >> k;
  int slen = strlen(s);

  if (k > slen) {
    int tandlen = (slen + k) & ~1;
    cout << tandlen << endl;
    return 0;
  }

  int tlen = slen + k;
  int nwindow = slen - k;
  int mxrp = tlen/2;
  int mxl = 0;
  for (int i = 0; i <= nwindow; ++i) {
    memmove(&s[slen], &s[i], k);
    for (int p = 0; p < slen; ++p) {
      for (int j = 1; j <= mxrp; ++j) {
        for (int l = 0; l < j; ++l) {
          if (s[p+l] != s[p+j+l]) goto nope;
        }
        mxl = max(j*2, mxl);
nope:;
      }
    }
  }
  cout << mxl << endl;
}
