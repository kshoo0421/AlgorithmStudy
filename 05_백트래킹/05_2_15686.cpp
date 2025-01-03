#include <bits/stdc++.h>
#define X second
#define Y first
using namespace std;

int N, M;
vector<int> sum_dist;
vector<pair<int, int>> houses, chickens, M_chickens;

int GetDist(int c1, int r1, int c2, int r2) { return abs(r1 - r2) + abs(c1 - c2); }

int GetChikenDist() {
	int sum = 0, mn = 0, dist = 0;
	for (int i = 0; i < houses.size(); i++) {
		for (int j = 0; j < M_chickens.size(); j++) {
			dist = GetDist(houses[i].X, houses[i].Y, M_chickens[j].X, M_chickens[j].Y);			
			if (j == 0) mn = dist;
			else mn = min(mn, dist);
		}
		sum += mn;
	}
	return sum;
}

void BackTracking(int index) {
	if (index >= chickens.size()) return;

	M_chickens.emplace_back(chickens[index]);
	if (M_chickens.size() == M) sum_dist.emplace_back(GetChikenDist());
	else BackTracking(index + 1);

	M_chickens.pop_back();
	BackTracking(index + 1);
	return;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) houses.emplace_back(make_pair(i, j));
			if (input == 2) chickens.emplace_back(make_pair(i, j));
		}
	}
	BackTracking(0);
	sort(sum_dist.begin(), sum_dist.end());
	cout << sum_dist[0];
}