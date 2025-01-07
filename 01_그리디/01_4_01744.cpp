/* [풀이]
1. 양수와 음수를 따로 저장
2. 양수는 내림차순, 음수는 오름차순으로 정렬
(절댓값 기준 내림차순)
3. 양수는 (곱셈) vs (덧셈)을 비교한 후 큰 값으로 덧셈.
음수는 최대한 묶기
4. 남은 모든 수를 더하고 결과 도출
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> pos, neg; // pos : 양수(positive) / neg : 음수(negative)
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input > 0) pos.emplace_back(input); // 0보다 크면 양수에
		else neg.emplace_back(input); // 0보다 작거나 같으면 음수에
		// 0을 음수에 넣을 경우 {(음수) * 0 } 묶음으로 총합을 늘릴 수 있음
	}
	sort(pos.rbegin(), pos.rend()); // 양수 : 내림차순
	sort(neg.begin(), neg.end()); // 음수 : 오름차순(절대값이 큰 순서)
	
	int total = 0; // 현재 총합 : 0
	// 양수 먼저
	for (int i = 0; i < pos.size(); i++) {
		if (i < pos.size() - 1) { // 다음 수가 있다면
			// (곱셈) vs (덧셈) 크기 비교
			if (pos[i] * pos[i + 1] > pos[i] + pos[i + 1]) {
				total += (pos[i] * pos[i + 1]);
				// 곱셈 시 묶였으니 i도 한 칸 더 이동
				i++;
			}
			else total += pos[i];
		}
		else total += pos[i]; // 마지막 수면 더하기
	}

	// 음수면 2개씩 묶고, 1개 남으면 해당 값 더하기
	for (int i = 0; i < neg.size(); i += 2) { // 반드시 묶으니 2칸씩
		if (i < neg.size() - 1) total += (neg[i] * neg[i + 1]);
		else total += neg[i];
	}
	cout << total; // 총합 출력
}