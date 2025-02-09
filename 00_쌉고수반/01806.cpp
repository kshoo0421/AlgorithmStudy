#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    LL N, S;
    cin >> N >> S;
    vector<LL> A(N + 1), sum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
    }
    LL s = 0, e = 1, answer = N + 1;
    while(e <= N) {
        if(s == e) {
            e++;
            continue;
        }

        LL cur = sum[e] - sum[s];
        if(cur >= S) {
            answer = min(answer, e - s);
            s++;
        }
        else e++;        
    }
    if(answer == N + 1) answer = 0;
    cout << answer;
}