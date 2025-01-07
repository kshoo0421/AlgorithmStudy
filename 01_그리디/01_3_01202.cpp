/* [풀이]
1. 보석과 가방을 무게를 기준으로 오름차순 정렬
2. 현재 가방보다 무게가 작은 보석의 가치를 다 우선순위 큐에 넣기
3. 무게가 작은 보석들 중 가장 가치가 높은 보석을 추출
4. 총합 계산
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long N, K, bag, total = 0;
	priority_queue<int> pq;
	/*
	cf) pq 기본값 : 내림차순
	오름차순으로 변경하고 싶다면
	priority_queue<int, vector<int>, greater<int>> pq;
	*/
	cin >> N >> K;

	// 보석은 총 N개. <무게, 가격>
	vector<pair<long, long>> Jewels(N);
	// 가방은 총 K개
	vector<int> Bags(K);
	
	// 보석 입력 cf) pll : Pair<Long, Long>
	for (auto& pll : Jewels) cin >> pll.first >> pll.second; 
	// 가방 입력 cf) i : int
	for (int& i : Bags) cin >> i;
	
	// 가방 오름차순 정렬
	sort(Bags.begin(), Bags.end());
	// 보석 오름차순 정렬
	sort(Jewels.begin(), Jewels.end());
	/* 
	cf) pair의 경우 앞 값을 기준으로 정렬. 
	앞 값이 같다면 뒷 값을 기준으로 정렬
	커스텀하고 싶으면
	int cmp(const pair<A, B>& p1, const pair<A, B>& p2) {}
	으로 비교 함수를 만들어서
	sort(A.begin(), B.begin(), cmp);
	를 넣어주면 됨(함수 포인터)
	*/ 

	// 보석의 인덱스. 무게가 작은 순서대로 하나씩 확인
	int idx = 0;
	// 가방에 하나씩 넣기
	for (int i = 0; i < K; i++) {
		// 가방 최대 무게보다 작은 보석들 pq에 넣기
		while (idx < N && Jewels[idx].first <= Bags[i]) pq.push(Jewels[idx++].second);
		// 그 중 가장 가치가 높은 보석을 가방에 넣기
		if (!pq.empty()) {
			// 총합에 더하기
			total += pq.top();
			pq.pop();
		}
	}
	// 결과 출력
	cout << total;
}