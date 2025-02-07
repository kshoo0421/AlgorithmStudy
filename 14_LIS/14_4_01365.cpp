#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> saved;
	for(int i = 0; i < N; i++) {
		int input;
		cin >> input;
		auto it = upper_bound(saved.begin(), saved.end(), input);
		if (it == saved.end()) saved.push_back(input);
		else *it = input;
	}
	cout << N  - saved.size();
}