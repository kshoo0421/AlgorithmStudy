#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, cx, cy, nx, ny, safeArea, maxSafeArea = 0;
vector<vector<int>> lab, tmpLab;
vector<pair<int, int>> room, viruses;
queue<pair<int, int>> q;

void bfs() {
    tmpLab = lab;
    for (auto virus : viruses) q.push(virus);

    while (!q.empty()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && tmpLab[ny][nx] == 0) {
                tmpLab[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }
    safeArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmpLab[i][j] == 0) safeArea++;
        }
    }
    maxSafeArea = max(maxSafeArea, safeArea);
}

void setWalls(int count, int start) {
    if (count == 3) {
        bfs();
        return;
    }

    for (int i = start; i < room.size(); i++) {
        int y = room[i].first;
        int x = room[i].second;
        lab[y][x] = 1;
        setWalls(count + 1, i + 1);
        lab[y][x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    lab.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) room.push_back({ i, j });
            else if (lab[i][j] == 2) viruses.push_back({ i, j });
        }
    }
    setWalls(0, 0);
    cout << maxSafeArea << "\n";
    return 0;
}