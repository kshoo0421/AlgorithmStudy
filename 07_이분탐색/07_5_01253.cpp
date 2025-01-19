/* [풀이]
1. 입력값을 정렬한다.
2. 기준값을 잡고, 투포인터로 다른 두 값을 찾는다.
3. 두 값의 합이 현재 값보다 크다면 r을 줄여 값을 줄이고
작다면 l을 늘려 값을 늘린다.
4. l이 r보다 크거나 같다면 탐색을 종료한다.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	int cnt = 0;
	sort(A.begin(), A.end()); // 정렬
	for (int i = N - 1; i >= 0; i--) { // 타겟
		int l = 0, r = N - 1;
		while (l < r) {
			if (r == i) { // 같다면 다음 값으로
				r--;
				continue;
			}
			if (l == i) {
				l++;
				continue;
			}
			int sum = A[l] + A[r];
			if (sum == A[i]) { // 발견
				cnt++;
				break;
			}
			if (sum < A[i]) l++; // 값 조정
			else r--; // 값 조정
		}
	}
	cout << cnt;
}