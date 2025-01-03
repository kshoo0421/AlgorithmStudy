#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int space[9][9];
vector<pair<int, int>> blanks;

bool IsValid(int x, int y, int num) {
    // 라인
    for (int i = 0; i < 9; i++) {
        if (space[x][i] == num || space[i][y] == num) {
            return false;
        }
    }

    // 33
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (space[i][j] == num) {
                return false;
            }
        }
    }

    // 통과
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
            space[x][y] = num;
            if (BackTracking(idx + 1)) {
                return true;
            }
            space[x][y] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> space[i][j];
            if (space[i][j] == 0) {
                blanks.push_back({ i, j });
            }
        }
    }
    BackTracking(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << space[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}