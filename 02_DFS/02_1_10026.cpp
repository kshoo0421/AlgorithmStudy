#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int N;
vector<string> grid;
vector<vector<bool>> visited; 

void DFS(int y, int x, char color, bool isBlind) {
    stack<pair<int, int>> stk;
    stk.push({ y, x });
    visited[y][x] = true;

    while (!stk.empty()) {
        int cy = stk.top().Y;
        int cx = stk.top().X;
        stk.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {
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

int GetCnt(bool isBlind) {
    visited.assign(N, vector<bool>(N, false));
    int regions = 0;
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