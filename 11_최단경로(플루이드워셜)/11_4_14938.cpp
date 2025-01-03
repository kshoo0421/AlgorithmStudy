#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> item(n);
	for (int& i : item) cin >> i;

	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	while (r--) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a - 1][b - 1] = min(dist[a - 1][b - 1], l);
		dist[b - 1][a - 1] = min(dist[b - 1][a - 1], l);
	}

	function<void()> Floyd = [&]() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	};

	Floyd();
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (dist[i][j] <= m) {
				cnt += item[j];
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer;
}