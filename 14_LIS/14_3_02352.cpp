#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> saved;
	while (N--) {
		int i;
		cin >> i;
		auto it = upper_bound(saved.begin(), saved.end(), i);
		if (it == saved.end()) saved.push_back(i);
		else *it = i;
	}
	cout << saved.size();
}