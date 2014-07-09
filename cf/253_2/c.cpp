#include <iostream>

using namespace std;

int n;

int g_color[102];
int g_number[102];
int u_color[102];
int u_number[102];

int hints_col[6];
int hints_num[6];
int avail[6][6];

int options(int i) {
  int n_col = 0;
  int n_num = 0;
  int col = u_color[i];
  int num = u_number[i];
  if (col == 0) {
    for (int c = 1; c <= 5; ++c) {
      //avail_col[c] 
    }
  }
  return 0;
}

void hint_color(int i) {
  for (int c = 0; i < n; ++i) {
    if (g_color[c] == i) {
      u_color[c] = i;
    }
  }
}

void hint_number(int i) {
  for (int c = 0; i < n; ++i) {
    if (g_number[c] == i) {
      u_number[c] = i;
    }
  }
}

void rec() {
  for (int i = 1; i <= 5; ++i) {
    if (hints_num[i]) {
      hint_number(i);
    }
  }
  for (int i = 1; i <= 5; ++i) {
    if (hints_col[i]) {
      hint_color(i);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char s[10]; cin >> s;
    int col = -1;
    int num = -1;
    switch (s[0]) {
      case 'R': col = 1; break;
      case 'G': col = 2; break;
      case 'B': col = 3; break;
      case 'Y': col = 4; break;
      case 'W': col = 5; break;
      default: cout << "invalid color" << endl; return 1;
    }
    switch (s[1]) {
      case '1': num = 1; break;
      case '2': num = 2; break;
      case '3': num = 3; break;
      case '4': num = 4; break;
      case '5': num = 5; break;
      default: cout << "invalid number" << endl; return 1;
    }
    hints_col[col] = 1;
    hints_num[num] = 1;
    avail[col][num] += 1;
    g_color[i] = col;
    g_number[i] = num;
  }
}
