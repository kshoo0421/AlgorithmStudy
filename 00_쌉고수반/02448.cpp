#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> grid;

void FillGrid(int y, int x, int cnt) {
    if(cnt == 3) {
        grid[y][x] = '*';
        grid[y + 1][x - 1] = '*';
        grid[y + 1][x + 1] = '*';
        for(int i = x - 2; i <= x + 2; i++) {
            grid[y + 2][i] = '*';
        }
        return;
    }
    FillGrid(y, x, cnt / 2);
    FillGrid(y + (cnt / 2), x - (cnt / 2), cnt / 2);
    FillGrid(y + (cnt / 2), x + (cnt / 2), cnt / 2);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    grid.assign(N, vector<char>(2 * N + 1, ' '));
    FillGrid(0, N - 1, N);
    for(auto& vc : grid) {
        for(char& c : vc) cout << c;
        cout << "\n";
    }
}