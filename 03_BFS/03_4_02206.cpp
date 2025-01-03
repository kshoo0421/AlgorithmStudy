#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M, cx, cy, nx, ny, result;
vector<vector<int>> nm_map;

void bfs(vector<vector<int>>& vvi, int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    vvi[y][x] = 1;
    while (!q.empty()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (nm_map[ny][nx] != 1)
                    if(vvi[ny][nx] > vvi[cy][cx] + 1 || vvi[ny][nx] == -1) {
                    vvi[ny][nx] = vvi[cy][cx] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> N >> M;
    nm_map.assign(N, vector<int>(M));
    vector<vector<int>> before(N, vector<int>(M, -1)), after(N, vector<int>(M, -1));
    queue<pair<int, int>> walls;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            nm_map[i][j] = s[j] - '0';
            if (nm_map[i][j] == 1) walls.push(make_pair(i, j));
        }
    }

    bfs(before, 0, 0);
    bfs(after, N - 1, M - 1);

    result = before[N - 1][M - 1];
    while (!walls.empty()) {
        int min_bef = -1, min_aft = -1;
        cy = walls.front().first;
        cx = walls.front().second;
        walls.pop();
        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (before[ny][nx] > 0) {
                    if (min_bef == -1) min_bef= before[ny][nx];
                    else min_bef = min(min_bef, before[ny][nx]);
                }
                
                if (after[ny][nx] > 0) {
                    if (min_aft == -1) min_aft = after[ny][nx];
                    else min_aft = min(min_aft, after[ny][nx]);
                }
            }
        }

        if (min_aft != -1 && min_bef != -1) {
            if (result == -1) result = min_bef + min_aft + 1;
            else result = min(result, min_bef + min_aft + 1);
        }
    }

    cout << result;
    return 0;
}
