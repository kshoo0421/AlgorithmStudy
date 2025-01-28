#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int N, cnt = 0, bMax = 0, wMax = 0;
vector<int> bDiff, bSum, bVal, wDiff, wSum, wVal;

void Bishop(bool isBlack, int idx, bool isActive) {
    if(isBlack) {
        int cDiff = bDiff[idx], cSum = bSum[idx];
        for(int i = 0; i < bSum.size(); i++) {
            if(cDiff == bDiff[i] || cSum == bSum[i]) {
                bVal[i] += isActive ? 1 : -1;
            }
        }
    }
    else {
        int cDiff = wDiff[idx], cSum = wSum[idx];
        for(int i = 0; i < wSum.size(); i++) {
            if(cDiff == wDiff[i] || cSum == wSum[i]) {
                wVal[i] += isActive ? 1 : -1;
            }
        }
    }
}

void BackTracking(bool isBlack, int idx, int cnt) {
    if(isBlack && bMax < cnt) bMax = cnt;
    else if(!isBlack && wMax < cnt) wMax = cnt;

    Bishop(isBlack, idx, true);
    int len = (isBlack) ? bVal.size() : wVal.size();
    for(int i = idx + 1; i < len; i++) {
        if(isBlack) {
            if(bVal[i] == 0) BackTracking(isBlack, i, cnt + 1);
        }
        else {
            if(wVal[i] == 0) BackTracking(isBlack, i, cnt + 1);
        }
    }
    Bishop(isBlack, idx, false);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if(input == 1) {
                if((i + j) % 2 == 1) {
                    bDiff.push_back(j - i);
                    bSum.push_back(j + i);
                    bVal.push_back(0);
                }
                else {
                    wDiff.push_back(j - i);
                    wSum.push_back(j + i);
                    wVal.push_back(0);
                }
            }
        }
    }
    for(int i = 0; i < bVal.size(); i++) BackTracking(true, i, 1);
    for(int i = 0; i < wVal.size(); i++) BackTracking(false, i, 1);
    cout << bMax + wMax;
}