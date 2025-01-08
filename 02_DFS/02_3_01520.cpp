/* [풀이]
1. DFS : 현재 위치로 오기 위해 몇 가지의 가능성이 있는지 계산하는 함수
주변 칸 탐색 후 자신의 값보다 크다면, 해당 칸에서 추가 탐색(재귀)
2. 중복된 탐색을 할 수 있으므로, 탐색을 한 후 dp(Dynamic Programming)에 저장.
dp에 값이 있다면 해당 값을 반환하고, 아니라면 계산 실행
*/

#include <bits/stdc++.h>
using namespace std;

// 입력값
int M, N;
vector<vector<int>> grid, dp;

int answer = 0; // 현재까지 도달 횟수

// DFS용
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 현재 칸(cy, cx)까지의 경로 계산
int DFS(int cy, int cx) {
	if(dp[cy][cx] != -1) return dp[cy][cx]; // 이미 방문했다면 계산한 값 반환

	int cnt = 0; // 현재 칸으로 오는 경로 갯수
	for(int i = 0; i < 4; i++) { // 주변 탐색
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue; // 범위를 벗어나면 pass
		if(grid[cy][cx] < grid[ny][nx]) cnt += DFS(ny, nx); // 더 작은 쪽에서 경로를 받을 수 있음
	}
	dp[cy][cx] = cnt; // dp값 업데이트
	return dp[cy][cx]; // 해당 값 출력
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N; // 입력
	grid.assign(M, vector<int>(N)); // 동적 할당 M x N
	for(auto& vi : grid) {	// vi : Vector<Int>
		for(int& i : vi) { // i : Int
			cin >> i; // 입력
		}
	}

	dp.assign(M, vector<int>(N, -1)); // 동적 할당 M x N. 0으로 초기화
	dp[0][0] = 1;  // 시작지점까지의 경로는 1개

	cout << DFS(M - 1, N - 1); // 도착지점까지의 경로 출력
}