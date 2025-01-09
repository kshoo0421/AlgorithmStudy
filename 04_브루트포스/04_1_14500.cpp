/* [풀이]
1. 모든 경우의 수를 다 찾아야한다.
2. 한 칸씩 확장해서 4칸이 될 때의 합을 확인(ㅡ, ㅣ, ㄴ, ㄱ, ㅁ)
3. 그 외 모양 확인(ㅏ, ㅗ, ㅓ, ㅜ)
4. 모든 칸 확인 후 그 중 가장 큰 값 확인
*/

#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;
int N, M, mx = 0;
vector<vector<int>> space;
vector<pair<int, int>> tetris;

void FindMax(int y, int x, int idx) { // 현재 위치(y, x). 몇 번째 칸인지 확인(0~3)
	if (y < 0 || y >= N || x < 0 || x >= M) return; // 범위 밖
	for (auto pii : tetris) if (pii.Y == y && pii.X == x) return; // 이미 탐색한 칸이면 탈출

	tetris.push_back({ y, x }); // 현재 칸 추가
	if (idx == 3) { // 4칸째
		int sum = 0; // 전체 합 계산
		for (auto vii : tetris) sum += space[vii.Y][vii.X]; 
		if (sum > mx) mx = sum; // 최대치보다 크면 최대치 없데이트
	}
	else {
		FindMax(y + 1, x, idx + 1); // 상
		FindMax(y - 1, x, idx + 1); // 하
		FindMax(y, x + 1, idx + 1); // 좌
		FindMax(y, x - 1, idx + 1); // 우
	}
	tetris.pop_back(); // 현재 칸 제거
}

void FindTValue(int y, int x) {
	if ((y == 0 || y == N - 1) && (x == 0 || x == M - 1)) return;
	int sum = 0;
	if (y == 0) sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y + 1][x]; // ㅜ
	else if (x == 0) sum = space[y][x] + space[y - 1][x] + space[y + 1][x] + space[y][1];  // ㅏ
	else if (y == N - 1) sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y - 1][x]; // ㅓ
	else if (x == M - 1) sum = space[y][x] + space[y][x - 1] + space[y + 1][x] + space[y - 1][x]; // ㅗ
	else {
		sum = space[y][x] + space[y][x - 1] + space[y][x + 1] + space[y + 1][x] + space[y - 1][x]; // +
		int mn = min(min(space[y + 1][x], space[y - 1][x]), min(space[y][x + 1], space[y][x - 1])); // 상하좌우 중 가장 작은 것
		sum -= mn; // 빼기
	}
	if (mx < sum) mx = sum;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	space.assign(N, vector<int>(M));
	for (auto& vi : space) for (int& i : vi) cin >> i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			FindMax(i, j, 0); // ㅡ, ㅣ, ㄴ, ㄱ, ㅁ 등
			FindTValue(i, j); // ㅓ, ㅗ, ㅜ, ㅏ
		}
	}
	cout << mx;
}