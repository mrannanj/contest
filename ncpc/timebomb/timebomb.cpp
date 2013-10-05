#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;

int z[10][5][3] = {
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1}
  },
  {
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  },
  {
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  },
  {
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
  },
  {
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
  },
  {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  }
};

ll min(ll a, ll b) {
  return a < b ? a : b;
}

string data[5];
int d[5][64];

int match(int c) {
  for (int i = 0; i < 10; ++i) {
    //cout << "trying " << i << endl;
    for (int r = 0; r < 5; ++r) {
      for (int x = 0; x < 3; ++x) {
        //cout << "(" << d[r][c+x] << ", " << z[i][r][x] << ") ";
        if (d[r][c+x] != z[i][r][x]) {
          //cout << " --> mismatch" << endl;
          goto next;
        }
      }
      //cout << " --> next line" << endl;
    }
    return i;
    next:;
  }
  return -1;
}

int main() {
  for (int i = 0; i < 5; ++i) {
    getline(cin, data[i]);
    for (size_t j = 0; j < data[i].size(); ++j) {
      d[i][j] = data[i][j] == '*' ? 1 : 0;
    }
  }

  ll res = 0;
  for (size_t k = 0; k < data[0].size(); k+=4) {
    //cout << "k: " << k << endl;
    int t = match(k);
    //cout << "t: " << t << endl;
    if (t >= 0) {
      res = res * 10 + t;
    }
    //cout << "res: " << res << endl;
  }
  //cout << res << endl;
  if (res%6 == 0) {
    cout << "BEER!!" << endl;
  } else {
    cout << "BOOM!!" << endl;
  }
}

