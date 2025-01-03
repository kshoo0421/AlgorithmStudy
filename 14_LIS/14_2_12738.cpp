#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
    vector<int> lis;
    for (int i : a) {
        auto it = lower_bound(lis.begin(), lis.end(), i);
        if (it == lis.end()) lis.push_back(i);
        else *it = i;
    }
    cout << lis.size();
}