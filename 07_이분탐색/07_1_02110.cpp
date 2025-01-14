/* [풀이]
1. 현재 거리제한을 두면 최대 몇 대의 공유기를 둘 수 있는지 확인한다.
-> 그리디 방식으로 찾기
2. 해당 값이 C보다 큰지 확인한다.
3. 이분탐색으로 범위를 좁힌다.
*/

#include <bits/stdc++.h>
using namespace std;

int N, C; // 입력값
vector<int> houses;

bool CanPlaceRouters(int dist) {
	int cnt = 1, last = houses[0];
	// cnt : 공유기 설치 갯수
	// last : 설치한 마지막 집
	for (int cur : houses) {
		// 마지막 집에서 현재 집까지의 거리가 dist를 넘는다면
		if (cur - last >= dist) {
			cnt++; // 설치 추가
			last = cur; // 현재 집에 마지막으로 설치
		}
	}
	return (cnt >= C); // 설치 갯수가 C보다 많은지
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> C;

	houses.assign(N, 0);
	for (int& i : houses) cin >> i;
	sort(houses.begin(), houses.end());

	// 집 사이 최소 거리
	int min = 1; 
	// 집 사이 최대 거리
	int max = houses.back() - houses.front(); 
	int result = 0;

	while (min <= max) {
		int mid = (min + max) / 2; // 중간값
		// 중간값에 라우터 설치 가능여부 확인
		if (CanPlaceRouters(mid)) { 
			result = mid; // 현재 값 업데이트
			min = mid + 1; // 최솟값 높이기
		}
		else max = mid - 1; // 최댓값 낮추기
	}
	cout << result;
}