#include <iostream>

using namespace std;

int main(void) {
  int i;
  cin >> i;
  for (int k = 0; k < i; ++k) {
    int n;
    int m;
    cin >> n;
    cin >> m;
    int x = m *(n-1) + n*(m-1);
    if (x %2 ==0) {
      cout << "Maija" <<endl;
    } else {
      cout << "Uolevi" <<endl;
    }
  }
  return 0;
}

