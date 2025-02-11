#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<vector<int>> grid(9, vector<int>(9, 0));

vector<pair<int, int>> blanks;

bool IsValid(int x, int y, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[x][i] == num || grid[i][y] == num) {
            return false;
        }
    }

    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (grid[i][j] == num) {
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
    int x = blanks[idx].X;
    int y = blanks[idx].Y;

    for (int num = 1; num <= 9; num++) {
        if (IsValid(x, y, num)) {
            grid[x][y] = num;
            if (BackTracking(idx + 1)) {
                return true;
            }
            grid[x][y] = 0;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<string> input(9);
    for(auto& s : input) cin >> s;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            grid[i][j] = input[i][j] - '0';
            if(grid[i][j] == 0) blanks.push_back({i, j});
        }
    }

    BackTracking(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}