#include <bits/stdc++.h>
using namespace std;
int memo[101][100001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;
	vector<pair<int, int>> inputs(n);
	for (auto& i : inputs) cin >> i.first >> i.second;
	for (int sum = 1; sum <= k; sum++) {
		for (int i = 0; i < n; i++) {
			if (inputs[i].first <= sum)
				memo[i + 1][sum] = max(memo[i][sum], memo[i][sum - inputs[i].first] + inputs[i].second);
			else memo[i + 1][sum] = memo[i][sum];
		}
	}
	cout << memo[n][k];
	return 0;
}