#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

pair<int,int> es[20002];
int col[10001];
int lup[10001];
int nes;
int nblack;

bool dfs(int x) {
    if (col[x] != 0) return true;
    int cur_color = 1;
    stack<int> s;
    s.push(x);
    col[x] = cur_color;

    while (!s.empty()) {
        int sx = s.top();
        s.pop();
        cur_color = col[sx];
        nblack += (cur_color == 2);
        for (int i = lup[sx]; es[i].first == sx; ++i) {
            auto edge = es[i];
            if (col[edge.second] == cur_color) return false;
            if (col[edge.second] == 0) {
                col[edge.second] = 3 - cur_color;
                s.push(edge.second);
            }
        }
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(lup, 0, sizeof(lup));
        memset(col, 0, sizeof(col));
        memset(es, -1, sizeof(es));
        nes = nblack = 0;

        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            es[nes++] = make_pair(a, b);
            es[nes++] = make_pair(b, a);
        }

        sort(es, &es[nes]);
        int last = -1;
        for (int i = 0; i < nes; ++i) {
            if (es[i].first > last) {
                lup[es[i].first] = i;
                last = es[i].first;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) {
                printf("EI\n");
                goto next;
            }
        }
        printf("JOO\n");
        printf("%d\n", nblack);
        for (int i = 0; i < n; ++i) {
            if (col[i] == 2) {
                printf("%d\n", i);
            }
        }
        next:;
    }
}
