#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dist(N, vector<int>(N, INF));

	for (int i = 0; i < N; i++) dist[i][i] = 0;

	for (int i = 0; i < M; i++) {
		int U, B, W;
		cin >> U >> B >> W;
		dist[U-1][B-1] = min(dist[U-1][B-1], W);
	}

	function<void()> Floyd = [&]() {
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	};

	Floyd();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}