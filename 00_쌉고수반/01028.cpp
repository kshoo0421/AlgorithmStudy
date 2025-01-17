#include <bits/stdc++.h>
using namespace std;

int R, C, biggest = 0;

vector<string> grid;

bool CheckNextSide(int y, int x, bool isLeft) {
	int ny = y + 1, nx = x + (isLeft ? -1 : 1);
	if (ny >= R || nx < 0 || nx >= C) return false;
	if (grid[ny][nx] == '1') return true;
	return false;
}

void CheckDiamond(int y, int x) {
	int idx = 0;
	int cy = y, lx = x, rx = x;
	while (CheckNextSide(cy, lx, true) && CheckNextSide(cy, rx, false)) {
		idx++, cy++, lx--, rx++;
		if (idx < biggest) continue;
		
		int ny = cy, nlx = lx, nrx = rx;
		for (int i = 0; i <= idx; i++) {
			if (i == idx) {
				biggest = max(biggest, (idx + 1));
				break;
			}

			if (CheckNextSide(ny, nlx, false) && CheckNextSide(ny, nrx, true)) {
				ny++, nlx++, nrx--;
			}
			else break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	grid.assign(R, "");
	for (auto& s : grid) cin >> s;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == '1') {
				if (biggest == 0) biggest = 1;
				CheckDiamond(i, j);
			}
		}
	}
	cout << biggest;
}