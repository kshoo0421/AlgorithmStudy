#include <bits/stdc++.h>
#define X second
#define Y first
using namespace std;

int N, L, R, cx, cy, nx, ny, tx, ty, tk, dif, sum, cnt = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> A, cmp;
vector<vector<bool>> isVisited;
vector<vector<vector<bool>>> isOpen;
queue<pair<int, int>> q, memo;

void CheckOpen() {
	isOpen.assign(N, vector<vector<bool>>(N, vector<bool>(2, false)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cx = j, cy = i;
			for (int k = 0; k < 2; k++) {
				nx = cx + dx[k];
				ny = cy + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				dif = abs(A[cy][cx] - A[ny][nx]);
				if (dif >= L && dif <= R) isOpen[cy][cx][k] = true;
			}
		}
	}
}

void Move() {
	isVisited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisited[i][j]) {
				sum = 0;
				q.push({ i, j });
				while (!q.empty()) {
					cx = q.front().X;
					cy = q.front().Y;
					q.pop();
					if (isVisited[cy][cx]) continue;
					isVisited[cy][cx] = true;
					sum += A[cy][cx];
					memo.push({ cy, cx });
					for (int k = 0; k < 4; k++) {
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (k > 1) tk = k - 2, tx = nx, ty = ny;
						else tk = k, tx = cx, ty = cy;
						if (!isOpen[ty][tx][tk]) continue;
						q.push({ ny, nx });
					}
				}
				sum /= memo.size();
				while (!memo.empty()) {
					A[memo.front().Y][memo.front().X] = sum;
					memo.pop();
				}
			}
		}
	}
}

bool IsDiff() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (cmp[i][j] != A[i][j]) return true;
	return false;

}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> L >> R;
	A.assign(N, vector<int>(N));
	cmp.assign(N, vector<int>(N));
	for (auto& vi : A) for (int& i : vi) cin >> i;
	cmp = A;

	while (1) {
		CheckOpen();
		Move();
		if (IsDiff()) {
			cmp = A;
			cnt++;
			continue;
		}
		else break;
	}
	cout << cnt;
}