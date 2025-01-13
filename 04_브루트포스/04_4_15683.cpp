/* [풀이]
1. 백트래킹으로 모두 탐색한다.
2. 카메라의 위치를 vector에 저장하고, 카메라별 모든 가능성을 탐색한다.
3. 방문/방문 취소 함수를 만들고. 방문했을 때 +1, 방문 취소했을 때 -1을 한다.
(벽은 +1을 하고 시작한다.)
4. 한 줄을 탐색할 때 범위를 벗어나거나 벽을 만나면 방문/방문 취소를 종료한다.
5. 현재 최솟값보다 현재의 값이 적으면 값을 업데이트한다.
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dy[4] = { 0, -1, 0, 1 }; // 우, 하, 좌, 상
int dx[4] = { 1, 0, -1, 0 }; // 우, 하, 좌, 상

int N, M; // 입력값
vector<vector<int>> grid;
vector<vector<int>> isVisited;
vector<pair<int, int>> cctv;

int minimum; // 최솟값 => 정답

void FillLine(int idx, int dir, bool isActive) { // 줄 채우는 함수
    int cy = cctv[idx].Y;
    int cx = cctv[idx].X;
    
    while(1) {
        cy += dy[dir];
        cx += dx[dir];
        if(cy < 0 || cy >= N || cx < 0 || cx >= M) break; // 범위 밖
        if(grid[cy][cx] == 6) break; // 벽
        isVisited[cy][cx] += (isActive ? 1 : -1); // +1 or -1
    }
}

void CheckCCTV(int idx) {
    if(idx == cctv.size()) { // 모든 cctv 확인
        int cnt = 0;
        for(int i = 0; i < N; i++) { // 갯수 체크
            for(int j = 0; j < M; j++) {
                if(!isVisited[i][j]) cnt++;
            }
        }
        if(cnt < minimum) minimum = cnt; // 값 업데이트
        return;
    }

    switch(grid[cctv[idx].Y][cctv[idx].X]) {
    case 1: // 1번 카메라
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true); // 1방향 방문
            CheckCCTV(idx + 1);
            FillLine(idx, i, false); // 1 방향 방문 취소
        }
        break;
    case 2: // 2번 카메라
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true); // 2방향 방문
            FillLine(idx, (i + 2) % 4, true); // 반대 방향
            CheckCCTV(idx + 1);
            FillLine(idx, i, false); // 방문 취소
            FillLine(idx, (i + 2) % 4, false);
        }
        break;
    case 3: // 3번 카메라
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true); // 2방향 방문
            FillLine(idx, (i + 1) % 4, true); // 옆방향
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
            FillLine(idx, (i + 1) % 4, false);
        }
        break;
    case 4:
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true); // 세 방향
            FillLine(idx, (i + 1) % 4, true);
            FillLine(idx, (i + 2) % 4, true);
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
            FillLine(idx, (i + 1) % 4, false);
            FillLine(idx, (i + 2) % 4, false);
        }
        break;
    case 5: 
        for(int i = 0; i < 4; i++) { // 모든 방향
            FillLine(idx, i, true);
        }        
        CheckCCTV(idx + 1);
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, false);
        }        
        break;
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    minimum = N * M; // 최소치의 Max = N * M

    grid.assign(N, vector<int>(M));
    isVisited.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= 1 && grid[i][j] <= 5) cctv.push_back({i, j});
            if(grid[i][j] >= 1) isVisited[i][j]++;
        }
    }
    CheckCCTV(0);
    cout << minimum;
}