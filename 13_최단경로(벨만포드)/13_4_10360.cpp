#include <bits/stdc++.h>
#define LL long long
#define INF (1LL << 60)
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    for (int cnt = 1; cnt <= T; cnt++) {
        int N, M;
        cin >> N >> M;
        vector<tuple<int, int, int>> edges;
        vector<vector<int>> rev(N);
        for (int i = 0; i < M; i++) {
            int A, B, C;
            cin >> A >> B >> C;
            edges.push_back({ A, B, C });
            rev[B].push_back(A);
        }

        vector<bool> revReachable(N, false);
        queue<int> q;
        q.push(0);
        revReachable[0] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int prev : rev[cur]) {
                if (!revReachable[prev]) {
                    revReachable[prev] = true;
                    q.push(prev);
                }
            }
        }

        vector<LL> dist(N, INF);
        dist[0] = 0;
        for (int i = 1; i < N; i++) {
            for (auto [u, v, w] : edges) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        bool checkNCycle = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                if (revReachable[v]) {
                    checkNCycle = true;
                    break;
                }
            }
        }

        cout << "Case #" << cnt << ": ";
        if (checkNCycle) cout << "possible\n";
        else cout << "not possible\n";
    }
}