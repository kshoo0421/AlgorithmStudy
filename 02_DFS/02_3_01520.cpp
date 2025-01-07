#include <bits/stdc++.h>
using namespace std;

int n, m, nx, ny;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int space[500][500], dp[500][500];

int DFS(int cx, int cy) {
	if (cx == m - 1 && cy == n - 1) return 1;
	if (dp[cy][cx] != -1) return dp[cy][cx];
	dp[cy][cx] = 0;
	for (int i = 0; i < 4; i++) {
		nx = cx + dx[i];
		ny = cy + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (space[cy][cx] > space[ny][nx]) dp[cy][cx] = dp[cy][cx] + DFS(nx, ny);
	}
	return dp[cy][cx];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
			dp[i][j] = -1;
		}
	}
	cout << DFS(0, 0);
	return 0;
}