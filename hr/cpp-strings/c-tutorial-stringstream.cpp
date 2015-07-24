#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
  vector<int> res;
  stringstream ss(str);
  while (!ss.eof()) {
    int d;
    char skip;
    ss >> d;
    res.push_back(d);
    ss >> skip;
  }
  return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}

