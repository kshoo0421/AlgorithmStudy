/* [풀이]
1. 수업시간을 시작하는 시각 기준으로 정렬
2. 우선순위 큐에 끝나는 시각 기록
3. 가장 빨리 끝나는 수업보다 더 일찍 시작해야한다면 강의실 추가
빨리 끝나는 수업 이후에 가능하다면, top을 빼고 새로운 종료 시각 추가
4. pq의 크기 == 강의실 갯수
*/

#include <bits/stdc++.h>
#define S first
#define T second
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; 
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> input(N);
	// pii : Pair<Int, Int>
	for (auto& pii : input) cin >> pii.S >> pii.T;
	
	// 시작시간 기준 정렬
	sort(input.begin(), input.end());
	pq.push(input[0].T); // 처음 끝나는 시간

	for (int i = 1; i < N; i++) { // 나머지 input 확인
		// 가장 빨리 끝나는 수업 이후 다른 수업이 가능하다면
		if (pq.top() <= input[i].S) pq.pop(); // 강의실 비우기
		pq.push(input[i].second); // 수업 종료 시각 추가
	}
	cout << pq.size();
	return 0;
}