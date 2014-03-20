#include <iostream>

using namespace std;

char A[300][300];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> A[i][j];
    }
  }
  char x_char = A[0][0];
  char o_char = A[1][0];
  if (x_char == o_char) goto fail;

  for (int i = 0; i < n; ++i) {
    if (A[i][i] != x_char) goto fail;
  }

  for (int i = 0; i < n; ++i) {
    if (A[i][n-i-1] != x_char) goto fail;
  }

  for (int i = 0; i < n; ++i)
    A[i][i] = o_char;

  for (int i = 0; i < n; ++i)
    A[i][n-i-1] = o_char;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (A[i][j] != o_char) goto fail;
    }
  }

  cout << "YES" << endl;
  return 0;
fail:
  cout << "NO" << endl;
}
