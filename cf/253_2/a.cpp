#include <iostream>
#include <cstring>

using namespace std;

char line[1024];
int letters[256];

int main() {
  cin.getline(line, sizeof(line));
  int len = strlen(line);
  for (int i = 0; i < len; ++i) letters[(unsigned)line[i]]++;
  int n = 0;
  for (int i = 'a'; i <= 'z'; ++i) n += !!letters[i];
  cout << n << endl;
}
