/* [풀이]
1. 현재 무게에서 가능한 물건의 가치를 기록한다.
물건은 하나씩 넣어보며, 무게가 감당 가능할 때 넣는다.
2. 무게를 하나씩 늘려보며, dp를 작성한다.
*/
#include <bits/stdc++.h>
#define W first // 무게
#define V second // 가치
using namespace std;

int memo[101][100001];
int N, K; // 물품의 수, 버틸 수 있는 무게

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	vector<pair<int, int>> inputs(N);
	for (auto& pii : inputs) cin >> pii.W >> pii.V;
	for (int sum = 1; sum <= K; sum++) { // 무게합이 1~K
		for (int i = 0; i < N; i++) { // 
			if (inputs[i].W <= sum) {// 물건의 무게가 현재 가능 무게보다 적다면
				// 현재 가치 = max(이전 물건까지의 가치, (현재 무게 - 물건 무게)의 가치 + 물건 가치)
				memo[i + 1][sum] = max(memo[i][sum], memo[i][sum - inputs[i].W] + inputs[i].V);
			}
			else memo[i + 1][sum] = memo[i][sum]; // 아니면 이전 값 그대로
		}
	}
	cout << memo[N][K];
	return 0;
}