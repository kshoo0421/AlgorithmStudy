/* [풀이]
1. 오름차순으로 정렬한다.
2. 일반적인 이분탐색에서 mid 대신 abs(arr[l] + arr[r])을 사용한다.
3. 최적의 값을 bestR, bestL에 기록한다.
*/

#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
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