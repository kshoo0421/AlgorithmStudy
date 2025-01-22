/* [풀이]
1. 절대값을 기준으로 map에 값 저장. <절대값, 양수 여부>
2. 우선순위 큐에 절대값 기준으로 삽입. => 절대값 내림차순
3. 절대값이 같은 값이 있다면 합이 0이므로 종료
4. 총 3가지 케이스 체크
1) abs(양수 + 양수)가 최소값인 경우
2) abs(음수 + 음수)가 최소값인 경우
3) abs(양수 + 음사)가 최소값인 경우
5. 최종 결과값 출력 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, input;
	cin >> N;
	map<int, bool> isPlus;
	priority_queue<int> pqi;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (isPlus.find(abs(input)) != isPlus.end()) { // 반대편 절대값이 있다면 합이 0
			cout << -1 * input << " " << input;
			return 0; // 프로그램 종료
		}
		isPlus[abs(input)] = (input > 0);
		pqi.push(abs(input));
	}

	int plus = -1, minus = -1, minimum = INT_MAX, cur;
	pair<int, int> result;
	
	while (!pqi.empty()) {
		cur = pqi.top();
		pqi.pop();
		if (isPlus[cur]) { // 양수라면
			if ((plus != -1) && (plus + cur < minimum)) { // 두 양수의 합이 현재 최소값보다 작다면
				minimum = plus + cur; // 값 업데이트
				result = { cur, plus };
			}
			plus = cur; // 양수값 업데이트
		}
		else {
			if ((minus != -1) && (minus + cur < minimum)) { // 두 음수의 합의 절대값이 최소값보다 작다면
				minimum = minus + cur; // 값 업데이트
				result = { -1 * minus, -1 * cur };
			}
			minus = cur; // 음수값 업데이트
		}
		if (plus == -1 || minus == -1) continue; // 둘 중 하나라도 초기 값이면 종료
		if (abs(plus - minus) < minimum) {
			minimum = abs(plus - minus);
			result = { -1 * minus, plus };
		}
	}
	cout << result.first << " " << result.second;
}