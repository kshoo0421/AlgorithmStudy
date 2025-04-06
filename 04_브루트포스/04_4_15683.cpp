#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int N, M;
vector<vector<int>> grid;
vector<vector<int>> isVisited;
vector<pair<int, int>> cctv;

int minimum;

void FillLine(int idx, int dir, bool isActive) {
    int cy = cctv[idx].Y;
    int cx = cctv[idx].X;
    
    while(1) {
        cy += dy[dir];
        cx += dx[dir];
        if(cy < 0 || cy >= N || cx < 0 || cx >= M) break;
        if(grid[cy][cx] == 6) break;
        isVisited[cy][cx] += (isActive ? 1 : -1);
    }
}

void CheckCCTV(int idx) {
    if(idx == cctv.size()) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!isVisited[i][j]) cnt++;
            }
        }
        if(cnt < minimum) minimum = cnt;
        return;
    }

    switch(grid[cctv[idx].Y][cctv[idx].X]) {
    case 1:
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true);
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
        }
        break;
    case 2: // 2번 카메라
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true);
            FillLine(idx, (i + 2) % 4, true);
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
            FillLine(idx, (i + 2) % 4, false);
        }
        break;
    case 3:
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true);
            FillLine(idx, (i + 1) % 4, true);
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
            FillLine(idx, (i + 1) % 4, false);
        }
        break;
    case 4:
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true);
            FillLine(idx, (i + 1) % 4, true);
            FillLine(idx, (i + 2) % 4, true);
            CheckCCTV(idx + 1);
            FillLine(idx, i, false);
            FillLine(idx, (i + 1) % 4, false);
            FillLine(idx, (i + 2) % 4, false);
        }
        break;
    case 5: 
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, true);
        }        
        CheckCCTV(idx + 1);
        for(int i = 0; i < 4; i++) {
            FillLine(idx, i, false);
        }        
        break;
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    minimum = N * M;

    grid.assign(N, vector<int>(M));
    isVisited.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= 1 && grid[i][j] <= 5) cctv.push_back({i, j});
            if(grid[i][j] >= 1) isVisited[i][j]++;
        }
    }
    CheckCCTV(0);
    cout << minimum;
}