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
		if (A.find(iP) == A.end()) {
			FindAi(iP);
		}

		if (A.find(iQ) == A.end()) {
			FindAi(iQ);
		}

		A[i] = A[iP] + A[iQ];
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> P >> Q;
	FindAi(N);
	cout << A[N];
}