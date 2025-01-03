#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int V, E;
	cin >> V >> E;
	vector<vector<int>> edges(E, vector<int>(3));
	for (auto& edge : edges) cin >> edge[0] >> edge[1] >> edge[2];

	vector<int> parent(V + 1), rank(V + 1, 0);
	for (int i = 1; i <= V; i++) parent[i] = i;
	
	function<int(int)> FindParent = [&](int a) -> int {
		if (a == parent[a]) return a;
		return parent[a] = FindParent(parent[a]);
	};

	function<void(int, int)> SetUnion = [&](int x, int y) -> void {
		int rootX = FindParent(x);
		int rootY = FindParent(y);

		if (rootX != rootY) {
			if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
			else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	};

	sort(edges.begin(), edges.end(), [](vector<int>& v1, vector<int>& v2) {
		return v1[2] < v2[2];
	});

	int answer = 0;
	for (auto& vi : edges) {
		int x = vi[0], y = vi[1], cost = vi[2];
		if (FindParent(x) != FindParent(y)) {
			SetUnion(x, y);
			answer += cost;
		}
	}
	cout << answer;
}