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
                q.push({ i, j });
                done++;
            }
            if (grid[i][j] != -1) total++;
        }
    }

    if (done == total) {
        cout << "0\n";
        return 0;
    }

    while (!q.empty()) {
        days++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cy = q.front().Y;
            int cx = q.front().X;
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(grid[ny][nx] != 0) continue;
                grid[ny][nx] = 1;
                q.push({ ny, nx });
                done++;
            }
        }
    }

    if (done == total) cout << days << "\n";
    else cout << "-1\n";
    return 0;
}