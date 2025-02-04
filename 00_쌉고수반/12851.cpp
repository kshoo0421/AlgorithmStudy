#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, answer = -1, cnt = 0;
    cin >> N >> K;
    vector<int> memo(100001, -1);
    queue<int> q;
    if(N == K) {
        answer = 0;
        cnt = 1;
    }
    else {
        memo[N] = 0;
        q.push(N);
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(answer != -1 && answer <= memo[cur]) break;
        for(int i = 0; i < 3; i++) {
            int next;
            if(i == 0) next = cur - 1;
            else if(i == 1) next = cur + 1;
            else next = cur * 2;
            if(next < 0 || next > 100000) continue;

            if(next == K) {
                answer = memo[cur] + 1;
                cnt++;
            }
            else {
                if(memo[next] == -1 || (memo[next] == memo[cur] + 1)) {
                    memo[next] = memo[cur] + 1;
                    q.push(next);
                }
            }
        }
   }
    cout << answer << "\n" << cnt;    
}