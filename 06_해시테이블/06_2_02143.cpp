#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL T;
int n, m;
vector<int> A, B;
vector<LL> aSubSum, bSubSum;
map<LL, LL> aTotal, bTotal;

inline LL FindSubArr(int start, int end, bool isA) {
	return isA ? (aSubSum[end] - aSubSum[start - 1]) : (bSubSum[end] - bSubSum[start - 1]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T >> n;
	A.assign(n + 1, 0);
	aSubSum.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		aSubSum[i] = aSubSum[i - 1] + A[i];
	}

	cin >> m;
	B.assign(m + 1, 0);
	bSubSum.assign(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		bSubSum[i] = bSubSum[i - 1] + B[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			aTotal[FindSubArr(i, j, true)]++;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			bTotal[FindSubArr(i, j, false)]++;
		}
	}

	LL count = 0;
	for (auto it = aTotal.begin(); it != aTotal.end(); it++) {
		LL curB = T - ((*it).first);
		if (bTotal.find(curB) != bTotal.end()) {
			count += ((*it).second) * (bTotal[curB]);
		}
	}
	cout << count;
}