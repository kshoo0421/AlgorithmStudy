#include <bits/stdc++.h>
#define LL long long
using namespace std;

int N;
LL C = 0;
vector<int> height;
set<int> si;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    height.resize(N + 1);
    int input;
    cin >> input;
    height[input] = 0;
    si.insert(input);

    cout << "0\n";
    for(int i = 1; i < N; i++) {
        cin >> input;
        auto it = si.lower_bound(input);
        if(it == si.end()) {
            it--;
            height[input] = height[*it] + 1;
        }
        else if(it == si.begin()) {
            height[input] = height[*it] + 1;
        }
        else {
            int r = height[*it];
            it--;
            int l = height[*it];
            height[input] = max(r, l) + 1;
        }
        si.insert(input);
        C += (LL)height[input];
        cout << C << "\n";
    }
}