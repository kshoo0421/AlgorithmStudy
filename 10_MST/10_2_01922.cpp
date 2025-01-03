#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> links(M, vector<int>(3));
	for (auto& vi : links) cin >> vi[0] >> vi[1] >> vi[2];

	vector<int> parent(N + 1, 0), rank(N + 1, 0);
	for (int i = 1; i <= N; i++) parent[i] = i;
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

	sort(links.begin(), links.end(), [](vector<int>& v1, vector<int>& v2) {
		return v1[2] < v2[2];
	});

	int answer = 0;
	for (auto& vi : links) {
		int x = vi[0], y = vi[1], cost = vi[2];
		if (FindParent(x) != FindParent(y)) {
			SetUnion(x, y);
			answer += cost;
		}
	}
	cout << answer;
}