#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL N, k;

LL GetCount(LL x) {
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