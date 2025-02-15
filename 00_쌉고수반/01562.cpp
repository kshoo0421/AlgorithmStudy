#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000000
using namespace std;

int N;
long long dp[101][10][1024]; // 최대 N=100, 10자리, 1024(2^10) 상태

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int len = 1; len < N; len++) {
        for (int last = 0; last < 10; last++) {
            for (int bit = 0; bit < 1024; bit++) {
                if (dp[len][last][bit] == 0) continue;

                if (last < 9) {
                    dp[len + 1][last + 1][bit | (1 << (last + 1))] =
                        (dp[len + 1][last + 1][bit | (1 << (last + 1))] + dp[len][last][bit]) % MOD;
                }
                if (last > 0) {
                    dp[len + 1][last - 1][bit | (1 << (last - 1))] =
                        (dp[len + 1][last - 1][bit | (1 << (last - 1))] + dp[len][last][bit]) % MOD;
                }
            }
        }
    }
    LL answer = 0;
    for (int last = 0; last < 10; last++) {
        answer = (answer + dp[N][last][1023]) % MOD;
    }
    cout << answer;
}
