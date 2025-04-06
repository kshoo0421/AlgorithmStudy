#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int N, M, year = 0;
vector<vector<int>> grid, after;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool IsOneGroup() {
	vector<vector<bool>> isVisited(N, vector<bool>(M, false));
	bool isFirst = true;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(grid[y][x] == 0) continue;
			if(isVisited[y][x]) continue;
			if(!isFirst) return false;	
			isFirst = false;

			stack<pair<int, int>> stk;
			stk.push({y, x});
			while(!stk.empty()) {
				int cy = stk.top().Y;
				int cx = stk.top().X;
				stk.pop();
				if(isVisited[cy][cx]) continue;
				isVisited[cy][cx] = true;
				for(int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
					if(grid[ny][nx] == 0) continue;
					if(isVisited[ny][nx]) continue;
					stk.push({ny, nx});
				}
			}
		}
	}

	if(isFirst) {
		year = 0;
		return false;
	}
	return true;
}

void AfterOneYear() {
	year++;
	for(int cy = 0; cy < N; cy++) {
		for(int cx = 0; cx < M; cx++) {
			if(grid[cy][cx] == 0) continue;
			after[cy][cx] = 0;
			for(int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if(grid[ny][nx] == 0) after[cy][cx]--;
			}
		}
	}

	for(int cy = 0; cy < N; cy++) {
		for(int cx = 0; cx < M; cx++) {
			if(grid[cy][cx] == 0) continue;
			grid[cy][cx] += after[cy][cx];
			if(grid[cy][cx] < 0) grid[cy][cx] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	grid.assign(N, vector<int>(M));
	after.assign(N, vector<int>(M));

	for(auto& vi : grid) {
		for(int& i : vi) {
			cin >> i;
		}
	}
	while(IsOneGroup()) AfterOneYear();
	cout << year;
}