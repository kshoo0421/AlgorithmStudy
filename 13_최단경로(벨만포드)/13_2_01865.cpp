#include <bits/stdc++.h>
#define MAX 2000000000
using namespace std;

bool DetectCycle(int N, vector<tuple<int, int, int>>& edges) {
    vector<int> nodes(N, MAX);
    nodes[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (auto [s, e, dist] : edges) {
            if (nodes[e] > nodes[s] + dist) {
                nodes[e] = nodes[s] + dist;
            }
        }
    }
    for (auto [s, e, dist] : edges) {
        if (nodes[e] > nodes[s] + dist) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<tuple<int, int, int>> edges;
        int S, E, T;
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            S--, E--;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            S--, E--;
            edges.push_back({S, E, -1 * T});
        }

        if (DetectCycle(N, edges)) cout << "YES\n";
        else cout << "NO\n";
    }
}