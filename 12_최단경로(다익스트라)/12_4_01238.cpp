#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

vector<int> Dijkstra(int start, int N, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(N + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [cDist, cPos] = pq.top();
        pq.pop();

        if (cDist > dist[cPos]) continue;

        for (auto [nDist, nPos] : graph[cPos]) {
            int cost = cDist + nDist;
            if (cost < dist[nPos]) {
                dist[nPos] = cost;
                pq.push({ cost, nPos });
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> fromGraph(N + 1);
    vector<vector<pair<int, int>>> toGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        fromGraph[u].push_back({ t, v });
        toGraph[v].push_back({ t, u });
    }

    vector<int> toX = Dijkstra(X, N, toGraph);
    vector<int> fromX = Dijkstra(X, N, fromGraph);

    int answer = 0;
    for (int i = 1; i <= N; i++) answer = max(answer, toX[i] + fromX[i]);
    cout << answer;
}
