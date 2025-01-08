/* [풀이]
1. 알파벳별로 방문 여부를 따로 기록
2. DFS로 주변 칸 중 방문하지 않은 칸을 추가로 확인
3. DFS 함수로 진입하는 시점에, 해당 칸에 방문 표시.
나올 때는 방문 해제
다음 BFS로 들어갈 때는 rank 상승
4. 결과 출력
*/

#include <bits/stdc++.h>
#define A(c) (c - 'A') // 대문자를 넣으면 숫자로 반환
using namespace std;

// 주변 방문용 dx, dy
int dx[] = { 1, -1, 0, 0 }; 
int dy[] = { 0, 0, 1, -1 };	

int R, C, answer = 0; // R, C : 입력값, answer : 최대 방문 글자(정답)

vector<string> grid;	// 입력된 글자들
vector<bool> isVisited(26, false);	// 알파벳 방문 여부

// 현재 위치와 현재까지 방문한 글자 갯수(이 칸 포함)
void DFS(int cy, int cx, int rank) {
	isVisited[A(grid[cy][cx])] = true; // 현재 칸 방문
	if(answer < rank) answer = rank; // 현재 rank가 정답보다 크다면 업데이트

	for(int i = 0; i < 4; i++) { // 주변 둘러보기
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue; // 칸 범위 벗어나면 pass
		if(isVisited[A(grid[ny][nx])]) continue; // 이미 방문한 글자라면 pass
		DFS(ny, nx, rank + 1); // 다음 칸 진입
	}

	isVisited[A(grid[cy][cx])] = false; // 방문 취소
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		string input;			// 입력용 string
		cin >> input;
		grid.push_back(input);	// 맵에 배치
	}

	DFS(0, 0, 1);
	cout << answer;
	return 0;
}