#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long N, K, bag, total = 0, j = 0;
	priority_queue<int> pq;
	cin >> N >> K;
	vector<pair<long, long>> Jewels(N);
	vector<int> Bags(K);
	for (auto& vii : Jewels) cin >> vii.first >> vii.second;
	for (int& i : Bags) cin >> i;
	sort(Bags.begin(), Bags.end());
	sort(Jewels.begin(), Jewels.end());
	for (int i = 0; i < K; i++) {
		while (j < N && Jewels[j].first <= Bags[i]) pq.push(Jewels[j++].second);
		if (!pq.empty()) {
			total += pq.top();
			pq.pop();
		}
	}
	cout << total;
}