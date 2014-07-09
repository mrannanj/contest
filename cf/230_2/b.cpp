#include <iostream>

using namespace std;

float W[170][170];
float A[170][170];
float B[170][170];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> W[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      float w1 = W[i][j];
      float w2 = W[j][i];
      A[i][j] = (w2 + w1)/2;
      A[j][i] = (w2 + w1)/2;
      B[i][j] = (w1 - w2)/2;
      B[j][i] = -(w1 - w2)/2;
    }
  }
  for (int i = 0; i < n; ++i) {
    A[i][i] = W[i][i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << A[i][j];
      if (j < n-1) cout << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << B[i][j];
      if (j < n-1) cout << " ";
    }
    cout << endl;
  }
}
