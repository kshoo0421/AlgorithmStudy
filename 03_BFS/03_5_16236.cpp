#include <bits/stdc++.h>
using namespace std;

int n, sharkSize = 2, sharkX, sharkY, cx, cy, nx, ny, ccnt, ncnt, ate_fish, result = 0;
int space[20][20];
bool isVisited[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct possible {
	int time;
	int x;
	int y;
};

queue<possible> q;
vector<possible> vp;
possible tmpP;

int Cmp(possible p1, possible p2) {
	if (p1.time != p2.time) return p1.time < p2.time;
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

bool EatFish()
{
	for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) isVisited[i][j] = false;
	tmpP.time = 0;
	tmpP.x = sharkX;
	tmpP.y = sharkY;
	q.push(tmpP);
	while (!q.empty()) {
		ccnt = q.front().time;
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		if (isVisited[cy][cx] == true) continue;
		isVisited[cy][cx] = 1;
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			ncnt = ccnt + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (isVisited[ny][nx] == 1 || space[ny][nx] > sharkSize) continue;

			if (space[ny][nx] == sharkSize || space[ny][nx] == 0) {
				tmpP.time = ncnt;
				tmpP.x = nx;
				tmpP.y = ny;
				q.push(tmpP);
			}
			else {
				tmpP.time = ncnt;
				tmpP.x = nx;
				tmpP.y = ny;
				vp.emplace_back(tmpP);
			}
		}
	}
	if (vp.empty()) return true;
	sort(vp.begin(), vp.end(), Cmp);
	sharkX = vp[0].x;
	sharkY = vp[0].y;
	space[sharkY][sharkX] = 0;
	result += vp[0].time;
	ate_fish++;
	if (sharkSize == ate_fish) {
		ate_fish = 0;
		sharkSize++;
	}
	vp.clear();
	return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				sharkX = j;
				sharkY = i;
				space[i][j] = 0;
			}
		}
	}
	while (!EatFish());
	cout << result;
}