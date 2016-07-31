#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;
    while(T--) {
        ll N, M, S;
        cin >> N >> M >> S;
        ll poisoned = (S + M - 1) % N;
        if (poisoned == 0) poisoned = N;
        cout << poisoned << endl;
    }
}
