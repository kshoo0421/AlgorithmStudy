/* [풀이]
1. 모든 땅마다 해당 위치에 보물이 있다고 가정하고
가장 먼 곳에 다른 보물을 배치한다.
2. 해당 값이 현재의 정답보다 크다면 정답을 업데이트한다.
3. 모든 칸을 돌았을 때, 최종 정답이 된다.
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int R, C, answer = 0;
vector<string> space;

// 현재 칸에 보물을 묻었다고 가정하고,
// 다른 어떤 곳에 보물을 묻을 수 있는지 확인한다.
void FindOtherTreasure(int y, int x) {
	vector<vector<int>> rank(R, vector<int>(C, -1));
	rank[y][x] = 0;
	queue<tuple<int, int, int>> q; // BFS, {y, x, rank}
	q.push({ y, x, 0 });

	while (!q.empty()) { // BFS 실행
		int cy, cx, cr; // CurrentY, CurrentX, CurrentRank
		tie(cy, cx, cr) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (space[ny][nx] == 'W') continue;
			if (rank[ny][nx] != -1) continue;
			rank[ny][nx] = cr + 1;
			answer = max(answer, cr + 1); // 최대 칸이 현재 답보다 큰지 확인
			q.push({ ny, nx, cr + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	space.resize(R);
	for (auto& s : space) cin >> s;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (space[i][j] == 'L') { // 땅이라면 확인
				FindOtherTreasure(i, j);
			}
		}
	}
	cout << answer;
}
