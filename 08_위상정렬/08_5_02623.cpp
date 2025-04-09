#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> indegree(N, 0), answer;
	vector<vector<int>> next(N, vector<int>());
	while(M--) {
		int cnt;
		cin >> cnt;

		int before, cur;
		for (int i = 0; i < cnt; i++) {
			cin >> cur;
			cur--;
			if (i > 0) {
				indegree[cur]++;
				next[before].push_back(cur);
			}
			before = cur;
		}
	}

	queue<int> zeros;
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			zeros.push(i);
		}
	}

	while (!zeros.empty()) {
		int cur = zeros.front();
		zeros.pop();
		answer.push_back(cur);
		for (int i : next[cur]) {
			indegree[i]--;
			if (indegree[i] == 0) zeros.push(i);
		}
	}
	for (int i : indegree) {
		if (i > 0) {
			cout << "0";
			return 0;
		}
	}
	for (int i : answer) cout << i + 1 << "\n";
}