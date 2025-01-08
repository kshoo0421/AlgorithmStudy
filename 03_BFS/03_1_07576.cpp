/* [풀이]
1. 전형적인 BFS + 날짜 개념
2. 확장을 하되, 날짜별로 확장되어야 하므로
while문에서 날짜 증가를 하고,
날짜별로 큐의 크기를 구해 그만큼 확장시킨다.
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int M, N;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    vector<vector<int>> grid(N, vector<int>(M));
    queue<pair<int, int>> q;

    int total = 0, done = 0, days = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({ i, j }); // 토마토는 위치를 큐에 넣기
                done++;
            }
            if (grid[i][j] != -1) total++;
        }
    }

    if (done == total) { // 이미 완료되었다면
        cout << "0\n";
        return 0; // 종료
    }

    while (!q.empty()) {
        days++; // 날짜 증가
        int size = q.size(); // 반복횟수 : 날짜 증가 시점의 큐의 크기
        for (int i = 0; i < size; i++) {
        // cf) 여기에 q.size()를 넣으면 계속 q.size()를 호출해서 반복 횟수가 달라질 수 있음.
            int cy = q.front().Y;
            int cx = q.front().X;
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // 범위 밖
                if(grid[ny][nx] != 0) continue; // 퍼질 수 없는 공간(있거나 막혀있거나)
                grid[ny][nx] = 1; // 토마토 추가
                q.push({ ny, nx });
                done++; // 토마토 갯수 증가
            }
        }
    }

    if (done == total) cout << days << "\n";
    else cout << "-1\n";
    return 0;
}