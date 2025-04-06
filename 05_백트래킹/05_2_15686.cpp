#include <bits/stdc++.h>
#define Y first
#define X second
#define GET_DIST(x1, y1, x2, y2) (abs((x1) - (x2)) + abs((y1) - (y2)))
using namespace std;

int N, M;
vector<int> sums;
vector<pair<int, int>> houses, chickens, selected;

int GetChickenDist() {
	int sum = 0, minimum = 0;
	for (int i = 0; i < houses.size(); i++) {
		for (int j = 0; j < selected.size(); j++) {
			int dist = GET_DIST(houses[i].X, houses[i].Y, selected[j].X, selected[j].Y);
			if (j == 0) minimum = dist;
			else minimum = min(minimum, dist);
		}
		sum += minimum;
	}
	return sum;
}

void BackTracking(int index) {
	if (index >= chickens.size()) return;

	selected.push_back(chickens[index]);
	
	if (selected.size() == M) sums.push_back(GetChickenDist()); 
	else BackTracking(index + 1);

	selected.pop_back();
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
			if (input == 1) houses.push_back({i, j});
			if (input == 2) chickens.push_back({i, j});
		}
	}
	BackTracking(0);
	cout << *min_element(sums.begin(), sums.end());
}