/* [풀이]
1. 정석적인 MST. 유니온 파인드를 활용한 크루스칼 알고리즘 구현
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ranks;
vector<vector<int>> edges;

int FindParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = FindParent(parent[a]);
}

void SetUnion(int x, int y) {
	int rootX = FindParent(x);
	int rootY = FindParent(y);

	if (rootX != rootY) {
		if (ranks[rootX] < ranks[rootY]) parent[rootX] = rootY;
		else if (ranks[rootX] > ranks[rootY]) parent[rootY] = rootX;
		else {
			parent[rootY] = rootX;
			ranks[rootX]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int V, E;
	cin >> V >> E;
	edges.assign(E, vector<int>(3));
	for (auto& edge : edges) cin >> edge[0] >> edge[1] >> edge[2];

	parent.resize(V + 1);
	ranks.assign(V + 1, 0);
	for (int i = 1; i <= V; i++) parent[i] = i;

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