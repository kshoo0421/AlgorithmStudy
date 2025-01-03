#include <bits/stdc++.h>
using namespace std;
int n, m, cx, cy, nx, ny, year = 0, tmp;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[300][300];
int space[300][300], memo[300][300];
queue<pair<int, int>> q;

void year_later()
{
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++) memo[i][j] = space[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (space[i][j] != 0)
			{
				cx = j;
				cy = i;
				for (int k = 0; k < 4; k++)
				{
					nx = cx + dx[k];
					ny = cy + dy[k];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (memo[ny][nx] == 0) space[cy][cx]--;
				}
				if (space[cy][cx] < 0) space[cy][cx] = 0;
			}
		}
	}

}

int check_piece()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++) vis[i][j] = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (space[i][j] != 0 && vis[i][j] == false)
			{
				cnt++;
				q.push({ i, j });
				while (!q.empty())
				{
					cx = q.front().second;
					cy = q.front().first;
					q.pop();
					if (vis[cy][cx]) continue;
					vis[cy][cx] = true;
					for (int k = 0; k < 4; k++)
					{
						nx = cx + dx[k];
						ny = cy + dy[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (vis[ny][nx] || space[ny][nx] == 0) continue;
						q.push({ ny, nx });
					}
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++) cin >> space[i][j];
	while (check_piece() == 1)
	{
		year++;
		year_later();
	}
	if (check_piece() == 0) cout << "0";
	else cout << year;
}