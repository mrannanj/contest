#include <cstdio>
#include <unordered_map>

int A[120002];
int B[120002];

int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      A[i] = a;
      A[i] = b;
    }
  }
}
