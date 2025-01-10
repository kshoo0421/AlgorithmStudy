/* [풀이]
1. 입력된 글자를 우선 정렬한다. 이렇게 할 경우 나중에 단어 정렬을 하지 않아도 된다.
2. 백트래킹으로 단어를 생성한다. 단어가 생성되었다면,
해당 단어가 모음 1개 이상과 자음 2개 이상인지 확인한다.
3. 조건에 맞다면 출력하고, 아니라면 취소한다.
*/

#include <bits/stdc++.h>
using namespace std;

int L, C;
string s = "";
vector<char> letters;

bool CheckCondition() { // 선택한 문자열에 최소 1개의 모음과 2개의 자음이 있는지 확인하는 함수
	int vowelCnt = 0; // 모음 갯수
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowelCnt++;
	}
	return (vowelCnt >= 1 && (2 <= (L - vowelCnt))); // 모음 1개 이상 && 자음 2개 이상
}

void BackTracking(int idx) {
	if (idx == letters.size()) return;
	s += letters[idx]; // 현재 글자를 문자열에 추가
	if (s.size() == L) { // 글자가 갯수에 맞다면
		if(CheckCondition()) cout << s << "\n"; // 단어가 조건에 맞다면 출력
	}
	else BackTracking(idx + 1); // 한 번 더 백트래킹 시도
	s.pop_back(); // 추가했던 문자열 제거
	BackTracking(idx + 1); // 백트래킹 시도
}

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> L >> C;
	letters.assign(C, ' ');
	for (char& c : letters) cin >> c;
	sort(letters.begin(), letters.end()); // 글자를 먼저 정렬하면, 나중에 단어 정렬을 안해도 됨
	BackTracking(0);
}