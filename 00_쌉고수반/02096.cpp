#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> input(3), minDp(3), maxDp(3), tmp(3);
    for(int i = 0; i < 3; i++) {
        cin >> input[i];
        minDp[i] = input[i];
        maxDp[i] = input[i];
    }
    for(int i = 1; i < N; i++) {
        for(int& i : input) cin >> i;
        // min
        tmp[0] = input[0] + min(minDp[0], minDp[1]);
        tmp[1] = input[1] + *min_element(minDp.begin(), minDp.end());
        tmp[2] = input[2] + min(minDp[1], minDp[2]);
        minDp = tmp;

        tmp[0] = input[0] + max(maxDp[0], maxDp[1]);
        tmp[1] = input[1] + *max_element(maxDp.begin(), maxDp.end());
        tmp[2] = input[2] + max(maxDp[1], maxDp[2]);
        maxDp = tmp;
    }
    cout << *max_element(maxDp.begin(), maxDp.end()) << " ";
    cout << *min_element(minDp.begin(), minDp.end());
}