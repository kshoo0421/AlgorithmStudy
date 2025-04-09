#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> item(N);
	for (int& i : item) cin >> i;

	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++) dist[i][i] = 0;
	while (R--) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a - 1][b - 1] = min(dist[a - 1][b - 1], l);
		dist[b - 1][a - 1] = min(dist[b - 1][a - 1], l);
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
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (dist[i][j] <= M) {
				cnt += item[j];
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer;
}