#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int r[1024];

class Req {
  public:
  int c;
  int p;
  int idx;
  int t;
};

class CompReq  {
  public:
  bool operator()(const Req& r1, const Req& r2) {
    return r1.p < r2.p;
  }
};

priority_queue<Req, std::vector<Req>, CompReq> pq;
vector<Req> acc;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    Req req;
    cin >> req.c >> req.p;
    req.idx = i;
    pq.push(req);
  }
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> r[i];
  }

  int accepted = 0;
  int money = 0;
  while (!pq.empty()) {
    Req req = pq.top();
    pq.pop();
    int idx = -1;
    int min_val = 1024;
    for (int i = 1; i <= k; ++i) {
      if (r[i] == -1) continue;
      if (req.c == r[i]) {
        idx = i;
        break;
      } else if (req.c <= r[i] && min_val > r[i]) {
        idx = i;
        min_val = r[i];
      }
    }
    if (idx != -1) {
      req.t = idx;
      acc.push_back(req);
      money += req.p;
      r[idx] = -1;
    }
  }

  cout << acc.size() << " " << money << endl;
  for (Req req : acc) {
    cout << req.idx << " " << req.t << endl;
  }
}
