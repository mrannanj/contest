#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;

double dev;

double f(double r) {
  return exp(-(r*r)/(2*(dev*dev))) / (2*M_PI*dev*dev);
}

int main() {
  double bulls_eye;
  double bull;
  double inner_ring_triple;
  double outer_ring_triple;
  double inner_ring_double;
  double outer_ring_double;
  cin >> bulls_eye;
  cin >> bull;
  cin >> inner_ring_triple;
  cin >> outer_ring_triple;
  cin >> inner_ring_double;
  cin >> outer_ring_double;
  cin >> dev;
  cout << f(bulls_eye) << endl;
  cout << f(bull) << endl;
  cout << f(inner_ring_triple) << endl;
  cout << f(outer_ring_triple) << endl;
  cout << f(inner_ring_double) << endl;
  cout << f(outer_ring_double) << endl;
}

