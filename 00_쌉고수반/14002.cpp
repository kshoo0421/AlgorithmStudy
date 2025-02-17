#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int len;
vector<int> A, mins, answer;
vector<vector<int>> dp;

bool FillAnswer(int idx) {
    int next = idx + 1; 
    if(idx == 0) {
        if(idx < len - 1) {
            for(int i : dp[0]) {
                if(i < answer[next] && A[i] < A[answer[next]]) {
                    answer[idx] = i;
                    return true;
                }
            }
        }
        else {
            answer[idx] = dp[0][0];
            return true;
        }   
    }
    else {
        if(idx < len - 1) {
            for(int i : dp[idx]) {
                if(i < answer[next] && A[i] < A[answer[next]]) {
                    answer[idx] = i;
                    if(FillAnswer(idx - 1)) return true;
                }
            }
        }
        else {
            for(int i : dp[idx]) {
                answer[idx] = i;
                if(FillAnswer(idx - 1)) return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    A.resize(N);
    cin >> A[0];
    mins.push_back(A[0]);
    dp.push_back(vector<int>(1, 0));
    for(int i = 1; i < N; i++) {
        cin >> A[i];
        auto it = lower_bound(mins.begin(), mins.end(), A[i]);
        if(it == mins.end()) {
            mins.push_back(A[i]);
            dp.push_back(vector<int>(1, i));
        }
        else {
            int idx = it - mins.begin();
            mins[idx] = A[i];
            dp[idx].push_back(i);
        }
    }
    len = mins.size();
    answer.assign(len, dp.back().back());
    FillAnswer(len - 1);
    cout << len << "\n";
    for(int i : answer) cout << A[i] << " ";
}