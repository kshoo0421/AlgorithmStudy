#include <bits/stdc++.h>
using namespace std;
bool btn_err[10];

bool is_num_possible(int n)
{
	if (n < 10) return !btn_err[n];
	while (n)
	{
		if (btn_err[n % 10]) return false;
		n /= 10;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	bool err_done = false;
	int n, m, u, d, tmp, ans, a1, a2, a3;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{ 
		cin >> tmp;
		btn_err[tmp] = true;
	}
	
	if (m == 10)
	{
		cout << abs(n - 100);
		return 0;
	}

	u = n, d = n;
	
	while (!is_num_possible(u))
	{
		if (m == 9 && btn_err[0] == false)
		{
			u = 100;
			break;
		}
		u++;
	}
	while (!is_num_possible(d))	d--;
	
	a1 = abs(u - n);
	tmp = u;
	if (u == 0) a1++;
	while (tmp)	tmp /= 10, a1++;

	if (d < 0) d = 100;
	a2 = abs(n - d);
	tmp = d;
	if (d == 0) a2++;
	while (tmp)	tmp /= 10, a2++;

	ans = min(a1, a2);
	ans = min(ans, abs(n - 100));
	cout << ans;
}