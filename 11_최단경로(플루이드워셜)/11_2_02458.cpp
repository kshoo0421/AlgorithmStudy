#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dist(N, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a - 1][b - 1] = 1;
	}

	function<void()> Floyd = [&]() {
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (dist[i][k] && dist[k][j]) {
						dist[i][j] = 1;
					}
				}
			}
		}
	};

	Floyd();

	int result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (dist[i][j] || dist[j][i]) cnt++;
		}
		if (cnt == N - 1) result++;
	}
	cout << result;
}