#include <bits/stdc++.h>
#define FISH pair<int, pair<int, int>>
#define DIST first
#define POS second
#define Y first
#define X second
using namespace std;

int N;
vector<vector<int>> grid;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

pair<int, int> shark;
int sharkSize = 2, answer = 0;
priority_queue<FISH, vector<FISH>, greater<FISH>> pq; 

bool FindNearFish() {
	int dist = 0;
	vector<vector<bool>> isVisited(N, vector<bool>(N, false));
	queue<pair<int, int>> q;
	q.push(shark);
	
	while(!q.empty()) {
		int qSize = q.size();
		dist++;
		for(int s = 0; s < qSize; s++) {
			int cy = q.front().Y;
			int cx = q.front().X;
			q.pop();
			if(isVisited[cy][cx]) continue;
			isVisited[cy][cx] = true;

			for(int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if(isVisited[ny][nx]) continue;
				if(grid[ny][nx] > 0) {
					if(grid[ny][nx] < sharkSize) {
						pq.push({dist, {ny, nx}});
					}
					else if(grid[ny][nx] == sharkSize) {
						q.push({ny, nx});
					}
				}
				else q.push({ny, nx});			
			}
		}
		if(!pq.empty()) return true;
	}
	return false;
}

void EatFish() {
	static int eatCnt = 0;
	FISH fish = pq.top();
	while(!pq.empty()) pq.pop();
	shark = fish.POS;
	answer += fish.DIST;
	grid[fish.POS.Y][fish.POS.X] = 0;

	eatCnt++;
	if(eatCnt == sharkSize) {
		eatCnt = 0;
		sharkSize++;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	grid.assign(N, vector<int>(N));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == 9) {
				shark = { i, j };
				grid[i][j] = 0;
			}
		}
	}
	while(FindNearFish()) EatFish();
	cout << answer;
}