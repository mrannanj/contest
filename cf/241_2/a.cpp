#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
  cin >> n;
  int lowest = -2 * 1000000000;
  int highest = 2 * 1000000000;
  for (int i = 0; i < n; ++i) {
    string sign;
    char ans;
    int x;
    cin >> sign >> x >> ans;
    if (ans == 'Y') {
      if (sign == ">=") {
        lowest = max(lowest, x);
      } else if (sign == ">") {
        lowest = max(lowest, x+1);
      } else if (sign == "<") {
        highest = min(highest, x-1);
      } else if (sign == "<=") {
        highest = min(highest, x);
      }
    } else {
      if (sign == ">=") {
        highest = min(highest, x-1);
      } else if (sign == ">") {
        highest = min(highest, x);
      } else if (sign == "<") {
        lowest = max(lowest, x);
      } else if (sign == "<=") {
        lowest = max(lowest, x+1);
      }
    }
  }
  if (lowest > highest) {
    cout << "Impossible" << endl;
  } else {
    cout << lowest << endl;
  }
}
