#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int R, C, answer = 0;
vector<string> space;

void FindOtherTreasure(int y, int x) {
	vector<vector<int>> rank(R, vector<int>(C, -1));
	rank[y][x] = 0;
	queue<tuple<int, int, int>> q;
	q.push({ y, x, 0 });

	while (!q.empty()) {
		int cy, cx, cr;
		tie(cy, cx, cr) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (space[ny][nx] == 'W') continue;
			if (rank[ny][nx] != -1) continue;
			rank[ny][nx] = cr + 1;
			answer = max(answer, cr + 1);
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
			if (space[i][j] == 'L') {
				FindOtherTreasure(i, j);
			}
		}
	}
	cout << answer;
}