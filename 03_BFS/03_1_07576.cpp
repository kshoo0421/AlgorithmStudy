#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
    int m, n, total = 0, done = 0, days = -1, size, ny, nx;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({ i, j });
                done++;
            }
            if (box[i][j] != -1) total++;
        }
    }

    if (done == total) {
        cout << "0\n";
        return 0;
    }

    while (!q.empty()) {
        size = q.size();
        days++;
        for (int i = 0; i < size; i++) {
            auto cycx = q.front(); 
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                ny = cycx.first + dy[dir];
                nx = cycx.second + dx[dir];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && box[ny][nx] == 0) {
                    box[ny][nx] = 1;
                    q.push({ ny, nx });
                    done++;
                }
            }
        }
    }

    if (done == total) cout << days << endl;
    else cout << "-1\n";
    return 0;
}