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
		linked[a].push_back(b); // 서로에게 추가
		linked[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++) {
		BackTracking(i); // 0번부터 N-1번까지 백트래킹 시도
	}
	
	if (isFin) cout << "1"; // 성공 : 1 출력
	else cout << "0"; // 실패 : 0 출력

	return 0;
}