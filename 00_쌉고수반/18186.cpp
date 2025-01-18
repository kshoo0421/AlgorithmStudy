#include <bits/stdc++.h>
#define LL long long
using namespace std;

int N;

LL B, C, BC, B2C, total;
vector<int> A;

inline void Case1(int idx) {
    total += (B * A[idx]);
    A[idx] = 0;
}

inline void Case2(int idx, int val) {
    A[idx] -= val;
    A[idx + 1] -= val;
    total += (BC * val);
}

inline void Case3(int idx, int val) {
    A[idx] -= val;
    A[idx + 1] -= val;
    A[idx + 2] -= val;
    total += (B2C * val);
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> B >> C;
    A.resize(N);
    for(int& i : A) cin >> i;
    for(int i = 0; i < 2; i++) A.push_back(0);
    if(B <= C) {
        for(int i : A) total += (LL)i;
        total *= B;
        cout << total;
        return 0;
    }
    BC = B + C;
    B2C = B + 2 * C;

    for(int i = 0; i < N; i++) {
        if(A[i] == 0) continue;
        int l = A[i], m = A[i + 1], r = A[i + 2];
        
        if(l >= m) { // 2 or 3
            if(m >= r) {
                Case3(i, r);
                Case2(i, A[i + 1]);
                Case1(i);
            }
            else {
                Case3(i, m);
                Case1(i);
            }
        }
        else  {
            if(m > r) {
                Case2(i, min(m - r, l));
                Case3(i, A[i]);
            }
            else {
                Case3(i, l);
            }
        }
    }
    cout << total;
}