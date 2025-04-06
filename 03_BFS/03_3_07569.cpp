#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    queue<vector<int>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) q.push({ i, j, k });
            }
        }
    }

    int days = 0;
    while (!q.empty()) {
        int size = q.size();
        bool ripened = false;

        for (int i = 0; i < size; i++) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 6; j++) {
                int nz = cur[0] + dz[j];
                int ny = cur[1] + dy[j];
                int nx = cur[2] + dx[j];
                if(nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    q.push(vector<int>({ nz, ny, nx }));
                    ripened = true;
                }
            }
        }
        if (ripened) days++;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    cout << days << "\n";
    return 0;
}