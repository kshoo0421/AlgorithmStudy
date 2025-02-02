#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
vector<pair<float, float>> stars;
vector<tuple<int, int, float>> dist;
vector<int> parent, ranks;

float GetDist(int idx1, int idx2) {
	float x = pow((stars[idx1].X - stars[idx2].X), 2);
	float y = pow((stars[idx1].Y - stars[idx2].Y), 2);
	return sqrt(x + y);
}

int FindParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = FindParent(parent[a]);
}

void SetUnion(int a, int b) {
	int rootX = FindParent(a);
	int rootY = FindParent(b);

	if (rootX != rootY) {
		if (ranks[rootX] < ranks[rootY]) parent[rootX] = rootY;
		else if (ranks[rootX] > ranks[rootY]) parent[rootY] = rootX;
		else {
			parent[rootY] = rootX;
			ranks[rootX]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	stars.resize(N);
	parent.resize(N);
	for (int i = 0; i < N; i++) parent[i] = i;
	ranks.assign(N, 0);
	for (auto& pff : stars) cin >> pff.X >> pff.Y;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			dist.push_back({ i, j, GetDist(i, j)});
		}
	}

	sort(dist.begin(), dist.end(), [&](auto& tiif1, auto& tiif2) {
		return get<2>(tiif1) < get<2>(tiif2);
		});

	float answer = 0;
	for (auto& tiif : dist) {
		int a = get<0>(tiif);
		int b = get<1>(tiif);
		if (FindParent(a) != FindParent(b)) {
			answer += get<2>(tiif);
			SetUnion(a, b);
		}
	}
	cout << fixed << setprecision(2) << answer;
}