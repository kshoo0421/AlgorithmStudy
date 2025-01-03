#include <bits/stdc++.h>
#define X second
#define Y first
using namespace std;
int N, M, mx = 0;
vector<vector<int>> space;
vector<pair<int, int>> tetris;

void FindMax(int y, int x, int idx) {
	if (y < 0 || y >= N || x < 0 || x >= M) return;
	for (auto vii : tetris) if (vii.Y == y && vii.X == x) return;

	tetris.emplace_back(make_pair(y, x));
	if (idx == 3) {
		int sum = 0;
		for (auto vii : tetris) sum += space[vii.Y][vii.X];
		if (sum > mx) mx = sum;
	}
	else {
		FindMax(y + 1, x, idx + 1);
		FindMax(y - 1, x, idx + 1);
		FindMax(y, x + 1, idx + 1);
		FindMax(y, x - 1, idx + 1);
	}
	tetris.pop_back();
}

void FindTValue(int y, int x) {
	if ((y == 0 || y == N - 1) && (x == 0 || x == M - 1)) return;
	int sum = 0;
	if (y == 0) sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y + 1][x];
	else if (x == 0) sum = space[y][x] + space[y - 1][x] + space[y + 1][x] + space[y][1];
	else if (y == N - 1) sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y - 1][x];
	else if (x == M - 1) sum = space[y][x] + space[y][x - 1] + space[y + 1][x] + space[y - 1][x];
	else {
		sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y + 1][x] + space[y - 1][x];
		int mn = min(min(space[y + 1][x], space[y - 1][x]), min(space[y][x + 1], space[y][x - 1]));
		sum -= mn;
	}
	if (mx < sum) mx = sum;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	space.assign(N, vector<int>(M));
	for (auto& vi : space) for (int& i : vi) cin >> i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			FindMax(i, j, 0);
			FindTValue(i, j);
		}
	}
	cout << mx;
}