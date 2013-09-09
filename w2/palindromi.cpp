#include <iostream>
#include <string.h>

using namespace std;

#define MAXLEN 10000

void check() {
  char s[MAXLEN];
  memset(s, 0, MAXLEN);
  cin >> s;
  int len = strlen(s);
  int k = 0;
  int j = len-1;
  int skips = 0;
  while (k < j) {
    if (s[k] != s[j]) {
      //cout << "MISMATCH " << s[k] << ", " << s[j] << endl;
      if (skips == 0) {
        if (s[k+1] == s[j]) {
          k++;
          skips = 1;
        } else if (s[j-1] == s[k]) {
          --j;
          skips = 1;
        } else {
          cout << "NO" << endl;
          return;
        }
      } else {
        cout << "NO" << endl;
        return;
      }
    }
    //cout << "MATCH " << s[k] << ", " << s[j] << endl;
    ++k; --j;
  }
  cout << "YES" << endl;
}

int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    check();
  }

  return 0;
}
