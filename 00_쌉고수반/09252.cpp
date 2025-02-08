#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int size1 = s1.size(), size2 = s2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for(int i = 1; i <= size1; i++) {
        for(int j = 1; j <= size2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][i - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int i = size1, j = size2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) { 
            lcs += s1[i - 1];
            i--, j--;
        } 
        else if (dp[i - 1][j] >= dp[i][j - 1]) i--;
        else j--; 
    }
    
    cout << lcs.size() << "\n";
    for(int i = lcs.size() - 1; i >= 0; i--) cout << lcs[i];
}