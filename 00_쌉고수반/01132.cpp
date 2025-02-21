#include <bits/stdc++.h>
#define LL long long
#define VAL first
#define IDX second
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<bool> isFirst(10, false);
    vector<string> A(N, "");
    vector<pair<LL, LL>> alphabet(10, make_pair(0, 0));
    for(LL i = 0; i < 10; i++) alphabet[i].IDX = i;
    for(auto& s : A) {
        cin >> s;
        LL idx = 1;
        isFirst[s.front() - 'A'] = true;
        stack<char> stk;
        for(char c : s) stk.push(c);
        while(!stk.empty()) {
            char c = stk.top();
            alphabet[c - 'A'].VAL += idx;
            stk.pop();
            idx *= 10;
        }
    }
    sort(alphabet.begin(), alphabet.end(), [&](auto& pii1, auto& pii2) {
        if(isFirst[pii1.IDX] != isFirst[pii2.IDX]) return !isFirst[pii1.IDX]; 
        return pii1.VAL < pii2.VAL;
    });

    sort(alphabet.begin() + 1, alphabet.end(), [](auto& pii1, auto& pii2) {
        return pii1.VAL < pii2.VAL;
    });

    LL answer = 0;
    for(LL i = 1; i < 10; i++) {
        answer += (LL)(i * alphabet[i].VAL);
    }
    cout << answer;
}