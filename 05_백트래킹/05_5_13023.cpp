/* [풀이]
1. 서로가 연결된 백트래킹 문제. 다음 이동을 link로 하면 일반 백트래킹과 동일하다.
2. 방문 여부를 표시하고, 다음 사람으로 넘어간다.
이미 방문한 사람이라면 취소하고, 방문하지 않은 사람이면 표시 후 다음으로 넘어간다.
3. 5명을 넘겼다면 성공, 넘긴 적이 한 번도 없다면 실패이다.
*/
#include <bits/stdc++.h>
using namespace std;

bool isFin = false;
int N, M, cnt = 0;
vector<bool> isVisited; // 방문 여부 확인
vector<vector<int>> linked; // 해당 인물이 어떤 친구들과 연결되어 있는지 확인

void BackTracking(int a) { // 백트래킹으로 총 5명이 연결되는지 확인
	if (isFin) return; // 이미 끝났다면 종료
	if (isVisited[a]) return;
	isVisited[a] = true; // 방문 여부 추가
	cnt++; // 갯수 늘리기
	if (cnt == 5) isFin = true; // 5명 연결되었으면 종료 가능

	for (int i : linked[a]) {
		BackTracking(i);
	}
	isVisited[a] = false; // 방문 취소
	cnt--; // 갯수 줄이기
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