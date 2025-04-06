#include <bits/stdc++.h>
#define A(c) (c - 'A')
using namespace std;

int dx[] = { 1, -1, 0, 0 }; 
int dy[] = { 0, 0, 1, -1 };	

int R, C, answer = 0;

vector<string> grid;
vector<bool> isVisited(26, false);

void DFS(int cy, int cx, int rank) {
	isVisited[A(grid[cy][cx])] = true;
	if(answer < rank) answer = rank;

	for(int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
		if(isVisited[A(grid[ny][nx])]) continue;
		DFS(ny, nx, rank + 1);
	}

	isVisited[A(grid[cy][cx])] = false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		string input;
		cin >> input;
		grid.push_back(input);
	}
	DFS(0, 0, 1);
	cout << answer;
	return 0;
}