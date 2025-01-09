/* [풀이]
1. 상어 기준으로 먹을 수 있는 물고기를 탐색한다.
거리가 가까워야하므로, BFS를 사용한다.
2. BFS를 사용할 때, 거리별로 나눠서 탐색한다.
이는 queue의 size를 확인하여 나눌 수 있고,
특정 거리에서 물고기가 발견되었다면 BFS는 종료한다.
(그 이상의 거리에서 물고기가 발견되었어도 우선순위에서 밀린다.)
3. 우선순위 큐를 활용해 우선순위를 판별하고,
가장 높은 우선순위의 물고기만 먹는다.
이후 우선순위 큐를 초기화한다.
4. 기록된 거리만큼 시간이 증가된다.
5, 먹은 물고기를 카운트하고, 그 수가 상어의 크기와 동일하다면
상어의 크기를 키운다.
6. 먹을 물고기가 발견되지 않는다면 프로그램을 종료한다.
*/
#include <bits/stdc++.h>
#define FISH pair<int, pair<int, int>> // { 거리, { Y, X } }
#define DIST first // 거리
#define POS second // 위치
#define Y first
#define X second
using namespace std;

int N; // 입력값
vector<vector<int>> grid; // 입력 공간

int dy[4] = { 1, -1, 0, 0 }; // BFS
int dx[4] = { 0, 0, 1, -1 }; // BFS

pair<int, int> shark; // 상어의 위치
int sharkSize = 2, answer = 0;
priority_queue<FISH, vector<FISH>, greater<FISH>> pq; 

bool FindNearFish() { // 물고기 찾기 성공 유무 반환
	int dist = 0;
	vector<vector<bool>> isVisited(N, vector<bool>(N, false));
	queue<pair<int, int>> q;
	q.push(shark);
	
	while(!q.empty()) { // BFS
		int qSize = q.size(); // 현재 큐의 크기만큼 반복
		dist++; // 거리 1 증가
		for(int s = 0; s < qSize; s++) { // s : size. dist 거리에 있는 물고기 탐색
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
				if(grid[ny][nx] > 0) { // 물고기 O
					if(grid[ny][nx] < sharkSize) { // 먹을 수 있음
						pq.push({dist, {ny, nx}});
					}
					else if(grid[ny][nx] == sharkSize) { // 지나갈 수 있음
						q.push({ny, nx});
					}
				}
				else q.push({ny, nx}); // 물고기 X					
			}
		}
		if(!pq.empty()) return true; // 물고기가 있음
	}
	return false; // 물고기가 없음
}

void EatFish() {
	static int eatCnt = 0; // 이 함수 내에서만 사용하지만 저장 필요 : static
	FISH fish = pq.top(); // 최우선순위의 물고기
	while(!pq.empty()) pq.pop(); // 나머지 비우기
	shark = fish.POS; // 상어 위치 변경
	answer += fish.DIST; // 거리만큼 시간 증가
	grid[fish.POS.Y][fish.POS.X] = 0; // 물고기가 있던 공간 비우기

	eatCnt++; // 먹은 갯수 추가
	if(eatCnt == sharkSize) { // 상어 크기 == 먹은 갯수
		eatCnt = 0; // 먹은 갯수 초기화
		sharkSize++; // 상어 크기 증가
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
			if(grid[i][j] == 9) { // 아기 상어라면
				shark = { i, j }; // 위치 저장
				grid[i][j] = 0; // 해당 위치는 0으로 초기화
			}
		}
	}
	while(FindNearFish()) EatFish(); // 물고기 발견하면 먹기
	cout << answer;
}