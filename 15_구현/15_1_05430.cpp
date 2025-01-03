#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	bool isError, isFront;
	int T, n;
	string p, x, stmp;
	deque<int> xDeq;
	cin >> T;
	while (T--) {
		xDeq.clear();
		isFront = true;
		isError = false;
		stmp = "";
		cin >> p >> n >> x;
		for (int i = 1; i < x.size(); i++) {
			if (x[i] == ',' || x[i] == ']') {
				if (stmp != "") {
					xDeq.push_back(stoi(stmp));
					stmp = "";
				}
			}
			else if (x[i] == ' ') continue;
			else stmp += x[i];
		}

		for (char c : p) {
			if (c == 'R') isFront = !isFront;
			else {
				if (xDeq.size() == 0) {
					isError = true;
					break;
				}
				if (isFront) xDeq.pop_front();
				else xDeq.pop_back();
			}
		}

		if (isError) cout << "error\n";
		else {
			if (!isFront) reverse(xDeq.begin(), xDeq.end());
			cout << "[";
			for (int i = 0; i < xDeq.size(); i++) {
				cout << xDeq[i];
				if (i != xDeq.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}
}