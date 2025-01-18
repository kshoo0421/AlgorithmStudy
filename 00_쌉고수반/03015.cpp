#include <bits/stdc++.h>
#define VAL first
#define CNT second
#define LL long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    
    LL answer = 0;
    stack<pair<LL, LL>> stk;
    while(N--) {
        LL input;
        cin >> input;
        while(!stk.empty() && stk.top().VAL < input) {
            LL cnt = stk.top().CNT;
            if(stk.size() != 1) answer += cnt; // 왼쪽
            answer += cnt; // 오른쪽
            answer += ((cnt) * (cnt - 1)) / 2; // 같은 수 (cnt)C(2)
            stk.pop();
        }
        if(!stk.empty() && stk.top().VAL == input) stk.top().CNT++;
        else stk.push({input, 1});
    }

    while(!stk.empty()) { // 나머지
        LL cnt = stk.top().CNT;
        if(stk.size() != 1) answer += cnt; // 왼쪽
        answer += ((cnt) * (cnt - 1)) / 2; // 같은 수
        stk.pop();
    }
    cout << answer;
}