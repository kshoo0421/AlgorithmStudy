#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, j, total = 0;
	cin >> N;
	vector<int> pos, neg;
	for (int i = 0; i < N; i++) {
		cin >> j;
		if (j > 0) pos.emplace_back(j);
		else neg.emplace_back(j);
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());
	for (int i = 0; i < pos.size(); i++) {
		if (i < pos.size() - 1) {
			if (pos[i] * pos[i + 1] > pos[i] + pos[i + 1]) {
				total += (pos[i] * pos[i + 1]);
				i++;
			}
			else total += pos[i];
		}
		else total += pos[i];
	}
	for (int i = 0; i < neg.size(); i += 2) {
		if (i < neg.size() - 1) total += (neg[i] * neg[i + 1]);
		else total += neg[i];
	}
	cout << total;
}