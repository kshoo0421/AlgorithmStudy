/* [풀이]
1. 총 3가지 단계
(1) 빙하가 몇 개의 그룹인지 확인한다
(2) 빙하가 얼마나 녹을지 확인한다
(3) 빙하를 녹인다
2. 1-(1)을 할 때 dfs 사용. 
이미 한 번 dfs를 했는데, 한 번 더 해야하면 그룹이 2개 이상
한 번도 dfs를 안했는데 함수가 종료되면 모두 0인 상태
3. 결과물 출력
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int N, M, year = 0;
vector<vector<int>> grid, after; // grid : 원래 빙하 / after : 경과

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool IsOneGroup() {
	vector<vector<bool>> isVisited(N, vector<bool>(M, false));
	bool isFirst = true;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(grid[y][x] == 0) continue; // 녹을 빙하가 없다면 continue
			if(isVisited[y][x]) continue; // 이미 방문한 칸이라면 continue
			// 이미 dfs를 돌렸다면 다른 그룹이 있는 것이니 false 반환
			if(!isFirst) return false;	
			isFirst = false; // dfs를 돌릴 것이기에 false 설정

			stack<pair<int, int>> stk; // dfs용 stk
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

	if(isFirst) { // 모두 0이라면
		year = 0; // year는 0
		return false; // while문 탈출
	}
	return true;
}

void AfterOneYear() {
	year++; // 1년 추가
	// 얼마나 녹는지 구하기
	for(int cy = 0; cy < N; cy++) {
		for(int cx = 0; cx < M; cx++) {
			if(grid[cy][cx] == 0) continue; // 녹을 빙하가 없다면 continue
			after[cy][cx] = 0;
			for(int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if(grid[ny][nx] == 0) after[cy][cx]--; // 주변에 바다가 있다면 녹음
			}
		}
	}

	// 녹은 값 업데이트
	for(int cy = 0; cy < N; cy++) {
		for(int cx = 0; cx < M; cx++) {
			if(grid[cy][cx] == 0) continue; // 녹을 빙하가 없다면 continue
			grid[cy][cx] += after[cy][cx];
			if(grid[cy][cx] < 0) grid[cy][cx] = 0; // 0보다 더 녹았으면 0으로 설정
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