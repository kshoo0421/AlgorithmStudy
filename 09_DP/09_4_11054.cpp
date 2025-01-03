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
		for (int j = i + 1; j < N; j++) {
			if (Ai[i] < Ai[j]) left[j] = max(left[j], left[i] + 1);
		}
		int k = N - i - 1;
		if (right[k] == 0) right[k] = 1;
		for (int j = k - 1; j >= 0; j--) {
			if (Ai[k] < Ai[j]) right[j] = max(right[j], right[k] + 1);
		}
	}
	for (int i = 0; i < N; i++) mx = max(mx, left[i] + right[i]);
	cout << mx - 1;
}