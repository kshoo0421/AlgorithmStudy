/* [풀이]
1. 수열을 입력 받고 2가지 기준으로 dp용으로 메모한다.
- left : (왼 -> 오) 현재까지 연속으로 몇 칸 증가했는지
- right : (오 -> 왼) 현재까지 연속으로 몇 칸 감소했는지
2. 각 칸을 탐색하며 left + right의 합이 가장 큰 값을 찾는다.
3. 결괏값을 출력한다. left와 right에 모두 자신이 포함되어 있으니 1을 빼고 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, mx = 0; 
	cin >> N;
	vector<int> Ai(N), left(N), right(N);
	for (int& i : Ai) cin >> i;
	for (int i = 0; i < N; i++) {
		if (left[i] == 0) left[i] = 1;
		for (int j = i + 1; j < N; j++) { // left
			if (Ai[i] < Ai[j]) left[j] = max(left[j], left[i] + 1);
		}
		int k = N - i - 1;
		if (right[k] == 0) right[k] = 1;
		for (int j = k - 1; j >= 0; j--) { // right
			if (Ai[k] < Ai[j]) right[j] = max(right[j], right[k] + 1);
		}
	}
	for (int i = 0; i < N; i++) mx = max(mx, left[i] + right[i]);
	cout << mx - 1;
}