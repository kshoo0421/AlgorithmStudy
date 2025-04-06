#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

vector<vector<int>> grid(9, vector<int>(9));
vector<pair<int, int>> blanks;

bool IsValid(int y, int x, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[y][i] == num || grid[i][x] == num) {
            return false;
        }
    }

    y = (y / 3) * 3;
    x = (x / 3) * 3;
    for (int cy = y; cy < y + 3; cy++) {
        for (int cx = x; cx < x + 3; cx++) {
            if (grid[cy][cx] == num) {
                return false;
            }
        }
    }
    return true;
}

bool BackTracking(int idx) {
    if (idx == blanks.size()) {
        return true;
    }
    int cy = blanks[idx].Y;
    int cx = blanks[idx].X;

    for (int num = 1; num <= 9; num++) {
        if (IsValid(cy, cx, num)) {
            grid[cy][cx] = num;
            if (BackTracking(idx + 1)) {
                return true;
            }
            grid[cy][cx] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                blanks.push_back({ i, j });
            }
        }
    }
    BackTracking(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}