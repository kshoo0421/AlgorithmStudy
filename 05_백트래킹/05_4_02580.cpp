/* [풀이]
1. 빈칸 모두를 한 번에 채워야 함. 
그러므로 빈 칸을 모두 vector에 넣고 백트래킹 시도
2. 각 칸에 가능한 숫자를 확인하고, 넣을 수 있다면 다른 빈 칸 채우기 시도
3. 모두 다 채워졌다면 종료
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

vector<vector<int>> grid(9, vector<int>(9)); // 스도쿠판
vector<pair<int, int>> blanks; // 빈 칸 좌료

bool IsValid(int y, int x, int num) { // 이 위치에 해당 숫자가 가능한지 여부 확인
    for (int i = 0; i < 9; i++) { // 가로/세로 줄 중에
        if (grid[y][i] == num || grid[i][x] == num) { // 이 숫자가 있다면
            return false; // 이 숫자 불가
        }
    }

    y = (y / 3) * 3; // 이 3x3칸의 y 시작 지점
    x = (x / 3) * 3; // 이 3x3칸의 x 시작 지점
    for (int cy = y; cy < y + 3; cy++) { // 3칸씩 이동
        for (int cx = x; cx < x + 3; cx++) { // 3칸씩 이동
            if (grid[cy][cx] == num) { // 이미 원하는 숫자가 있다면
                return false; // 이 숫자 불가
            }
        }
    }
    return true;    // 통과
}

bool BackTracking(int idx) { // 빈 칸 백트래킹
    if (idx == blanks.size()) { // 모든 칸에 맞는 숫자를 찾았다면
        return true; // 성공
    }
    int cy = blanks[idx].Y; // 빈 칸의 y 좌표
    int cx = blanks[idx].X; // 빈 칸의 x 좌료

    for (int num = 1; num <= 9; num++) {
        if (IsValid(cy, cx, num)) {
            grid[cy][cx] = num;
            if (BackTracking(idx + 1)) {
                return true;
            }
            grid[cy][cx] = 0;
        }
    }
    return false; // 실패
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
    for (int i = 0; i < 9; i++) { // 출력
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}