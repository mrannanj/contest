#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> str;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int s; cin >> s;
    str.push_back(s);
  }
  int pilestr = 128;
  int piles = 1;
  while (!str.empty()) {
    auto e = max_element(str.begin(), str.end());
    pilestr = *e;
    str.erase(e);
    if (pilestr == 0 and !str.empty()) {
      piles++;
      pilestr = 128;
    }
  }
  cout << piles << endl;
}
