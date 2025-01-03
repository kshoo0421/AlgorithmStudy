#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> memo;
	vector<pair<int, int>> input(n);
	for (auto& i : input) cin >> i.first >> i.second;
	sort(input.begin(), input.end());
	memo.push(input[0].second);
	for (int i = 1; i < n; i++)
	{
		if (memo.top() <= input[i].first) memo.pop();
		memo.push(input[i].second);
	}
	cout << memo.size();
	return 0;
}