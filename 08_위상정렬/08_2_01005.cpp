/* [풀이]
1. 걸리는 시간(times), 진입에 필요한 갯수(indegree), 다음 노드(next)를 기록한다.
2. indegree가 0인 노드부터 차례로 q에 넣고, 하나씩 확인한다.
3. 다음 노드들의 indegree를 1씩 줄이고, 0이라면 큐에 넣는다.
4. 걸리는 시간은 max(현재의 시간 vs 앞 노드 시간 + 걸리는 시간)로
가장 오래 걸리는 시간을 찾는다.
*/
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