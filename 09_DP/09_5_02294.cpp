#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> coin(N), dp(K + 1, 99999);
	for (int& i : coin) cin >> i;
	dp[0] = 0;
	for (int i : coin) {
		for (int j = 1; j <= K; j++) {
			if (j >= i) dp[j] = min(dp[j], dp[j - i] + 1);
		}
	}
	if (dp[K] == 99999) cout << "-1";
	else cout << dp[K];
}