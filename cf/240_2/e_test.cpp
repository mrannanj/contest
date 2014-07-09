#include <iostream>

using namespace std;

int main() {
  cout << "19" << endl;
  for (int i = 1; i <= 1<<19; ++i) {
    cout << i << endl;
  }
  cout << "2" << endl;
  cout << "0" << endl;
  cout << "19" << endl;
  /*
  for (int i = 0; i < 1000000; ++i) {
    cout << i%21 << " ";
  }
  cout << endl;
  */
}
