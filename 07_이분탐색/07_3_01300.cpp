/* [풀이]
1. x 이하 숫자의 갯수는 sum(1~N)min(N, (x / i))
2. 이분 탐색을 하며, 적절한 갯수를 찾는다.
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL N, k; // k가 int 범위를 초과할 수 있음

LL GetCount(LL x) { // x 이하의 숫자의 개수
	LL count = 0;
	for (int i = 1; i <= N; i++) {
		count += min(N, (x / i));
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> k;
	// 이분탐색. 범위가 int를 초과할 수 있으므로 LL 사용
	LL l = 1, r = N * N, result = 0;
	while (l <= r) {
		LL m = (l + r) / 2;
		if (GetCount(m) >= k) {
			result = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << result;
}