#include <iostream>
#include <map>
#include <tuple>

using namespace std;

typedef long long ll;

ll n;
int a[100000];
int b[100000];

int main(void) {
  cin >> n;
  ll joy = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  for (int i = 0; i < n; ++i) {
    if (a[i] * 2 < b[i] or b[i] == 1) {
      --joy;
    } else {
      ll x = b[i] / 2;
      joy += 1ll * x * (b[i] - x);
    }
  }
  cout << joy << endl;
}
