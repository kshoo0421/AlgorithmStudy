/* [풀이]
1. 해당 숫자를 만들 수 있는 경우의 수를 기록한다.
2. 동전 A를 사용해서 만들 수 있는 경우의 수는
이전까지의 경우의 수 + 현재의 경우의 수
3. 최종 결과를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, K; 
	cin >> N >> K;
	vector<int> input(N), tmp(K + 1);
	vector<vector<int>> dp(2, vector<int>(K + 1));
	for (int& i : input) cin >> i;
	for (int i = 0; i < N; i++)	{
		if (i % 2 == 0) dp[0] = tmp;
		else dp[1] = tmp;

		for (int j = 0; j <= K; j++) {
			if (i == 0) {
				if (j % input[i] == 0) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			else {
				if (i % 2 == 0) {
					for (int k = j; k >= 0; k -= input[i]) dp[0][j] += dp[1][k];
				}
				else {
					for (int k = j; k >= 0; k -= input[i]) dp[1][j] += dp[0][k];
				}
			}
		}
	}
	cout << dp[N % 2 ? 0 : 1][K];
}