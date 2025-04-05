#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long N, K, bag, total = 0;
	priority_queue<int> pq;
	cin >> N >> K;

	vector<pair<long, long>> Jewels(N);
	vector<int> Bags(K);
	
	for (auto& pll : Jewels) cin >> pll.first >> pll.second; 
	for (int& i : Bags) cin >> i;
	
	sort(Bags.begin(), Bags.end());
	sort(Jewels.begin(), Jewels.end());
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && Jewels[idx].first <= Bags[i]) pq.push(Jewels[idx++].second);
		if (!pq.empty()) {
			total += pq.top();
			pq.pop();
		}
	}
	cout << total;
}