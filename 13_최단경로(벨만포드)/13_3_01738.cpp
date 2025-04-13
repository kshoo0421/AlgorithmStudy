#include <bits/stdc++.h>
#define MIN -1e9
using namespace std;

int N, M;
vector<tuple<int, int, int>> edges;
vector<int> answer;
vector<vector<int>> graph;  // 음수 사이클에서 도달 가능한지 확인하는 그래프

bool CanReachN(vector<int>& negCycle) {
    vector<bool> visited(N + 1, false);
    queue<int> q;

    for (int i : negCycle) {
        q.push(i);
        visited[i] = true;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == N) return true;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

bool BellmanFord() {
    vector<int> dist(N + 1, MIN);
    vector<int> before(N + 1, -1);
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != MIN && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                before[v] = u;
            }
        }
    }

    vector<int> negCycleNodes;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != MIN && dist[v] < dist[u] + w) {
            negCycleNodes.push_back(v);
        }
    }

    if ((!negCycleNodes.empty() && CanReachN(negCycleNodes))
        || dist[N] == MIN) {
        cout << -1;
        return false;
    }

    answer.push_back(N);
    int cur = before[N];
    while (cur != -1) {
        answer.push_back(cur);
        cur = before[cur];
    }
    reverse(answer.begin(), answer.end());

    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    edges.resize(M);
    graph.resize(N + 1);

    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
        graph[u].push_back(v);
    }

    if (BellmanFord()) {
        for (int i : answer) cout << i << " ";
    }
}
