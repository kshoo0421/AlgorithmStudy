/* [풀이]
1. 3가지 케이스를 비교한다.
1) 위/아래 버튼만 누른다.(100보다 크면 위, 아니면 아래)
2) 원하는 것보다 큰 숫자를 누르고, 아래 버튼만 누른다.
3) 원하는 것보다 작은 숫자를 누르고, 위 버튼만 누른다.
2. 숫자 버튼으로 누를 수 있는지 확인하는 함수를 만들어
한 칸 한 칸 올렸을/내렸을 때 그 숫자를 만들 수 있는지 확인한다.
3. 모든 케이스를 비교해 가장 적은 횟수를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
bool btnErr[10];

// 버튼으로 바로 누를 수 있는지 확인
bool IsNumPossible(int n) {
	if (n < 10) return !btnErr[n]; // 1자리수면 버튼 고장났는지 반환
	while (n) { // 각 자릿수 확인
		// 고장난 버튼 있으면 불가
		if (btnErr[n % 10]) return false;
		n /= 10;
	}
	return true; // 없으면 버튼으로 이동 가능
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	bool errDone = false;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) { 
		int input;
		cin >> input;
		btnErr[input] = true; // 고장 체크
	}
	
	if (M == 10 || (M == 9 && btnErr[0] == false)) { // 모두 고장나거나 0만 멀쩡하면 ( +, - )로만 움직여야함.
		cout << abs(N - 100);
		return 0;
	}

	int up = N, down = N;
	
	while (!IsNumPossible(up)) up++; // 한 채널씩 올려봄
	while (!IsNumPossible(down)) down--; // 버튼 사용 가능할 때까지 내림

	int a1 = abs(up - N); // 기본 횟수 : 목표치와 up의 차이
	int tmp = up;
	if (up == 0) a1++; // 
	while (tmp)	tmp /= 10, a1++; // 숫자 버튼 누르는 횟수 추가

	if (down < 0) down = 100; // 나올 수 없는 값이면 기본값
	int a2 = abs(N - down); // N과 down의 차이
	tmp = down;
	if (down == 0) a2++;
	while (tmp)	tmp /= 10, a2++;  // 버튼 누르는 횟수

	cout << min(min(a1, a2), abs(N - 100));
}