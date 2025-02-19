#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    vector<LL> modCnt(M, 0);
    LL prefixSum = 0, result = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        prefixSum += A[i];  
        int mod = prefixSum % M;

        if (mod == 0) result++;
        modCnt[mod]++; 
    }

    for (int i = 0; i < M; i++) {
        if (modCnt[i] > 1) {
            result += (modCnt[i] * (modCnt[i] - 1)) / 2;
        }
    }
    cout << result;
}
