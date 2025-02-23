#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N;
vector<vector<int>> grid, dp;

int DFS(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x]; 

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (grid[ny][nx] <= grid[y][x]) continue;

        dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);
    }

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    grid.assign(N, vector<int>(N));
    dp.assign(N, vector<int>(N, -1));

    for (auto& vi : grid) {
        for (int& i : vi) cin >> i;
    }

    int answer = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            answer = max(answer, DFS(y, x));
        }
    }

    cout << answer;
}