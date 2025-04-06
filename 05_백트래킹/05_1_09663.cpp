#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;
vector<vector<bool>> isUsed(15, vector<bool>(15, false));
bool isAllUsed;

void CheckUsed(int x, int y, bool isPlus) {
	for (int i = y + 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == x || y - x == i - j || x + y == i + j) { 
				if (isPlus) isUsed[i][j] = true;
				else isUsed[i][j] = false;
			}
		}
	}
}

void BackTracking(int idx) {
	if (idx == N)	{
		cnt++;
		return;
	}

	isAllUsed = true;
	for (int i = 0; i < N; i++) {
		if (isUsed[idx + 1][i] == false) {
			isAllUsed = false;
			break;
		}
	}
	if (isAllUsed) return;

	for (int i = 0; i < N; i++) {
		if (isUsed[idx][i] == 0) {
			CheckUsed(i, idx, true);
			BackTracking(idx + 1);
			CheckUsed(i, idx, false);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	BackTracking(0);
	cout << cnt;
}