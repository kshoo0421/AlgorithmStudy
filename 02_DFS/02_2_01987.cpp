#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int R, C, nx, ny, mx = 0;
vector<vector<char>> space;
map<char, int> done;

void BackTracking(int y, int x, int idx) {
	done[space[y][x]]++;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i], nx = x + dx[i];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			if (done[space[ny][nx]] == 0) BackTracking(ny, nx, idx + 1);
		}
		mx = max(mx, idx);
	}
	done[space[y][x]]--;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	cin >> R >> C;
	space.assign(R, vector<char>(C));
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			space[i][j] = input[j];
			done[space[i][j]] = 0;
		}
	}
	BackTracking(0, 0, 1);
	cout << mx;
}