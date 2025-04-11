#include <bits/stdc++.h>
#define MAX 1e9
#define LL long long
using namespace std;

int N, M;
vector<tuple<LL, LL, LL>> edges;
vector<LL> dist;

bool BellmanFord(int start) {
    dist.assign(N, MAX);
    dist[start] = 0;

    for(int i = 0; i < N; i++) {
        for(auto& [u, v, w] : edges) {
            if(dist[u] != MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            } 
        }
    }

    for(auto& [u, v, w] : edges) {
        if(dist[u] != MAX && dist[v] > dist[u] + w) {
            return false;
        } 
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    edges.resize(M);
    for(auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
        u--, v--;
    }

    if(BellmanFord(0)) {
        for(int i = 1; i < N; i++) {
            if(dist[i] == MAX) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    } 
    else cout << "-1\n";
}