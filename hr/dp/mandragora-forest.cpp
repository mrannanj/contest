#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> H(1e5 + 1);

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> H[i];
    }
    sort(H.begin(), H.begin()+N);
    H[N] = 0;
    for (int i = N-1; i >= 0; --i) {
      H[i] += H[i+1];
    }
    long m = 0;
    for (long i = 0; i < N; ++i) {
      long v = (1+i) * H[i];
      m = v > m ? v : m;
    }
    cout << m << endl;
  }
}
