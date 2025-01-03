#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int isUsed[15][15];
bool isAllUsed;

void CheckUsed(int x, int y, bool isPlus) {
	for (int i = y + 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == x || y - x == i - j || x + y == i + j) {
				if (isPlus) isUsed[i][j]++;
				else isUsed[i][j]--;
			}
		}
	}
}

void BackTracking(int idx) {
	if (idx == n)	{
		cnt++;
		return;
	}
	isAllUsed = true;
	for (int i = 0; i < n; i++) {
		if (isUsed[idx + 1][i] == 0) {
			isAllUsed = false;
			break;
		}
	}
	if (isAllUsed) return;

	for (int i = 0; i < n; i++) {
		if (isUsed[idx][i] == 0) {
			CheckUsed(i, idx, true);
			BackTracking(idx + 1);
			CheckUsed(i, idx, false);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	BackTracking(0);
	cout << cnt;
}