#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string S[2];
	for (string& s : S) cin >> s;
	vector<vector<int>> dp(S[0].size() + 1, vector<int>(S[1].size() + 1, 0));
	for (int i = 0; i < S[0].size(); i++)	{
		for (int j = 0; j < S[1].size(); j++) {
			if (S[0][i] == S[1][j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	cout << dp[S[0].size()][S[1].size()];
}