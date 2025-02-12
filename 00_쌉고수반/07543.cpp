#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    LL N;
    cin >> N;
    vector<LL> A(N), B(N), C(N), D(N);
    for(LL i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<LL> AB(N * N), CD(N * N);
    for(LL i = 0; i < N; i++) {
        for(LL j = 0; j < N; j++) {
            LL idx = i * N + j;
            LL ab = A[i] + B[j], cd = C[i] + D[j];
            AB[idx] = ab;
            CD[idx] = cd;
        }
    }
    LL size = N * N;
    sort(AB.begin(), AB.end());
    sort(CD.rbegin(), CD.rend());
    LL answer = 0, idx1 = 0, idx2 = 0;
    while(idx1 < size && idx2 < size) {
        LL sum = AB[idx1] + CD[idx2];
        if(sum == 0) {
            LL cnt1 = 1, cnt2 = 1;
            while(idx1 + cnt1 < size && AB[idx1] == AB[idx1 + cnt1]) {
                cnt1++;
            }
            while(idx2 + cnt2 < size && CD[idx2] == CD[idx2 + cnt2]) {
                cnt2++;
            }
            answer += (cnt1 * cnt2);
            idx1 += cnt1;
            idx2 += cnt2; 

        }
        else if(sum < 0) idx1++;
        else idx2++;
    }
    cout << answer;
}