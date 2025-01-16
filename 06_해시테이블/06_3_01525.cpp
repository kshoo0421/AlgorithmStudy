/* [풀이]
1. 경로를 string으로 바꿔서 저장 후 unordered_set으로 중복 제거
2. BFS로 하나씩 탐색. 최종 목표에 도달하면 종료
*/

#include <bits/stdc++.h>
#define STR first
#define CNT second
using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

string goal = "123456780";

int BFS(string start) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        string curGrid = q.front().STR;
        int cnt = q.front().CNT;
        q.pop();

        if (curGrid == goal) return cnt;

        int curZero = curGrid.find('0');
        int cy = curZero / 3;
        int cx = curZero % 3;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dx[i];
            int nx = cx + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            int nextZero = ny * 3 + nx;
            string nextGrid = curGrid;
            swap(nextGrid[curZero], nextGrid[nextZero]);
            if (visited.find(nextGrid) == visited.end()) {
                visited.insert(nextGrid);
                q.push({nextGrid, cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string start = "";
    for(int i = 0; i < 9; i++) {
        int num;
        cin >> num;
        start += to_string(num);
    }
    cout << BFS(start) << '\n';
}
