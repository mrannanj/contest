#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int N; cin >> N;
  map<string, int> m;
  while (N--) {
    string s;
    cin >> s;
    m[s] += 1;
  }
  int Q; cin >> Q;
  while (Q--) {
    string s;
    cin >> s;
    cout << m[s] << endl;
  }
}
