#include <bits/stdc++.h>
#define LL long long
using namespace std;

int N;
vector<LL> height;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    height.assign(N, 0);
    for(LL& ll : height) cin >> ll;
    reverse(height.begin(), height.end());

    LL total = 0;
    stack<LL> stk;
    for(int i = 0; i < N; i++) {
        while((!stk.empty()) && (height[i] > height[stk.top()])) stk.pop();

        if(stk.empty()) total += i;
        else {
            total += (i - stk.top() - 1);
            while((!stk.empty()) && (height[stk.top()] == height[i])) stk.pop();
        }
        stk.push(i);
    }
    cout << total;
}