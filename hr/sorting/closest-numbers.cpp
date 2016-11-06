#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> A(200002);

int main() {
  long N; cin >> N;
  for (long i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.begin()+N);
  long diff = A[1] - A[0];
  for (long i = 1; i < N-1; ++i) {
    long d = A[i+1] - A[i];
    if (d < diff) {
      diff = d;
    }
  }
  for (long i = 0; i < N-1; ++i) {
    if (A[i+1] - A[i] == diff) {
      cout << A[i] << " " << A[i+1] << " ";
    }
  }
  cout << endl;
}
