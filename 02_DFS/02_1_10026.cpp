/* [풀이]
1. 색약일 경우 vs 아닐 경우 둘 다 계산해야하므로 케이스 분류
2. dfs를 통해 원래 색과 다음 칸의 색을 비교. 같은 색의 칸으로만 확장
- 색약인 경우 : R과 G를 같은 색으로 간주
- 아닌 경우 : 다른 색으로 간주
3. 모든 칸을 방문할 때까지 반복. 함수 실행 횟수가 각 구역의 갯수가 됨
*/
#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int N;
vector<string> grid; // 전체 그림
vector<vector<bool>> visited; // 

// dfs
void DFS(int y, int x, char color, bool isBlind) {
    stack<pair<int, int>> stk; // stack : dfs. queue로 바꾸면 bfs
    stk.push({ y, x }); // 시작 위치
    visited[y][x] = true; // 시작 위치 방문

    while (!stk.empty()) {
        int cy = stk.top().Y; // current y
        int cx = stk.top().X; // current x
        stk.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i]; // next y
            int nx = cx + dx[i]; // next x
            // nx ny가 범위 안이고, 방문하지 않은 칸이라면
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {
                if (isBlind) { // 색약의 경우
                    // 기존 색이 'R'이나 'G' + 다음 칸 색도 'R'이나 'G'
                    if ((color == 'R' || color == 'G') 
                        && (grid[ny][nx] == 'R' || grid[ny][nx] == 'G')) {
                        visited[ny][nx] = true;
                        stk.push({ ny, nx });
                    }
                    else if (color == 'B' && grid[ny][nx] == 'B') {
                        visited[ny][nx] = true;
                        stk.push({ ny, nx });
                    }
                }
                else { // 색약이 아닌 경우
                    if (grid[ny][nx] == color) {
                        visited[ny][nx] = true;
                        stk.push({ ny, nx });
                    }
                }
            }
        }
    }
}

// 색약 여부에 따라 구역 갯수 구하는 함수
int GetCnt(bool isBlind) {
    // 방문 여부 새로 할당(N x N)
    visited.assign(N, vector<bool>(N, false));
    int regions = 0; // 현재 칸 : 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                regions++;
                DFS(i, j, grid[i][j], isBlind);
            }
        }
    }
    return regions;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    grid.resize(N);
    for(auto& s : grid) cin >> s;
    cout << GetCnt(false) << " " << GetCnt(true);
    return 0;
}