#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, input;
	cin >> N;
	map<int, bool> isPlus;
	priority_queue<int> pqi;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (isPlus.find(abs(input)) != isPlus.end()) {
			cout << -1 * input << " " << input;
			return 0;
		}
		isPlus[abs(input)] = (input > 0);
		pqi.push(abs(input));
	}

	int plus = -1, minus = -1, minimum = INT_MAX, cur;
	pair<int, int> result;
	
	while (!pqi.empty()) {
		cur = pqi.top();
		pqi.pop();
		if (isPlus[cur]) {
			if ((plus != -1) && (plus + cur < minimum)) {
				minimum = plus + cur;
				result = { cur, plus };
			}
			plus = cur;
		}
		else {
			if ((minus != -1) && (minus + cur < minimum)) {
				minimum = minus + cur;
				result = { -1 * minus, -1 * cur };
			}
			minus = cur;
		}
		if (plus == -1 || minus == -1) continue;
		if (abs(plus - minus) < minimum) {
			minimum = abs(plus - minus);
			result = { -1 * minus, plus };
		}
	}
	cout << result.first << " " << result.second;
}