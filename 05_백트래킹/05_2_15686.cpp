/* [풀이]
1. 치킨집 중 N개를 백트래킹으로 선정한다. 선정한 치킨집은 vector에 좌표를 저장한다.
2. 선택된 치킨집 중 각 집에서 가장 가까운 치킨집을 확인한다.
vector에 있는 좌표를 바탕으로 거리를 계산한다.
3. 최솟값들을 모두 더해, N개를 골랐을 때 마을의 치킨 거리를 구한다.
4. 해당 값들 중 최솟값을 정답으로 출력한다.
*/

#include <bits/stdc++.h>
#define Y first
#define X second
#define GET_DIST(x1, y1, x2, y2) (abs((x1) - (x2)) + abs((y1) - (y2)))
// 2개의 위치가 있을 때 거리 계산하는 매크로 함수
using namespace std;

int N, M; // 입력값
vector<int> sums; // 마을의 치킨거리들 저장. 일단 저장 후 min_element로 최솟값 확인
vector<pair<int, int>> houses, chickens, selected; // 각 집, 전체 치킨집, 선택된 치킨집의 좌료

int GetChickenDist() { // N개를 고른 후 마을의 치킨 거리를 구하는 함수
	int sum = 0, minimum = 0;
	for (int i = 0; i < houses.size(); i++) {
		// 각 집에서 가장 가까운 치킨집 찾기
		for (int j = 0; j < selected.size(); j++) {
			int dist = GET_DIST(houses[i].X, houses[i].Y, selected[j].X, selected[j].Y);
			if (j == 0) minimum = dist;
			else minimum = min(minimum, dist);
		}
		sum += minimum;
	}
	return sum;
}

void BackTracking(int index) { // 치킨집 N개를 선택하는 함수
	if (index >= chickens.size()) return;

	// idx번째 치킨집을 선택한 치킨집에 추가
	selected.push_back(chickens[index]);
	
	// N개를 찾았으면 마을 치킨거리 확인 후 추가
	if (selected.size() == M) sums.push_back(GetChickenDist()); 
	// 아니라면 한 번 더 탐색
	else BackTracking(index + 1);

	// idx번째 치킨집을 선택한 치킨집에서 제거
	selected.pop_back();
	// 그 다음 백트래킹 시도
	BackTracking(index + 1);
	return;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) houses.push_back({i, j}); // 집 좌표 추가
			if (input == 2) chickens.push_back({i, j}); // 치킨집 좌표 추가
		}
	}
	BackTracking(0); // 0번째 치킨집부터 시작
	cout << *min_element(sums.begin(), sums.end()); // 최솟값 출력
}