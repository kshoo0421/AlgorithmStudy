/* [풀이]
1. 위상정렬이므로 indegree 설정.
특정 값 지운 이후 indegree 감소도 시켜야하므로 next도 설정
2. 답에 넣으면 answer에 추가, indegree를 -1로 설정
=> while문 조건 : answer의 size, indegree가 0이 아니면 통과
3. indegree를 줄일 때, 값이 0이면 idx의 최솟값 찾기
기본 idx = idx + 1 // 다음 칸
그 칸보다 앞에 칸에 idx가 0인 칸이 잇다면 idx 변경
아니면 다음 칸으로 진행
4. 정답 출력
*/
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
		if (indegree[idx] != 0) { // 답에 넣을 수 없으면
			idx++;
			continue;
		}

		answer.push_back(idx + 1);
		indegree[idx] = -1; // 이미 처리한 값
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