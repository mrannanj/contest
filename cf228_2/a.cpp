#include <iostream>

typedef long long ll;

using namespace std;
ll A[128];
int n;

ll sum() {
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += A[i];
  }
  return res;
}

void dec() {
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i == j) continue;
      while (true) {
        ll res = A[i] - A[j];
        if (res <= 0) break;
        A[i] = res;
      }
    }
  }
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  ll s = sum();
  while (true) {
    dec();
    ll s2 = sum();
    if (s2 == s) break;
    s = s2;
  }
  cout << sum() << endl;
}
