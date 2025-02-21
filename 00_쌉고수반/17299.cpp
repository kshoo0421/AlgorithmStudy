#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N), cnt(1000001, 0), result(N, -1);
    stack<int> stk;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    
    for (int i = 0; i < N; i++) {
        while (!stk.empty() && cnt[A[stk.top()]] < cnt[A[i]]) {
            result[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}