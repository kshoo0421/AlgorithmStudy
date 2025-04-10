#include <bits/stdc++.h>
#define INF (1e9 + 10)
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int V, E, st;
	cin >> V >> E >> st;
	vector<int> dist(V + 1, INF);
	vector<vector<pair<int, int>>> next(V + 1);
	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		next[u].push_back({ v, w });
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({ 0, st });
	while (!pq.empty()) {
		auto [curDist, A] = pq.top();
		pq.pop();
		if (dist[A] != curDist) continue;
		for (auto [B, w] : next[A]) {
			if (dist[B] <= dist[A] + w) continue;
			dist[B] = dist[A] + w;
			pq.push({ dist[B], B });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}