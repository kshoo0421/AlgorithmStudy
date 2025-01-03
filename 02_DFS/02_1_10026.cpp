#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, cx, cy, nx, ny;
vector<string> grid;
vector<vector<bool>> visited;

void dfs(int x, int y, char color, bool isBlind) {
    stack<pair<int, int>> stk;
    stk.push({ x, y });
    visited[x][y] = true;

    while (!stk.empty()) {
        cy = stk.top().first;
        cx = stk.top().second;
        stk.pop();
        for (int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx]) {
                if (isBlind) {
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
                else {
                    if (grid[ny][nx] == color) {
                        visited[ny][nx] = true;
                        stk.push({ ny, nx });
                    }
                }
            }
        }
    }
}

int getCnt(bool isBlind) {
    visited.assign(n, vector<bool>(n, false));
    int regions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                regions++;
                dfs(i, j, grid[i][j], isBlind);
            }
        }
    }
    return regions;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    cout << getCnt(false) << " " << getCnt(true);
    return 0;
}