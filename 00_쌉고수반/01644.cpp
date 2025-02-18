#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for(int i = 2; i <= N; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * 2; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
    int answer = 0;
    for(int i = 2; i <= N; i++) {
        if(!isPrime[i]) continue;
        int sum = 0;
        for(int j = i; j <= N; j++) {
            if(!isPrime[j]) continue;
            sum += j;
            if(sum >= N) {
                if(sum == N) answer++;
                break;
            }
        }
    }
    cout << answer;
}