#include <bits/stdc++.h>
#define NEXT(dir) ((dir + 3) % 4)
#define BACK(dir) ((dir + 2) % 4)
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M, cnt = 0;
int r, c, d;
vector<vector<int>> space;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> r >> c >> d;
	space.assign(N, vector<int>(M));
	for (auto& vi : space) {
		for (int& i : vi) {
			cin >> i;
		}
	}

	while (1) {
		bool isFin = false;
		int nr, nc;
		if (space[r][c] == 0) {
			space[r][c] = 2;
			cnt++;
		}

		for (int i = 0; i <= 4; i++) {
			if (i == 4) {
				r = r + dy[BACK(d)];
				c = c + dx[BACK(d)];
				if (space[r][c] == 1) isFin = true;
				break;
			}

			d = NEXT(d);
			nr = r + dy[d];
			nc = c + dx[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (space[nr][nc] == 0) {
				r = nr;
				c = nc;
				break;
			}
		}
		if (isFin) break;
	}
	cout << cnt;
}