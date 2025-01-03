#include <bits/stdc++.h>
using namespace std;

int L, C;
string s = "";
vector<char> letters;

bool CheckCondition() {
	int vowelCnt = 0;
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowelCnt++;
	}
	return (vowelCnt >= 1 && vowelCnt <= L - 2);
}

void BackTracking(int idx) {
	if (idx == letters.size()) return;
	s += letters[idx];
	if (s.size() == L) {
		if(CheckCondition()) cout << s << "\n";
	}
	else BackTracking(idx + 1);
	s.pop_back();
	BackTracking(idx + 1);
}

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> L >> C;
	letters.assign(C, ' ');
	for (char& c : letters) cin >> c;
	sort(letters.begin(), letters.end());
	BackTracking(0);
}