#include <bits/stdc++.h>
#define Y first
#define X second
#define LL long long
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;
    vector<pair<LL, LL>> points(N);

    for(auto& pii : points) cin >> pii.Y >> pii.X;

    LL sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum1 += points[i].Y * points[j].X;
        sum2 += points[i].X * points[j].Y;
    }

    double area = abs(sum1 - sum2) / 2.0;
    cout << fixed << setprecision(1) << area << "\n";
}