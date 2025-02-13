#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    LL N, mins = 1e11;
    cin >> N;
    vector<LL> A(N);
    vector<int> answer(3);
    for(LL& ll : A) cin >> ll;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
        int s = i + 1, e = N - 1;
        while(s < e) {
            LL sum = A[i] + A[s] + A[e];
            if(abs(mins) > abs(sum)) {
                mins = sum;
                answer = { i, s, e };
            }
            if(sum < 0) s++;
            else e--;
        }
    }
    for(int i : answer) cout << A[i] << " ";
}