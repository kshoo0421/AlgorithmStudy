#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string input, bomb;
    cin >> input >> bomb;
    int bSize = bomb.size();
    string answer = "";
    for(char c : input) {
        stack<char> stk;
        answer += c;
        while(answer.size() >= bSize) {
            bool isBreak = false;
            for(int i = bSize - 1; i >= 0; i--) {
                if(answer.back() == bomb[i]) {
                    stk.push(answer.back());
                    answer.pop_back();
                }
                else {
                    while(!stk.empty()) {
                        answer += stk.top();
                        stk.pop();
                    }
                    isBreak = true;
                    break;
                }
            }
            while(!stk.empty()) stk.pop();
            if(isBreak) break;
        }
    }
    if(answer.size() == 0) cout << "FRULA";
    else cout << answer;
}