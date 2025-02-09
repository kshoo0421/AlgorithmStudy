#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> indegree(N + 1, 0), answer;
    vector<vector<int>> next(N + 1);
    while(M--) {
        int A, B;
        cin >> A >> B;
        indegree[B]++;
        next[A].push_back(B);
    }

    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(int i : next[cur]) {
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }
    for(int i : answer) cout << i << " ";
}