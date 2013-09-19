#include <iostream>
#include <cstring>

using namespace std;

#define MAXLEN 10001
#define LETTERS 26

void check(char s[]) {
  int len =strlen(s);
  int maxlen = len/2 + len%2;
  int letters[LETTERS];
  memset(letters, 0, LETTERS*sizeof(int));
  for (int k = 0; k < len; ++k) {
    letters[s[k] - 'A'] += 1;
    if (letters[s[k] - 'A'] > maxlen) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}

int main(void) {
  int n;
  cin >> n;
  for (int i =0; i < n; ++i) {
    char s[MAXLEN];
    memset(s, '\0', MAXLEN);
    cin >> s;
    check(s);
  }
  return 0;
}
