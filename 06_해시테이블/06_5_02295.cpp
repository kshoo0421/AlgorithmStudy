/* [풀이]
1. 두 수의 합을 저장하고, 두 수의 차이를 계산하여 탐색한다.
a + b + c = d => a + b = d - c
2. 이분탐색을 이용하여 탐색하는데,
이를 위해 입력값과 두 수의 합을 저장한다.
3. 값이 있다면, 최대값을 업데이트한다.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> U(N);
    for(int& i : U) cin >> i;
    sort(U.begin(), U.end());
    
    vector<int> sumOfTwo;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sumOfTwo.push_back(U[i] + U[j]);
        }
    }
    sort(sumOfTwo.begin(), sumOfTwo.end());

    int answer = INT_MIN;
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            int goal = U[i] - U[j];
            if(binary_search(sumOfTwo.begin(), sumOfTwo.end(), goal)) {
                answer = max(answer, U[i]);
            }
        }
    }
    cout << answer;
}