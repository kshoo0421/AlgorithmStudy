#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<vector<int>> linked;

bool IsBiGraph() 
{
	vector<int> color(V, -1);
	for (int i = 0; i < V; i++) {
		if (color[i] == -1) {
			stack<int> stk;
			stk.push(i);
			color[i] = 0; 
			
			while (!stk.empty()) {
				int cur = stk.top();
				stk.pop();
				for (int next : linked[cur]) {
					if (color[next] == -1) {
						color[next] = 1 - color[cur];
						stk.push(next);
					}
					else if (color[next] == color[cur]) return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> K;
	while (K--) {
		cin >> V >> E;
		linked.assign(V + 1, vector<int>());
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--; // 1 ~ V => 0 ~ V-1
			linked[u].push_back(v);
			linked[v].push_back(u);
		}
		if (IsBiGraph()) cout << "YES\n";
		else cout << "NO\n";
	}
}