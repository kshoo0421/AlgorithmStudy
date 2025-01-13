/* [풀이]
1. 부분배열의 합을 구해서 map에 그 갯수를 저장한다.
2. 하나의 부분배열합이 정해졌다면, 반대편에 그 갯수를 확인한다.
3. 만약 반대편에 필요한 값이 있다면, 각각의 갯수를 곱해 count에 추가한다.
4. 모든 합이 int 범위를 초과할 수 있으므로, long long 으로 선언한다.
*/

#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL T;
int n, m;
vector<int> A, B;
vector<LL> aSubSum, bSubSum;
map<LL, LL> aTotal, bTotal;

inline LL FindSubArr(int start, int end, bool isA) { // 부분배열 합
	return isA ? (aSubSum[end] - aSubSum[start - 1]) : (bSubSum[end] - bSubSum[start - 1]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T >> n;
	A.assign(n + 1, 0);
	aSubSum.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		aSubSum[i] = aSubSum[i - 1] + A[i];
	}

	cin >> m;
	B.assign(m + 1, 0);
	bSubSum.assign(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		bSubSum[i] = bSubSum[i - 1] + B[i];
	}
	
	for (int i = 1; i <= n; i++) { // a map에 저장
		for (int j = i; j <= n; j++) {
			aTotal[FindSubArr(i, j, true)]++;
		}
	}

	for (int i = 1; i <= m; i++) { // b map에 저장
		for (int j = i; j <= m; j++) {
			bTotal[FindSubArr(i, j, false)]++;
		}
	}

	LL count = 0; // 총 갯수
	for (auto it = aTotal.begin(); it != aTotal.end(); it++) { // a map 전체 탐색
		LL curB = T - ((*it).first); // 현재 B의 필요값 == T - A값
		if (bTotal.find(curB) != bTotal.end()) {
			count += ((*it).second) * (bTotal[curB]); // A 갯수 * B 갯수
		}
	}
	cout << count;
}