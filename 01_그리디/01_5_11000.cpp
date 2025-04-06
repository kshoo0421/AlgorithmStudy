#include <bits/stdc++.h>
#define S first
#define T second
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; 
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> input(N);
	for (auto& pii : input) cin >> pii.S >> pii.T;
	
	sort(input.begin(), input.end());
	pq.push(input[0].T);

	for (int i = 1; i < N; i++) {
		if (pq.top() <= input[i].S) pq.pop();
		pq.push(input[i].second);
	}
	cout << pq.size();
	return 0;
}