#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    
    vector<int> height(N);
    set<int> si;
    
    int input;
    cin >> input;
    height[input] = 1;
    si.insert(input);

    long long answer = 1; // 초기값
    for(int i = 1; i < N; i++) {
        cin >> input;
        auto low = si.lower_bound(input);

        if(low == si.end()) { // input이 최댓값
            low--;
            height[input] = height[*low] + 1;
        }
        else if(low == si.begin()) { // input이 최솟값
            height[input] = height[*low] + 1;
        }
        else { // 중간값
            int r = *low;
            low--;
            int l = *low;
            height[input] = max(height[l], height[r]) + 1;
        }
        answer += (long long)height[input];
        si.insert(input);
    }
    cout << answer;
}