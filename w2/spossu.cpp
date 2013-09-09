#include <iostream>

using namespace std;

int months[] = {
  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int karkaus(int i) {
  return ((i%4 == 0 && i%100 != 0) || (i%400 == 0));
}

int date_to_range(int y, int m, int d) {
  int sum = (y - 1900) * 365;
  for (int i = 1900; i < y; ++i) {
    if (karkaus(i)) {
        sum += 1;
    }
  }
  for (int i = 1; i < m; ++i) {
    sum += months[i];
    if (i == 2 && karkaus(y)) {
      sum += 1;
    }
  }
  sum += d;
  return sum;
}

void print_range() {
  int y1;
  int y2;
  int m1;
  int m2;
  int d1;
  int d2;
  char c;
  //cin >> y1 >> c >> m1 >> c >> d1 >> c;
  cin >> y1;
  cin >> c;
  cin >> m1;
  cin >> c;
  cin >> d1;

  cin >> y2;
  cin >> c;
  cin >> m2;
  cin >> c;
  cin >> d2;

  int r1 = date_to_range(y1, m1, d1);
  int r2 = date_to_range(y2, m2, d2);
  cout << (r2-r1+1) << endl;
}

int main(void) {

  int n;
  cin >> n;

  for (int i =0; i<n; ++i) {
    print_range();
  }

  return 0;
}
