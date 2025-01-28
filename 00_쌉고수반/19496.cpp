#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    auto cmp = [](const string& s1, const string s2) {
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        return s1s2 < s2s1;
    };
    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
    while(N--) {
        string s;
        cin >> s;
        pq.push(s);
    }
    if(pq.top() == "0") cout << "0";
    else {
        while(!pq.empty()) {
            cout << pq.top();
            pq.pop();
        }
    }
}