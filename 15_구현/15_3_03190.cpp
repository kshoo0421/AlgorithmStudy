#include <bits/stdc++.h>
#define X first
#define Y second
#define C second
using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int N, K, L, sec = 0, dir = 0;

vector<vector<int>> space;
queue<pair<int, char>> inform;
deque<pair<int, int>> snake;

void changeDir(char c) {
	if (c == 'D') dir = ((dir + 3) % 4);
	else dir = ((dir + 1) % 4);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);	
	cin >> N >> K;
	space.assign(N, vector<int>(N, 0));
	pair<int, int> tpii;
	for (int i = 0; i < K; i++) {
		cin >> tpii.X >> tpii.Y;
		space[tpii.X - 1][tpii.Y - 1] = 1;
	}

	cin >> L;
	pair<int, char> tpic;
	for (int i = 0; i < L; i++) {
		cin >> tpic.X >> tpic.C;
		inform.push(tpic);
	}
	
	snake.push_back({ 0, 0 });
	while (1) {
		sec++;
		int nx = snake.back().X + dx[dir];
		int ny = snake.back().Y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
		
		bool isEnd = false;
		for (auto& pii : snake) {
			if (pii.X == nx  && pii.Y == ny) {
				isEnd = true;
				break;
			}
		}
		if (isEnd) break;

		if (space[nx][ny] == 1) space[nx][ny] = 0;
		else snake.pop_front();	
		snake.push_back({ nx, ny });
		if (!inform.empty() && (inform.front().X == sec)) {
			changeDir(inform.front().C);
			inform.pop();
		}
	}
	cout << sec;
}