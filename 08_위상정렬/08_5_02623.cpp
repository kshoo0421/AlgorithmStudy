/* [풀이]
1. indegree가 0인 순서대로 큐에 넣는다.
2. 큐에서 pop된 원소는 answer에 넣고, 그 다음 노드들의 indegree를 1씩 줄인다.
그 결과가 0이라면 큐에 넣는다.큐가 빌 때까지 이 과정을 반복한다.
3. 아직 넣지 못한 원소가 있다면 0을, 아니라면 정답을 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
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