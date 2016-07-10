#include <iostream>
using namespace std;

const char *days[] = {
  "maanantai",
  "tiistai",
  "keskiviikko",
  "torstai",
  "perjantai",
  "lauantai",
  "sunnuntai"
};

int days_in_month[] = {
  0,
  31, /* tammi */
  28, /* helmi */
  31, /* maalis */
  30, /* huhti */
  31, /* touko */
  30, /* kesä */
  31, /* heinä */
  31, /* elo */
  30, /* syys */
  31, /* loka */
  30, /* marras */
  31  /* joulu */
};

int leapyear(int x) {
  return (x%4 == 0) && ((x%100 != 0) || (x%400 == 0));
}

int main() {
  int d, m, y;
  char c;
  cin >> d >> c >> m >> c >> y;
  int day = 1;
  for (int i = 1800; i < y; ++i) {
    day += 365 + leapyear(i);
  }
  for (int i = 1; i < m; ++i) {
    day += days_in_month[i] + (i == 2 && leapyear(y));
  }
  day += d;
  cout << days[day%7] << endl;
}
