#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, E;
	cin >> N >> E;
	vector<vector<pair<int, int>>> next(N + 1);
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		next[a].push_back({ b, c });
		next[b].push_back({ a, c });
	}
	int v1, v2;
	cin >> v1 >> v2;

	auto Dijkstra = [&](int start, int end) {
		vector<int> dist(N + 1, MAX);
		dist[start] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });
		
		while (!pq.empty()) {
			auto [cDist, cPos] = pq.top();
			pq.pop();
			if (dist[cPos] != cDist) continue;
			if (cPos == end) break;
			for (auto [nPos, weight] : next[cPos]) {
				if (cDist + weight < dist[nPos]) {
					dist[nPos] = cDist + weight;
					pq.push({ dist[nPos], nPos });
				}
			}
		}
		return dist[end];
		};

	int _v1 = Dijkstra(1, v1);
	int _v2 = Dijkstra(1, v2);
	int v1_v2 = Dijkstra(v1, v2);
	int v1_N = Dijkstra(v1, N);
	int v2_N = Dijkstra(v2, N);

	if (_v1 == MAX || _v2 == MAX || v1_v2 == MAX || v1_N == MAX || v2_N == MAX) {
		cout << "-1";
	}
	else {
		int v1_v2_N = _v1 + v1_v2 + v2_N;
		int v2_v1_N = _v2 + v1_v2 + v1_N;
		cout << min(v1_v2_N, v2_v1_N);
	}
}