#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> cards[100];

long tmp[2];

bool empty() {
  for (int i = 0; i < n; ++i)
    if (!cards[i].empty()) return false;
  return true;
}

int getback() {
  int m = 0;
  int d = 0;
  for (int i = 0; i < n; ++i) {
    if (cards[i].empty()) continue;
    int x = cards[i].back();
    if (x > m) {
      m = x;
      d = i;
    }
  }
  cards[d].pop_back();
  return m;
}

int getfront() {
  int m = 0;
  int d = 0;
  for (int i = 0; i < n; ++i) {
    if (cards[i].empty()) continue;
    int x = cards[i].front();
    if (x > m) {
      m = x;
      d = i;
    }
  }
  cards[d].pop_front();
  return m;
}

int main() {
  cin >> n;
  for (int j = 0; j < n; ++j) {
    int p; cin >> p;
    for (int i = 0; i < p; ++i) {
      int num; cin >> num;
      cards[j].push_back(num);
    }
  }

  for (int i = 0; !empty(); ++i) {
    if (i%2 == 0) {
      tmp[0] += getfront();
    } else {
      tmp[1] += getback();
    }
  }

  cout << tmp[0] << " " << tmp[1] << endl;
}

