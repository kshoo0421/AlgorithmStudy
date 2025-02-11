#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<vector<int>> dp;

void Palindrome() {
    dp.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) dp[i][i] = 1;

    for (int i = 0; i < N - 1; i++) {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }

    for (int len = 2; len < N; len++) {
        for (int i = 0; i + len < N; i++) {
            int j = i + len;
            if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    Palindrome();
    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S - 1][E - 1] << "\n";
    }
}