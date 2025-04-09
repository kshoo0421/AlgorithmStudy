#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> indegree(N, 0), answer;
	vector<vector<int>> next(N, vector<int>());
	while (M--) {
		int i1, i2;
		cin >> i1 >> i2;
		i1--, i2--;
		indegree[i2]++;
		next[i1].push_back(i2);
	}

	int idx = 0;
	while (answer.size() < N) {
		if (indegree[idx] != 0) {
			idx++;
			continue;
		}

		answer.push_back(idx + 1);
		indegree[idx] = -1;
		int minimum = idx + 1;
		for (int i : next[idx]) {
			indegree[i]--;
			if (indegree[i] == 0) {
				minimum = min(minimum, i);
			}
		}
		idx = minimum;
	}
	for (int i : answer) cout << i << " ";
}