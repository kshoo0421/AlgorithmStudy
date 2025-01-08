/* [풀이]
1. 벽을 부수지 않은 경우 최솟값 구하기.
BFS 사용. (0, 0)부터 (N-1, M-1)까지의 거리와 그 역순으로 거리를 구함
2. 벽을 부순다고 가정했을 때 구하기
- 한 벽을 기준으로 상하좌우에 (0, 0) ~> 벽, 벽 ~> (M-1, N-1)로 갈 수 있는 길이 있다면
그 최솟값들을 더함
3. 이렇게 나온 값들 중 가장 최소의 값을 정답으로 제출
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M, result;
vector<vector<int>> grid;

void BFS(vector<vector<int>>& vvi, int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    vvi[y][x] = 1;
    while (!q.empty()) {
        int cy = q.front().Y;
        int cx = q.front().X;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (grid[ny][nx] != 1) {
                if(vvi[ny][nx] > vvi[cy][cx] + 1 || vvi[ny][nx] == -1) {
                    vvi[ny][nx] = vvi[cy][cx] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    grid.assign(N, vector<int>(M));
    vector<vector<int>> before(N, vector<int>(M, -1)), after(N, vector<int>(M, -1));
    queue<pair<int, int>> walls;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j] - '0';
            if (grid[i][j] == 1) walls.push({i, j});
        }
    }

    BFS(before, 0, 0); // (0,0)부터 (N-1, M-1)까지
    BFS(after, N - 1, M - 1); // (N-1, M-1)부터 (0, 0)까지

    result = before[N - 1][M - 1]; // 초기값 :00부터의 값 기준
    while (!walls.empty()) { // 모든 벽 체크
        int minBefore = -1, minAfter = -1; // 초기값 : -1
        int cy = walls.front().Y;
        int cx = walls.front().X;
        walls.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (before[ny][nx] > 0) { // (0, 0)에서 (ny, nx)까지 이동할 수 있다면
                if (minBefore == -1) minBefore = before[ny][nx];
                else minBefore = min(minBefore, before[ny][nx]);
            }
            
            if (after[ny][nx] > 0) { // (N-1, M-1)에서 (ny, nx)까지 이동할 수 있다면
                if (minAfter == -1) minAfter = after[ny][nx];
                else minAfter = min(minAfter, after[ny][nx]);
            }            
        }

        if (minAfter != -1 && minBefore != -1) { // 양쪽으로 다 이동 가능하다면
            if (result == -1) result = minBefore + minAfter + 1;
            else result = min(result, minBefore + minAfter + 1);
        }
    }
    cout << result;
    return 0;
}
