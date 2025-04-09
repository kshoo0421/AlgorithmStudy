#include <bits/stdc++.h>
using namespace std;

int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

vector<int> parent;
vector<vector<int>> grid;
vector<vector<bool>> isVisited;

inline int CalIdx(int y, int x) { return (y * M) + x; }
inline int GetY(int idx) { return (idx / M); }
inline int GetX(int idx) { return (idx % M); }

int FindParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = FindParent(parent[a]);
}

void SetUnion(int a, int b) {
	int rootX = FindParent(a);
	int rootY = FindParent(b);
	if (rootX != rootY) parent[rootY] = rootX;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	parent.assign(N * M, 0);
	grid.assign(N, vector<int>(M));
	isVisited.assign(N, vector<bool>(M, false));

	for (int i = 0; i < parent.size(); i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0) {
				int curIdx = CalIdx(i, j);
				parent[curIdx] = -1;
			}
		}
	}

	vector<int> islands;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) continue;
			if (isVisited[i][j]) continue;
			int rootIdx = CalIdx(i, j);
			islands.push_back(rootIdx);
			queue<pair<int, int>> q;
			q.push({ i, j });
			while (!q.empty()) {
				auto [cy, cx] = q.front();
				q.pop();
				if (isVisited[cy][cx]) continue;
				isVisited[cy][cx] = true;
				int curIdx = CalIdx(cy, cx);
				SetUnion(rootIdx, curIdx);
				for (int dir = 0; dir < 4; dir++) {
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
					if (grid[ny][nx] == 0 || isVisited[ny][nx]) continue;
					q.push({ ny, nx });
				}
			}
		}
	}

	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) continue;
			int rootParent = FindParent(CalIdx(i, j));
			int cy = i, cx = j;
			for (int k = 0; k < 4; k++) {
				int ny = cy, nx = cx;
				while (1) {
					ny += dy[k];
					nx += dx[k];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M) break; // 범위 밖
					if (grid[ny][nx] == 1) break;
				}
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				int len = abs(ny - cy) + abs(nx - cx);
				if (len <= 2) continue;
				edge.push_back({ CalIdx(i, j), k, len });
			}
		}
	}	

	sort(edge.begin(), edge.end(), [](auto& tiii1, auto& tiii2) {
		return get<2>(tiii1) < get<2>(tiii2);
		});

	int edgeCnt = 0, islandCnt = islands.size(), answer = 0;
	for (auto& [startIdx, dir, len] : edge) {
		int startY= GetY(startIdx), startX = GetX(startIdx);
		int endY = startY + (len * dy[dir]);
		int endX = startX + (len * dx[dir]);
		int endIdx = CalIdx(endY, endX);
		if (FindParent(startIdx) != FindParent(endIdx)) {
			for (int i = 1; i < len; i++) {
				int ny = startY + (dy[dir] * i);
				int nx = startX + (dx[dir] * i);
				grid[ny][nx] = 2;
			}
			SetUnion(startIdx, endIdx);
			answer += (len - 1);
			edgeCnt++;
		}
		if (edgeCnt == islandCnt - 1) break;
	}
	if (edgeCnt != islandCnt - 1) cout << "-1";
	else cout << answer;
}