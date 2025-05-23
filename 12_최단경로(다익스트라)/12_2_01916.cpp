/* [풀이]
-- 거리를 다른 배열로 분리한 풀이 --
1. 우선순위 큐를 사용해서, 방문하지 않은 노드 중 가장 거리가 적은 곳을 고른다.
2. 그 노드에서 다음 노드로 가는 경우의 수를 계산해본다.
값이 더 적다면 pq에 추가하고, 방문하지 않았음을 표시한다.
3. 방문한 칸은 패스하고, 아니면 계속 확인한다.
4. 정답을 출력한다.
*/
#include <bits/stdc++.h>
#define MAX 2000000000
using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<vector<pair<int, int>>> next(N + 1, vector<pair<int, int>>());
    for(int i = 0; i < M; i++) {
        int s, e, t; // start, end, time
        cin >> s >> e >> t;
        next[s].push_back({e, t});
    }
    int s, e;
    cin >> s >> e;
    vector<bool> isVisited(N + 1, false);
    vector<int> dist(N + 1, MAX);
    auto cmp = [&](int i1, int i2) { return dist[i1] < dist[i2]; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(s);
    dist[s] = 0;
    while(!pq.empty()) {
        int A = pq.top();
        pq.pop();
        if(isVisited[A]) continue;
        isVisited[A] = true;
        for(auto [B, time] : next[A]) {
            // (B까지의 거리) vs (A까지의 거리) + (A->B의 가중치)
            if(dist[B] > dist[A] + time) {
                dist[B] = dist[A] + time;
                // 값 업데이트이므로 다시 탐색 
                isVisited[B] = false;
                pq.push(B);
            }
        }
    }
    cout << dist[e];
}