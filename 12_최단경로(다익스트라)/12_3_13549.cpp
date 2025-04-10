#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<bool> isVisited(100001, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });
	while (!pq.empty()) {
		auto [time, cur] = pq.top();
		pq.pop();
		if (isVisited[cur]) continue;
		isVisited[cur] = true;
		if (cur == K) {
			cout << time;
			return 0;
		}
		if (cur + 1 <= 100000) pq.push({ time + 1, cur + 1 });
		if (cur - 1 >= 0) pq.push({ time + 1, cur - 1 });
		if (cur * 2 <= 100000) pq.push({ time, cur * 2 });
	}
}