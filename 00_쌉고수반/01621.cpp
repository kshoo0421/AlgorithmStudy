#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, K, C;
    cin >> N >> K >> C;
    vector<int> bananas(N + 1, 0), dp(N + 1, INT_MAX), prefixSum(N + 1, 0);
    vector<int> groupChoice(N + 1, -1);

    for (int i = 1; i <= N; i++) {
        cin >> bananas[i];
        prefixSum[i] = prefixSum[i - 1] + bananas[i];
    }

    dp[0] = 0;
    deque<int> dq;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + bananas[i];

        if (!dq.empty() && dq.front() < i - K) dq.pop_front();

        int start = max(0, i - K);
        if (dp[start] + C < dp[i]) {
            dp[i] = dp[start] + C;
            groupChoice[i] = start + 1;
        }

        while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }

    cout << dp[N] << "\n";

    vector<int> Ks;
    int i = N;
    while (i > 0) {
        if (groupChoice[i] != -1) {
            Ks.push_back(groupChoice[i]);
            i = groupChoice[i] - 1;
        } 
        else i--;
    }

    cout << Ks.size() << "\n";
    sort(Ks.begin(), Ks.end());
    for (int i : Ks) cout << i << " ";
}