#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll res;

ll unk_before;
ll unk_middle;

ll fst;
ll nxt;
ll diff;

enum State {
  INIT,
  BEFORE_FIRST,
  AFTER_FIRST,
  AFTER_SECOND
};

int main() {
  State s = INIT;
  cin >> n;
  while (n--) {
    ll x; cin >> x;
    switch (s) {
      init: case INIT:
        res += 1;
        unk_before = unk_middle = fst = nxt = diff = 0;
        s = BEFORE_FIRST;
      case BEFORE_FIRST:
        if (x == -1) {
          ++unk_before;
        } else {
          fst = x;
          s = AFTER_FIRST;
        }
        break;
      case AFTER_FIRST:
        if (x == -1) {
          ++unk_middle;
        } else {
          if ((x - fst) % (unk_middle + 1) != 0) goto init;
          diff = (x - fst) / (unk_middle + 1);
          if (fst - diff * unk_before <= 0) goto init;
          nxt = x + diff;
          s = (nxt < 1) ? INIT : AFTER_SECOND;
        }
        break;
      case AFTER_SECOND:
        if (x != -1 && x != nxt) goto init;
        nxt += diff;
        if (nxt < 1) s = INIT;
        break;
    }
  }
  cout << res << endl;
}
