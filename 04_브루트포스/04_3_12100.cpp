/* [풀이]
1. (돌리기 -> 밀기) X 5 구조로 한다.
2. 돌리기/밀기 함수는 &를 이용해 적용
3. 백트래킹은 &를 없앰으로써, call by value(값 복사)를 이용한다.
이렇게 해야 함수 내부에서만 사용된다.
4. 돌리고 밀기까지가 한 과정인데, 
한 번 밀면 이미 과정이 진행된 것이다.
따라서 돌린 후 함수를 실행하고
함수 내부에서 밀면서 이 문제를 해결했다.
5. 미는 과정에서 0이 아닌 숫자들은 큐에 저장하여
앞의 두 숫자가 같다면 합치고, 아니면 안합치는 방식을 사용했다.
큐가 비어있다면 0을 대신 채웠다.
*/
#include <bits/stdc++.h>
using namespace std;

int N, answer = 0;
vector<vector<int>> grid;

void TurnGrid(vector<vector<int>>& cur) { // 돌리기
	vector<vector<int>> copied = cur;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cur[i][j] = copied[N - 1 - j][i];
		}
	}
}

void Slide(vector<vector<int>>& cur) { // 밀기
	for (int i = 0; i < N; i++) {
		queue<int> tmp;
		for (int j : cur[i]) {
			if (j != 0) tmp.push(j);
		}

		for (int j = 0; j < N; j++) {
			if (tmp.empty()) {
				cur[i][j] = 0;
				continue;
			}
			cur[i][j] = tmp.front();
			tmp.pop();
			if (!tmp.empty() && cur[i][j] == tmp.front()) { // 겹치면 추가
				cur[i][j] *= 2;
				tmp.pop();
			}
		}
	}
}

void Step(int step, vector<vector<int>> cur) {
	Slide(cur);

	if (step == 5) {
		for (auto& vi : cur) {
			for (int& i : vi) {
				if (answer < i) {
					answer = i;
				}
			}
		}
		return;
	}

	Step(step + 1, cur);
	for (int i = 0; i < 3; i++) {
		TurnGrid(cur);
		Step(step + 1, cur);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	grid.assign(N, vector<int>(N));
	for (auto& vi : grid) {
		for (int& i : vi) {
			cin >> i;
		}
	}
	Step(1, grid);
	for (int i = 0; i < 3; i++) {
		TurnGrid(grid);
		Step(1, grid);
	}
	cout << answer;
}