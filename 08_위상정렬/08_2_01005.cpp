#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T, N, K, X, Y, W;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        vector<int> D(N, 0), times(N, 0), indegree(N, 0);
        vector<vector<int>> next(N, vector<int>());
        for(int& i : D) cin >> i;
        while(K--) {
            cin >> X >> Y;
            X--, Y--;
            indegree[Y]++;
            next[X].push_back(Y);
        }
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                times[i] = D[i];
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int i : next[cur]) {
                indegree[i]--;
                times[i] = max(times[i], times[cur] + D[i]);
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        cin >> W;
        cout << times[W - 1] << "\n";
    }
}