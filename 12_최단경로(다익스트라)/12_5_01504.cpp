#include <bits/stdc++.h>
#define MAX 2000000000
using namespace std;

int N, E;
vector<vector<int>> dist;

int shortestPath(int start, int dest) {
	if (start == dest) return 0;
	int cur = start, minVal, minPos;
	vector<int> path(N, MAX);
	vector<int> done(1, start);
	path[start] = 0;

	while (1) {
		minVal = MAX;
		minPos = -1;
		for (int i : done) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (path[j] == MAX && path[i] + dist[i][j] < minVal) {
					minVal = path[i] + dist[i][j];
					minPos = j;
				}
			}
		}
		if (minPos == -1) return MAX;
		path[minPos] = minVal;
		done.emplace_back(minPos);
		if (minPos == dest) break;
	}
	return path[dest];
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b, c, v1, v2, result = 0;
	cin >> N >> E;
	dist.assign(N, vector<int>(N, MAX));
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a - 1][b - 1] = c;
		dist[b - 1][a - 1] = c;
	}	
	cin >> v1 >> v2;
	int sToV1 = shortestPath(0, v1 - 1);
	int sToV2 = shortestPath(0, v2 - 1);
	int v1ToV2 = shortestPath(v1 - 1, v2 - 1);
	int v1ToE = shortestPath(v1 - 1, N - 1);
	int v2ToE = shortestPath(v2 - 1, N - 1);
	result = v1ToV2 + min(sToV1 + v2ToE, sToV2 + v1ToE);
	if (sToV1 == MAX || sToV2 == MAX || v1ToV2 == MAX || v1ToE == MAX || v2ToE == MAX) result = -1;
	cout << result;
}