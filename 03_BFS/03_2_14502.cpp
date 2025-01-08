/* [풀이]
1. 모든 공간을 입력받고, 빈 공간을 저장한다(room).
2. 이 공간 중 3개를 골라 벽을 세운다.
벽은 백트래킹을 이용해 모든 경우의 수를 탐색한다.
3. 벽 3개가 세워졌다면 BFS로 바이러스를 퍼뜨린다.
그 이후, 안전한 공간의 갯수를 센다.
4.  그 갯수의 최대치를 출력한다.
*/
#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int N, M;
int safeArea, maxSafeArea = 0;
vector<vector<int>> lab, tmpLab;
vector<pair<int, int>> room, viruses;
queue<pair<int, int>> q;

void BFS() {
    tmpLab = lab; // 현재 연구실 상황을 복사
    for (auto& virus : viruses) q.push(virus); // 바이러스 모두 큐에 넣기

    while (!q.empty()) { // BFS 실행
        int cy = q.front().Y;
        int cx = q.front().X;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // 공간 밖 pass
            if(tmpLab[ny][nx] != 0) continue; // 빈 공간 아니라면 pass
            tmpLab[ny][nx] = 2; // 바이러스 확장
            q.push({ny, nx}); // 큐에 추가
        }
    }

    // 0 갯수 확인
    safeArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmpLab[i][j] == 0) safeArea++;
        }
    }
    // 지금까지 나온 max와 비교
    maxSafeArea = max(maxSafeArea, safeArea);
}

// 백트래킹으로 모든 빈 공간 중 3개 선점
void SetWalls(int count, int start) { 
    if (count == 3) { // 벽 3개를 세웠다면 BFS 실행
        BFS();
        return;
    }

    // 처음부터 끝까지 중 3개 선점.
    for (int i = start; i < room.size(); i++) {
        int cy = room[i].Y;
        int cx = room[i].X;
        lab[cy][cx] = 1; // 임시 벽 생성
        SetWalls(count + 1, i + 1);
        lab[cy][cx] = 0; // 임시 벽 제거
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    lab.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) room.push_back({ i, j });
            else if (lab[i][j] == 2) viruses.push_back({ i, j });
        }
    }
    SetWalls(0, 0);
    cout << maxSafeArea << "\n";
    return 0;
}