#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> time(N), indegree(N, 0), answer(N, 0);
	vector<vector<int>> next(N, vector<int>());

	for (int i = 0; i < N; i++) {
		cin >> time[i];
		while (1) {
			int input;
			cin >> input;
			if (input == -1) break;
			input--;
			next[input].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < N; i++) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (indegree[cur] > 0) {
			q.push(cur);
			continue;
		}
		answer[cur] += time[cur];
		for (int i : next[cur]) {
			indegree[i]--;
			if (answer[i] == 0) answer[i] = answer[cur];
			else answer[i] = max(answer[i], answer[cur]);
		}
	}
	for (int i : answer) cout << i << "\n";
}