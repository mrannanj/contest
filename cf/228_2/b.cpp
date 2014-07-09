#include <iostream>
#include <cstring>

typedef long long ll;

using namespace std;
char A[128][128];
int n;

bool ok() {
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (A[j][i] == '#') {
        if (j+1 >= n or j+2 >= n or i-1 < 0 or i+1 >= n) goto fail;
        if (A[j+1][i] != '#') goto fail;
        if (A[j+2][i] != '#') goto fail;
        if (A[j+1][i-1] != '#') goto fail;
        if (A[j+1][i+1] != '#') goto fail;
        A[j][i] = A[j+1][i] = A[j+2][i] = A[j+1][i-1] = A[j+1][i+1] = 'C';
      }
    }
  }
  return true;
fail: ;
  return false;
}

int main(void) {
  cin >> n;
  memset(A, 0, 128*128);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      cin >> A[j][i];
    }
  }

  if (ok()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
