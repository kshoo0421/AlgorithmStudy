/* [풀이]
1. 이분 그래프 : 같은 그룹끼리는 연결되면 안되는 그래프
=> 색이 A인 노드와 연결된 모든 노드는 색이 B여야 함.
- 종류 : 안칠함(-1) / A(0) / B(1)
2. DFS를 통해 탐색
*/

#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<vector<int>> linked;

// 이분 그래프인지 탐색하는 함수
bool IsBiGraph() 
{
	vector<int> color(V, -1); // -1 : 색이 안칠해짐 / 0 : 색 A / 1 : 색 B
	for (int i = 0; i < V; i++) {
		if (color[i] == -1) { // 색이 칠해지지 않았다면
			stack<int> stk;
			stk.push(i);
			color[i] = 0; // 시작 색 : 0 
			
			// DFS : 한 칸씩 확인하며, 다음 칸은 현재와 반대되는 색을 칠함,(0 <-> 1)
			while (!stk.empty()) {
				int cur = stk.top();
				stk.pop();
				for (int next : linked[cur]) {
					if (color[next] == -1) { // 색이 안칠해졌다면
						color[next] = 1 - color[cur]; // 현재와는 다른 색으로
						stk.push(next); // 다음 칸 탐색
					} 
					// 현재 색과 다음 색이 같다면 이분 그래프가 아님
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
			linked[u].push_back(v);#include <bits/stdc++.h>
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
			u--, v--;
			linked[u].push_back(v);
			linked[v].push_back(u);
		}
		if (IsBiGraph()) cout << "YES\n";
		else cout << "NO\n";
	}
}
			linked[v].push_back(u);
		}
		if (IsBiGraph()) cout << "YES\n";
		else cout << "NO\n";
	}
}