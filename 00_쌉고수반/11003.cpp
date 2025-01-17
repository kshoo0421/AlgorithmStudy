#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, L;
	cin >> N >> L;
	deque<int> dq;
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> pq, unerased;

	while (N--) {
		int input;
		cin >> input;
		dq.push_back(input);
		pq.push(input);

		if (dq.size() == L + 1) {
			int front = dq.front();
			dq.pop_front();

			if (pq.top() == front) {
				pq.pop();

				while (unerased.size() > 0) {
					if (pq.top() != unerased.top()) break;
					pq.pop();
					unerased.pop();
				}
			}
			else unerased.push(front);
		}
		answer.push_back(pq.top());
	}
	for (int i : answer) cout << i << " ";
	return 0;
}