#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;

bool IsBiGraph(int v) 
{
	vector<int> color(v + 1, -1);
	for (int i = 1; i <= v; i++) {
		if (color[i] == -1) {
			queue<int> q;
			q.push(i);
			color[i] = 0;

			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : graph[u]) {
					if (color[v] == -1) {
						color[v] = 1 - color[u]; 
						q.push(v);
					} 
					else if (color[v] == color[u]) return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int K, V, E, u, v;
	cin >> K;

	while (K--) {
		cin >> V >> E;
		graph.assign(V + 1, vector<int>());
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		if (IsBiGraph(V)) cout << "YES\n";
		else cout << "NO\n";
	}
}