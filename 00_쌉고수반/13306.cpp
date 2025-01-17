#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> parent, topNode, ranks;

int Find(int x) {
    if(topNode[x] != x) {
        topNode[x] = Find(topNode[x]);
    }
    return topNode[x];
}

void SetUnion(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX != rootY) {
        if (ranks[rootX] < ranks[rootY]) {
            swap(rootX, rootY);
        }
        topNode[rootY] = rootX;
        if (ranks[rootX] == ranks[rootY]) {
            ranks[rootX]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    
    parent.assign(N + 1, 1);
    topNode.assign(N + 1, 1);
    ranks.assign(N + 1, 0);

    for(int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        parent[i] = a;
        topNode[i] = a;
    }

    vector<pair<int, vector<int>>> commands;
    for(int i = 0; i < (N - 1) + Q; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            int b;
            cin >> b;
            topNode[b] = b; // 일단 끊기
            commands.push_back({x, {b}});
        }
        else {
            int c, d;
            cin >> c >> d;
            commands.push_back({x, {c, d}});
        }
    }

    // Union 업데이트
    for(int i = 2; i <= N; i++) {
        if(topNode[i] != i) {
            SetUnion(i, topNode[i]);
        }
    }

    vector<string> answers;

    while(!commands.empty()) {
        auto curCommand = commands.back();
        commands.pop_back();
        if(curCommand.first == 0) {
            int b = curCommand.second[0];
            SetUnion(b, parent[b]);
        }
        else {
            int c = curCommand.second[0], d = curCommand.second[1];
            if(Find(c) == Find(d)) answers.push_back("YES");
            else answers.push_back("NO");
        }
    }
    while(!answers.empty()) {
        cout << answers.back() << "\n";
        answers.pop_back();
    }
}