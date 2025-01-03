#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k, cur;
	cin >> n >> k;
	
	vector<int> subin(100001, MAX);
	queue<int> q;
	q.push(n);
	subin[n] = 0;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if(cur > 0) {
			if (subin[cur - 1] > subin[cur] + 1) {
				subin[cur - 1] = subin[cur] + 1;
				q.push(cur - 1);
			}
		}

		if (cur < 100000) {
			if (subin[cur + 1] > subin[cur] + 1) {
				subin[cur + 1] = subin[cur] + 1;
				q.push(cur + 1);
			}
		}

		if (cur <= 50000) {
			if (subin[cur * 2] > subin[cur]) {
				subin[cur * 2] = subin[cur];
				q.push(cur * 2);
			}
		}
	}
	cout << subin[k];
}