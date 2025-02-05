#include <bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

LL ModPow(LL base, LL exp, LL mod) {
    LL result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int M;
    cin >> M;
    LL answer = 0;
    while (M--) {
        LL N, S;
        cin >> N >> S;
        LL invN = ModPow(N, MOD - 2, MOD);
        answer = (answer + (S * invN) % MOD) % MOD;
    }    
    cout << answer;
}
