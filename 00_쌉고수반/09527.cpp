#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL Get1Cnt(LL X) {
    if (X == 0) return 0;
    LL cnt = 0, power = 1;
    while (power <= X) {
        LL totalPairs = (X + 1) / (power * 2);
        LL left = (X + 1) % (power * 2);
        cnt += totalPairs * power + max((LL)0, left - power);
        power *= 2;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL A, B;
    cin >> A >> B;
    cout << Get1Cnt(B) - Get1Cnt(A - 1);
}