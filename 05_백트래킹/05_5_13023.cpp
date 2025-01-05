#include <bits/stdc++.h>
using namespace std;

bool isFin = false;
int N, M, cnt = 0;
vector<bool> isVisited;
vector<vector<int>> linked;

void BackTracking(int a) {
	if (isFin) return;
	if (isVisited[a]) return;
	isVisited[a] = true;
	cnt++;
	if (cnt == 5) isFin = true;

	for (int i : linked[a]) {
		BackTracking(i);
	}
	isVisited[a] = false;
	cnt--;
	return;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	isVisited.assign(N, false);
	linked.resize(N);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		linked[a].push_back(b);
		linked[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++) {
		BackTracking(i);
	}
	
	if (isFin) cout << "1";
	else cout << "0";

	return 0;
}