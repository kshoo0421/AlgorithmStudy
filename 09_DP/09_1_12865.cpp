#include <bits/stdc++.h>
#define W first
#define V second
using namespace std;

int memo[101][100001];
int N, K;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	vector<pair<int, int>> inputs(N);
	for (auto& pii : inputs) cin >> pii.W >> pii.V;
	for (int sum = 1; sum <= K; sum++) {
		for (int i = 0; i < N; i++) { 
			if (inputs[i].W <= sum) {
				memo[i + 1][sum] = max(memo[i][sum], memo[i][sum - inputs[i].W] + inputs[i].V);
			}
			else memo[i + 1][sum] = memo[i][sum];
		}
	}
	cout << memo[N][K];
	return 0;
}