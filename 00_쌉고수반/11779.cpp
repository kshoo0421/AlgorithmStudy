#include <bits/stdc++.h>
#define NEXT first
#define DIST second
#define MAX 2000000000
using namespace std;

int N, M, S, E, T;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<vector<pair<int, int>>> next(N + 1, vector<pair<int, int>>());
    for(int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        next[S].push_back({E, T});
    }
    cin >> S >> E;
    vector<bool> isVisited(N + 1, false);
    vector<int> dist(N + 1, MAX);
    vector<vector<int>> route(N + 1);

    auto cmp = [&](int i1, int i2) { return dist[i1] < dist[i2];};
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(S);
    dist[S] = 0;
    route[S].push_back(S);

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if(isVisited[cur]) continue;
        isVisited[cur] = true;
        for(auto pii : next[cur]) {
            if(dist[pii.NEXT] > dist[cur] + pii.DIST) {
                int n = pii.NEXT;
                dist[n] = dist[cur] + pii.DIST;
                isVisited[n] = false;
                route[n] = route[cur];
                route[n].push_back(n);
                pq.push(n);
            }
        }
    }
    cout << dist[E] << "\n";
    cout << route[E].size() << "\n";
    for(int i : route[E]) cout << i << " "; 
}