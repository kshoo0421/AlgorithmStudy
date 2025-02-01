#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> dist(N, vector<int>(N, MAX));
	for (int i = 0; i < N; i++) dist[i][i] = 0;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		a--, b--;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	vector<int> minDist(N);
	for (int i = 0; i < N; i++) {
		minDist[i] = *max_element(dist[i].begin(), dist[i].end());
	}	
	int curDist = *min_element(minDist.begin(), minDist.end());

	vector<int> answer;
	for (int i = 0; i < N; i++) {
		if (curDist == minDist[i]) {
			answer.push_back(i + 1);
		}
	}

	cout << curDist << " " << answer.size() << "\n";
	for (int i : answer) cout << i << " ";
}