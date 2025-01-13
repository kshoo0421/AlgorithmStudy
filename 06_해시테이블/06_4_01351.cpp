/* [풀이]
1. 재귀 형식으로 필요한 A[i]만 생성
2. map으로 해당 인덱스의 값이 있는지 확인
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL N, P, Q;
map<LL, LL> A;

void FindAi(LL i) {
	if (i == 0) A[0] = 1;
	else {
		LL iP = i / P;
		LL iQ = i / Q;
		if (A.find(iP) == A.end()) { // A[i/P]가 없다면
			FindAi(iP);	// 재귀로 찾기
		}

		if (A.find(iQ) == A.end()) { // A[i/Q]가 없다면
			FindAi(iQ);	// 재귀로 찾기
		}

		A[i] = A[iP] + A[iQ]; // 합쳐서 구하기
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> P >> Q;
	FindAi(N);
	cout << A[N];
}