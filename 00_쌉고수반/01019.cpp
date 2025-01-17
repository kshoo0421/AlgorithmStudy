#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string N;
    cin >> N;
    
    vector<LL> cnt(10, 0);

    for(int i = 0; i < N.size(); i++) {
        string leftString = string(N.begin(), N.begin() + i);
        string rightString = string(N.begin() + i + 1, N.end());
        
        int left = (leftString.empty()) ? 0 : stoi(leftString);
        int cur = N[i] - '0';
        int right = (rightString.empty()) ? 0 : stoi(rightString);

        if(left != 0) { 
            if(cur == 0) cnt[0] += (right + 1) + ((left - 1) * pow(10, rightString.size()));
            else cnt[0] += (left * pow(10, rightString.size()));
        }

        for(int i = 1; i <= 9; i++) {
            cnt[i] += left * pow(10, rightString.size());
            if(i < cur) cnt[i] += pow(10, rightString.size());            
            if(i == cur) cnt[i] += (right + 1);
        }
    }

   for(LL ll : cnt) cout << ll << " ";
    cout << "\n";
}