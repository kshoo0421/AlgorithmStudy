#include <bits/stdc++.h>
#define NODE first
#define DIST second
using namespace std;

vector<vector<pair<int, int>>> tree;
int n;

pair<int, int> DFS(int node, int parent) {
    int maxDist = 0;
    int farthestNode = node;

    for (auto [next, weight] : tree[node]) {
        if (next == parent) continue;
        auto [childFarthestNode, dist] = DFS(next, node);
        dist += weight;
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = childFarthestNode;
        }
    }
    return {farthestNode, maxDist};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    tree.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }

    pair<int, int> farthest = DFS(1, -1);
    pair<int, int> diameter = DFS(farthest.NODE, -1);
    cout << diameter.DIST;
}