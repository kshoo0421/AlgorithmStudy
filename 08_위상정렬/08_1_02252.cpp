/* [풀이]
1. 특정 가수 뒤에 다른 가수가 온다면 진입(indegree)을 1 늘린다.
2. 앞선 가수에는 뒤에 어떤 가수가 있는지 기록한다.
3. 진입이 0인 가수들을 큐에 넣는다.
4. 큐에 있는 요소를 하나씩 꺼내보며 정답에 추가한다.
정답에 추가할 때, 그 뒤의 가수들의 집입로를 1씩 줄이고,
진입로가 0이라면 큐에 추가한다.
5. 큐가 비었을 때 종료하는데, 아직 남은 가수가 있다면 0을,
아니라면 정답을 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> after;
vector<int> indegree;
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	indegree.assign(N, 0);
	after.assign(N, vector<int>());
	while(M--) {
		int cnt;
		cin >> cnt;
		int before, cur; // 이전, 현재
		for (int i = 0; i < cnt; i++) {
			cin >> cur;
			cur--;
			if (i > 0) {
				indegree[cur]++;
				after[before].push_back(cur);
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
		for (int i : after[cur]) {
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