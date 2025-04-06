#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<vector<int>> grid, dp;

int answer = 0;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int DFS(int cy, int cx) {
	if(dp[cy][cx] != -1) return dp[cy][cx];

	int cnt = 0;
	for(int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
		if(grid[cy][cx] < grid[ny][nx]) cnt += DFS(ny, nx);
	}
	dp[cy][cx] = cnt;
	return dp[cy][cx];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N;
	grid.assign(M, vector<int>(N));
	for(auto& vi : grid) {
		for(int& i : vi) {
			cin >> i;
		}
	}
	dp.assign(M, vector<int>(N, -1));
	dp[0][0] = 1;
	cout << DFS(M - 1, N - 1);
}