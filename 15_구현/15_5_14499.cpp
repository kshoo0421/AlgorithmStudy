#include <bits/stdc++.h>
#define UP 0
#define FRONT 1
#define DOWN 2
#define BACK 3
#define LEFT 4
#define RIGHT 5
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
using namespace std;

int dice[6] = { 0, 0, 0, 0, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void Move(int dir) {
    int tmp = dice[DOWN];
    switch (dir) {
    case NORTH:
        dice[DOWN] = dice[BACK];
        dice[BACK] = dice[UP];
        dice[UP] = dice[FRONT];
        dice[FRONT] = tmp;
        break;
    case EAST:
        dice[DOWN] = dice[RIGHT];
        dice[RIGHT] = dice[UP];
        dice[UP] = dice[LEFT];
        dice[LEFT] = tmp;
        break;
    case WEST:
        dice[DOWN] = dice[LEFT];
        dice[LEFT] = dice[UP];
        dice[UP] = dice[RIGHT];
        dice[RIGHT] = tmp;
        break;
    case SOUTH:
        dice[DOWN] = dice[FRONT];
        dice[FRONT] = dice[UP];
        dice[UP] = dice[BACK];
        dice[BACK] = tmp;
        break;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, cx, cy, K;
    cin >> N >> M >> cy >> cx >> K;
    vector<vector<int>> grid(N, vector<int>(M));
    for (auto& vi : grid) {
        for (int& i : vi) cin >> i;
    }
    int cmd;
    if (grid[cy][cx] != 0) {
        dice[DOWN] = grid[cy][cx];
        grid[cy][cx] = 0;
    }
    while (K--) {
        cin >> cmd;
        int ny = cy + dy[cmd];
        int nx = cx + dx[cmd];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        Move(cmd);
        cout << dice[UP] << "\n";
        cy = ny, cx = nx;
        if (grid[cy][cx] != 0) {
            dice[DOWN] = grid[cy][cx];
            grid[cy][cx] = 0;
        }
        else grid[cy][cx] = dice[DOWN];
    }
}