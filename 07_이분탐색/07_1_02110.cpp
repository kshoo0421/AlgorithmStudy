#include <bits/stdc++.h>
using namespace std;

bool canPlaceRouters(vector<int>& houses, int dist, int c) {
	int cnt = 1, last = houses[0];
	for (int cur : houses) {
		if (cur - last >= dist) {
			cnt++;
			last = cur;
		}
	}
	return cnt >= c;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, c, min, mid, max, result;
	cin >> n >> c;
	vector<int> houses(n);

	for (int& i : houses) cin >> i;
	sort(houses.begin(), houses.end());

	min = 1;
	max = houses.back() - houses.front();
	result = 0;

	while (min <= max) {
		mid = (min + max) / 2;
		if (canPlaceRouters(houses, mid, c)) {
			result = mid;
			min = mid + 1;
		}
		else max = mid - 1;
	}
	cout << result;
}