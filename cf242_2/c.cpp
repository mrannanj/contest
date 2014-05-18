#include <iostream>
#include <cstdio>

using namespace std;

int n;
int m[100][100];
int f[100];
int k[100];

int v(int i, int n) {
  return (((n-i) % 2) * i) ^ f[(i-1)/2] ^ k[i];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i-1] ^ i;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i/2; ++j) {
      k[i] ^= (i % j);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      m[i][j] = i % j;
    }
  }

  cout << hex;
  printf("     ");
  for (int j = 1; j <= n; ++j)
    printf("%3x ", j);
  printf("\n");

  for (int i = 1; i <= n; ++i) {
    printf("%3x: ", i);
    int l = 0;
    for (int j = 1; j <= n; ++j) {
      l ^= m[i][j];
      printf("%3x ", m[i][j]);
    }
    printf("%3x %3x %3x\n", l, v(i, n), k[i]);
  }
  cout << '\n';

  /*
  int q = 0;
  for (int i = 1; i <= n; ++i) {
    int p; cin >> p;
    q ^= p ^ m[i];
  }
  cout << q << endl;

  for (int i = 1; i <= n; ++i) {
    cout << hex << m[i] % i << " " << m[n] << endl;
  }
  */
}
