#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, digit = 9, total = 0;
    map<char, int> weight;
    vector<pair<int, char>> weightV;
    cin >> N;    
    while(N--) {
        string word;
        cin >> word;
        for (int i = 0; i < word.size(); i++) { 
            char c = word[i];
            weight[c] += pow(10, word.size() - i - 1);
        }
    }

    for (auto mci : weight) weightV.push_back({ mci.second, mci.first });

    sort(weightV.rbegin(), weightV.rend());

    for(auto& pic : weightV) {
        total += (pic.first * digit--); 
    }
    cout << total;
}