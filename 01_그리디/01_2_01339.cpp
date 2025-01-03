#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, digit = 9, total = 0;
    map<char, int> weight;
    vector<pair<int, char>> weightV;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        for (int j = 0; j < words[i].size(); ++j) {
            char c = words[i][j];
            weight[c] += pow(10, words[i].size() - j - 1);
        }
    }
    for (auto vpic : weight) weightV.push_back({ vpic.second, vpic.first });
    sort(weightV.rbegin(), weightV.rend());
    for (auto vpic : weightV) weight[vpic.second] = digit--;
    for (string& s : words) for (char& c : s) c = weight[c] + '0';
    for (string s : words) total += stoi(s);
    cout << total;
}