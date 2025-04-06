#include <bits/stdc++.h>
using namespace std;

int N, answer = 0;
vector<vector<int>> grid;

void TurnGrid(vector<vector<int>>& cur) {
	vector<vector<int>> copied = cur;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cur[i][j] = copied[N - 1 - j][i];
		}
	}
}

void Slide(vector<vector<int>>& cur) {
	for (int i = 0; i < N; i++) {
		queue<int> tmp;
		for (int j : cur[i]) {
			if (j != 0) tmp.push(j);
		}

		for (int j = 0; j < N; j++) {
			if (tmp.empty()) {
				cur[i][j] = 0;
				continue;
			}
			cur[i][j] = tmp.front();
			tmp.pop();
			if (!tmp.empty() && cur[i][j] == tmp.front()) {
				cur[i][j] *= 2;
				tmp.pop();
			}
		}
	}
}

void Step(int step, vector<vector<int>> cur) {
	Slide(cur);

	if (step == 5) {
		for (auto& vi : cur) {
			for (int& i : vi) {
				if (answer < i) {
					answer = i;
				}
			}
		}
		return;
	}

	Step(step + 1, cur);
	for (int i = 0; i < 3; i++) {
		TurnGrid(cur);
		Step(step + 1, cur);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	grid.assign(N, vector<int>(N));
	for (auto& vi : grid) {
		for (int& i : vi) {
			cin >> i;
		}
	}
	Step(1, grid);
	for (int i = 0; i < 3; i++) {
		TurnGrid(grid);
		Step(1, grid);
	}
	cout << answer;
}