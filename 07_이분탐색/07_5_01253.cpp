#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	int cnt = 0;
	sort(A.begin(), A.end());
	for (int i = N - 1; i >= 0; i--) {
		int l = 0, r = N - 1;
		while (l < r) {
			if (r == i) {
				r--;
				continue;
			}
			if (l == i) {
				l++;
				continue;
			}
			int sum = A[l] + A[r];
			if (sum == A[i]) {
				cnt++;
				break;
			}
			if (sum < A[i]) l++;
			else r--;
		}
	}
	cout << cnt;
}