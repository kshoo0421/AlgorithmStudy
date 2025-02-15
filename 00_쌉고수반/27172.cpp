#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

vector<int> cnt(MAX, 0), score(MAX, 0);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> card(N);
    
    for (int i = 0; i < N; i++) {
        cin >> card[i];
        cnt[card[i]]++;
    }

    for (int i = 1; i < MAX; i++) {
        if (cnt[i] == 0) continue; 

        for (int j = 2 * i; j < MAX; j += i) {
            if (cnt[j] > 0) {
                score[i] += cnt[j];
                score[j] -= cnt[i];
            }
        }
    }

    for (int i = 0; i < N; i++) cout << score[card[i]] << " ";
}
