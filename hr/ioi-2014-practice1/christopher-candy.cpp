#include <iostream>

using namespace std;

int n;
char s[(size_t)(1e6) + 1];
int ss;
int cs;

int sbeg[(size_t)(1e6) + 1];
int cbeg[(size_t)(1e6) + 1];

int send[(size_t)(1e6) + 1];
int cend[(size_t)(1e6) + 1];

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    ((s[i] == 'C') ? cs : ss) += 1;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'C') {
      cbeg[i+1] = cbeg[i] + 1;
      sbeg[i+1] = sbeg[i];
    } else {
      cbeg[i+1] = cbeg[i];
      sbeg[i+1] = sbeg[i] + 1;
    }
  }

  for (int i = n; i > 0; --i) {
    if (s[i-1] == 'C') {
      cend[i-1] = cend[i] + 1;
      send[i-1] = send[i];
    } else {
      cend[i-1] = cend[i];
      send[i-1] = send[i] + 1;
    }
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = n; j > i; --j) {
      int tcs = cs - (cbeg[i] + cend[j]);
      int tss = ss - (sbeg[i] + send[j]);
      sum += (tss * 2 == tcs);
    }
  }
  cout << sum << '\n';
}
