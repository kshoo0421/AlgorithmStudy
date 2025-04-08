#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i : arr) cin >> i;
    sort(arr.begin(), arr.end());

    int l = 0, r = N - 1;
    int bestL = 0, bestR = N - 1;
    while (l < r) {
        if (abs(arr[l] + arr[r]) < abs(arr[bestL] + arr[bestR])) {
            bestL = l;
            bestR = r;
        }
        if (arr[l] + arr[r] == 0) break;
        else if (arr[l] + arr[r] < 0) l++;
        else r--;
    }
    cout << arr[bestL] << " " << arr[bestR];
}