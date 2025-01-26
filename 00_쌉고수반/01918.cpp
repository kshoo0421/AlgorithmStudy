#include <bits/stdc++.h>
using namespace std;

string input;

string CalBracket(int& idx) {
    string result = "";
    idx++;
    if(input[idx] == '(') result += CalBracket(idx);
    else result += input[idx];
    idx++;

    stack<char> oper;
    for(int i = idx; i < input.size(); i++) {
        if(input[i] == ')') {
            idx = i;
            break;
        }
        switch(input[i]) {
            case '+':
            case '-':
                while(!oper.empty()) {
                    result += oper.top();
                    oper.pop();
                }
                oper.push(input[i++]);
                if(input[i] == '(') result += CalBracket(i);
                else result += input[i];
                break;
            case '*':
            case '/':
                char cur = input[i++];
                if(input[i] == '(') result += CalBracket(i);
                else result += input[i];         
                result += cur;
                break;
        }
    }
    while(!oper.empty()) {
        result += oper.top();
        oper.pop();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> input;
    int idx = -1;
    cout << CalBracket(idx);
}