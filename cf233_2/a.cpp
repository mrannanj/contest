#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
  int n, p, k; cin >> n >> p >> k;
  stringstream ss;

  if (p-k > 1) ss << "<< ";
  for (int i = max(p-k, 1); i < p; ++i) ss << i << " ";
  ss << "(" << p << ") ";
  for (int i = p+1; i <= p+k && i <= n; ++i) ss << i << " ";
  if (p+k < n) ss << ">>";
  cout << ss.str() << endl;
}
