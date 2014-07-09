#include <iostream>
#include <climits>
#include <cstring>
#include <cstdio>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdint.h>

int a[1<<20];
int b[1<<20];
int left[(1<<19) + 1];
int right[(1<<19) + 1];
int n, m;

typedef int64_t ll;

struct pair {
  ll a,b;
};

pair inversions[20];
int state;

ll merge(int a[], int l, int m, int r, bool dir) {
  int left_size = m - l + 1;
  int right_size = r - m;

  memcpy(left, &a[l], left_size * sizeof(int));
  memcpy(right, &a[m+1], right_size * sizeof(int));
  if (dir) {
    left[left_size] = INT_MAX;
    right[right_size] = INT_MAX;
  } else {
    left[left_size] = INT_MIN;
    right[right_size] = INT_MIN;
  }

  int lp = 0;
  int rp = 0;
  ll n = 0;
  for (int i = l; i <= r; ++i) {
    if (dir) {
      if (left[lp] <= right[rp]) {
        a[i] = left[lp++];
      } else {
        a[i] = right[rp++];
        n += left_size - lp;
      }
    } else {
      if (left[lp] >= right[rp]) {
        a[i] = left[lp++];
      } else {
        a[i] = right[rp++];
        n += left_size - lp;
      }
    }
  }
  return n;
}

ll merge_sort(int a[], int l, int r, int depth, bool dir) {
  ll inv = 0;
  if (l < r) {
    int mid = (l + r)/2;
    merge_sort(a, l, mid, depth+1, dir);
    merge_sort(a, mid+1, r, depth+1, dir);
    inv += merge(a, l, mid, r, dir);
  }

  if (dir) {
    inversions[depth].a += inv;
  } else {
    inversions[depth].b += inv;
  }

  return inv;
}

void print_inv() {
  ll inv = 0;
  for (int i = 0; i < n; ++i) {
    inv += (state & 1<<i) ? inversions[i].b : inversions[i].a;
  }
  printf("%" PRId64 "\n", inv);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < (1<<n); ++ i) scanf("%d", &a[i]);
  memcpy(b, a, (1<<n)*sizeof(int));
  merge_sort(a, 0, (1<<n)-1, 0, true);
  merge_sort(b, 0, (1<<n)-1, 0, false);

  scanf("%d", &m);

  for (int i = 0; i < m; ++ i) {
    int q; scanf("%d", &q);
    for (int j = n-q; j < n; ++j) {
      state ^= 1<<j;
    }
    print_inv();
  }
}
