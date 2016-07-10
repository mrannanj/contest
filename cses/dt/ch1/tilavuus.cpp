#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double r; cin >> r;
  cout << fixed << setprecision(6);
  cout << 4.0/3.0 * M_PI * r * r * r << endl;
}
