/* [풀이]
1. 위상정렬 : indegree가 0인 노드부터 처리
2. 현재 값 뒤에 어떤 값들이 있는지 저장.
현재 값을 뺄 때 뒤의 값에 indegree를 -해줌
3. 현재 건물을 지을 수 있다면 현재 시간 + 걸리는 시간
4. 뒷타임, 걸리는 시간의 업데이트
- 0이라면 현재 시간으로 업데이트
- 아니라면 두 값 중 오래 걸리는 값으로 업데이트
*/
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