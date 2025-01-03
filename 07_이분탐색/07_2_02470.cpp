#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, min, max, near0 = INT_MAX, bestLeft, bestRight, left;
	cin >> n;
	vector<int> arr(n);
	for (int& i : arr) cin >> i;
	sort(arr.begin(), arr.end());
    bestLeft = 0, bestRight = 1;

    for (int i = 0; i < n - 1; i++) {
        left = arr[i];
        auto it = lower_bound(arr.begin() + i + 1, arr.end(), -left);

        if (it != arr.end() && abs(left + *it) < abs(near0)) {
            near0 = left + *it;
            bestLeft = left;
            bestRight = *it;
        }
        if (it != arr.begin() + i + 1) {
            it--;
            if (abs(left + *it) < abs(near0)) {
                near0 = left + *it;
                bestLeft = left;
                bestRight = *it;
            }
        }
    }
    if (bestLeft > bestRight) swap(bestLeft, bestRight);
    cout << bestLeft << " " << bestRight;
}