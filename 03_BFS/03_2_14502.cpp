#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int N, M;
int safeArea, maxSafeArea = 0;
vector<vector<int>> lab, tmpLab;
vector<pair<int, int>> room, viruses;
queue<pair<int, int>> q;

void BFS() {
    tmpLab = lab;
    for (auto& virus : viruses) q.push(virus);

    while (!q.empty()) {
        int cy = q.front().Y;
        int cx = q.front().X;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(tmpLab[ny][nx] != 0) continue;
            tmpLab[ny][nx] = 2;
            q.push({ny, nx});
        }
    }

    safeArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmpLab[i][j] == 0) safeArea++;
        }
    }
    maxSafeArea = max(maxSafeArea, safeArea);
}

void SetWalls(int count, int start) { 
    if (count == 3) {
        BFS();
        return;
    }

    for (int i = start; i < room.size(); i++) {
        int cy = room[i].Y;
        int cx = room[i].X;
        lab[cy][cx] = 1;
        SetWalls(count + 1, i + 1);
        lab[cy][cx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    lab.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) room.push_back({ i, j });
            else if (lab[i][j] == 2) viruses.push_back({ i, j });
        }
    }
    SetWalls(0, 0);
    cout << maxSafeArea << "\n";
    return 0;
}