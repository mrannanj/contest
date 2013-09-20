#include <iostream>
#include <alloca.h>
#include <string.h>

using namespace std;

int idx(int l, int i, int j) {
  return l*i + j;
}

void tkohta_range(int& x1, int& x2, int& y1, int& y2, int* tkohta,
    int a, int b) {
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (tkohta[idx(b, i, j)] == 2) {
        y2 = i;
      }
    }
  }

  for (int j = 0; j < b; ++j) {
    for (int i = 0; i < a; ++i) {
      if (tkohta[idx(b, i, j)] == 2) {
        x2 = j;
      }
    }
  }

  for (int i = a; i >= 0; --i) {
    for (int j = b; j >= 0; --j) {
      if (tkohta[idx(b, i, j)] == 2) {
        y1 = i;
      }
    }
  }

  for (int j = b; j >= 0; --j) {
    for (int i = a; i >= 0; --i) {
      if (tkohta[idx(b, i, j)] == 2) {
        x1 = j;
      }
    }
  }
}

int main(void) {
  int n;
  int m;
  int a;
  int b;
  cin >> n;
  cin >> m;
  int* maasto = (int*)alloca(n*m*sizeof(int));
  memset(maasto, 0, n*m*sizeof(int));
  for (int i = 0; i < n; ++i) {
    char* l = (char*)alloca(m);
    cin >> l;
    for (int k = 0; k < m; ++k) {
      maasto[idx(m,i,k)] = (l[k] == '0' ? 0 : 1);
    }
  }

  cin >> a;
  cin >> b;
  int* tkohta = (int*)alloca(a*b*sizeof(int));
  memset(tkohta, 0, a*b*sizeof(int));
  for (int i = 0; i < a; ++i) {
    char* l = (char*)alloca(b);
    cin >> l;
    for (int k = 0; k < b; ++k) {
      tkohta[idx(b,i,k)] = (l[k] == '0' ? 0 : 2);
    }
  }

  int tx1, tx2, ty1, ty2;

  tkohta_range(tx1,tx2,ty1,ty2,tkohta,a,b);

  int sum = 0;

  //cout << "x: " << tx1 << "," << tx2 << " y:" << ty1 << "," << ty2 << endl;

  int x_delta = tx2-tx1;
  int y_delta = ty2-ty1;

  for (int i = 0; i < n-y_delta; ++i) {
    for (int j = 0; j < m-x_delta; ++j) {

      for (int x = tx1; x <= tx2; ++x) {
        for (int y = ty1; y <= ty2; ++y) {
          if (maasto[idx(m,i+y-ty1,j+x-tx1)] + tkohta[idx(b,y,x)] == 3) {
            goto out;
          }
        }
      }
      //cout << i << ", " << j << endl;
      sum += 1;
out:  while(0);
    }
  }

  cout << sum << endl;
}

