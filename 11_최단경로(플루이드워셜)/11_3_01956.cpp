#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int V, E;
	cin >> V >> E;
	vector<vector<int>> dist(V, vector<int>(V, INF));
	
	for (int i = 0; i < V; i++) dist[i][i] = 0;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a - 1][b - 1] = c;
	}

	function<void()> Floyd = [&]() {
		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	};
	Floyd();

	int result = INF;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j || dist[i][j] == INF || dist[j][i] == INF) continue;
			result = min(result, dist[i][j] + dist[j][i]);
		}
	}
	if (result == INF) cout << "-1";
	else cout << result;
}