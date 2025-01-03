#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int& i : a) cin >> i;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) lis.push_back(a[i]);
        else *it = a[i];
    }
    cout << lis.size();
}