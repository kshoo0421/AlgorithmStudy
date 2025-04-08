#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> houses;

bool CanPlaceRouters(int dist) {
	int cnt = 1, last = houses[0];
	for (int cur : houses) {
		if (cur - last >= dist) {
			cnt++;
			last = cur;
		}
	}
	return (cnt >= C);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> C;

	houses.assign(N, 0);
	for (int& i : houses) cin >> i;
	sort(houses.begin(), houses.end());

	int min = 1; 
	int max = houses.back() - houses.front(); 
	int result = 0;

	while (min <= max) {
		int mid = (min + max) / 2;
		if (CanPlaceRouters(mid)) { 
			result = mid;
			min = mid + 1;
		}
		else max = mid - 1;
	}
	cout << result;
}