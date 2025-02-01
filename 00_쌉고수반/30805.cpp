#include <bits/stdc++.h>
#define VAL first
#define IDX second
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	cin >> M;
	vector<int> B(M);
	for (int& i : B) cin >> i;
	
	vector<pair<int, int>> answer;
	int aIdx = 0, bIdx = 0;
	for (; aIdx < N; aIdx++) {
		int curA = A[aIdx];
		int answerIdx = 0;
		for (; answerIdx < answer.size(); answerIdx++) {
			if (answer[answerIdx].VAL < curA) break;
		}
		bIdx = (answerIdx > 0) ? answer[answerIdx - 1].IDX + 1 : 0;
		for (; bIdx < M; bIdx++) {
			if (curA == B[bIdx]) {
				while (answer.size() > answerIdx) answer.pop_back();
				answer.push_back({ curA, bIdx });
				break;
			}
		}
	}

	cout << answer.size() << "\n";
	for (auto& pii : answer) cout << pii.VAL << " ";
}