#include <iostream>
#include <set>

using namespace std;

set<int> al;

int main() {
  int n; cin >> n;
  int s, e; cin >> s >> e;
  for (int i = s; i < e; ++i)
    al.insert(i);
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    for (int i = x; i < y; ++i)
      al.erase(i);
  }
  cout << al.size() << endl;
}
